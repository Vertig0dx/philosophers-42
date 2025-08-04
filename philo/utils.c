/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:21:48 by lmiguel-          #+#    #+#             */
/*   Updated: 2024/06/03 16:39:03 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(const char *str)
{
	int		i;
	long	result;
	long	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - 48;
		str++;
		i++;
		if (*str != '\0' && (*str < '0' || *str > '9'))
			return (-1);
	}
	if (i > 18)
		return (-1);
	return (sign * result);
}

void	print_states(t_philo *philo, int print_num)
{
	int	n;

	n = 0;
	pthread_mutex_lock(&philo->table->print_lock);
	if (philo->death == true)
	{
		pthread_mutex_unlock(&philo->table->print_lock);
		return ;
	}
	get_current_time(philo, 0);
	pthread_mutex_lock(&philo->time_lock);
	if (print_num == 0)
		printf ("%ld %d has taken a fork\n", 
			philo->current_time_ms, philo->seat_num + 1);
	if (print_num == 1)
		printf ("%ld %d is eating\n", 
			philo->current_time_ms, philo->seat_num + 1);
	if (print_num == 2)
		printf ("%ld %d is sleeping\n", 
			philo->current_time_ms, philo->seat_num + 1);
	if (print_num == 3)
		printf ("%ld %d is thinking\n", 
			philo->current_time_ms, philo->seat_num + 1);
	pthread_mutex_unlock(&philo->time_lock);
	pthread_mutex_unlock(&philo->table->print_lock);
}

void	get_current_time(t_philo *philo, int update)
{
	struct timeval	tv;

	pthread_mutex_lock(&philo->time_lock);
	gettimeofday(&tv, NULL);
	philo->current_time_ms = ((tv.tv_sec * 1000) + 
			(tv.tv_usec / 1000)) - philo->time_start_ms;
	if (update == 1)
		philo->latest_meal = philo->current_time_ms;
	if (update == 2)
		philo->time_spent_sleeping = philo->current_time_ms;
	pthread_mutex_unlock(&philo->time_lock);
}

int	routine_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_lock);
	if (philo->exited == true)
	{
		if (philo->exit_check == false)
		{
			philo->table->exit_num++;
			philo->exit_check = true;
		}
		pthread_mutex_unlock(&philo->philo_lock);
		return (0);
	}
	get_current_time(philo, 0);
	pthread_mutex_lock(&philo->time_lock);
	if ((philo->current_time_ms - philo->latest_meal) >= philo->time_to_die)
	{
		pthread_mutex_unlock(&philo->time_lock);
		pthread_mutex_unlock(&philo->philo_lock);
		return (-1);
	}
	pthread_mutex_unlock(&philo->time_lock);
	pthread_mutex_unlock(&philo->philo_lock);
	return (0);
}

void	clean_and_destroy(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_num)
	{
		if (pthread_join(table->philo[i].thread_id, NULL) != 0)
			break ;
		i++;
	}
	i = 0;
	while (i < table->philo_num)
	{
		if (pthread_mutex_destroy(&table->fork[i]) != 0
			|| pthread_mutex_destroy(&table->philo[i].philo_lock) != 0 
			|| pthread_mutex_destroy(&table->philo[i].time_lock) != 0)
			break ;
		i++;
	}
	if (pthread_mutex_destroy(&table->table_lock) != 0
		|| pthread_mutex_destroy(&table->print_lock) != 0)
		return ;
	free(table->philo);
	free(table->fork);
}
