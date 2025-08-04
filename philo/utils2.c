/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:47:43 by lmiguel-          #+#    #+#             */
/*   Updated: 2024/06/03 16:29:02 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_lock(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_lock);
	get_current_time(philo, 0);
	pthread_mutex_unlock(&philo->philo_lock);
	if (philo->seat_num % 2 == 0)
	{
		if (philo->seat_num == 0)
			pthread_mutex_lock(&philo->table->fork[philo->philo_num - 1]);
		else
			pthread_mutex_lock(&philo->table->fork[philo->seat_num - 1]);
		print_states(philo, 0);
		pthread_mutex_lock(&philo->table->fork[philo->seat_num]);
		print_states(philo, 0);
	}
	else
	{
		pthread_mutex_lock(&philo->table->fork[philo->seat_num]);
		print_states(philo, 0);
		pthread_mutex_lock(&philo->table->fork[philo->seat_num - 1]);
		print_states(philo, 0);
	}
}

void	fork_unlock(t_philo *philo)
{
	if (philo->seat_num % 2 == 0)
	{
		pthread_mutex_unlock(&philo->table->fork[philo->seat_num]);
		if (philo->seat_num == 0)
			pthread_mutex_unlock(&philo->table->fork[philo->philo_num - 1]);
		else
			pthread_mutex_unlock(&philo->table->fork[philo->seat_num - 1]);
	}
	else
	{
		pthread_mutex_unlock(&philo->table->fork[philo->seat_num - 1]);
		pthread_mutex_unlock(&philo->table->fork[philo->seat_num]);
	}
}

void	death_march(t_table *table, int n)
{
	pthread_mutex_lock(&table->print_lock);
	if (n > -1)
		printf ("%ld %d died\n", table->philo[n].current_time_ms, 
			(table->philo[n].seat_num) + 1);
	n = 0;
	while (n < table->philo_num)
	{
		pthread_mutex_lock(&table->philo[n].philo_lock);
		table->philo[n].death = true;
		pthread_mutex_unlock(&table->philo[n].philo_lock);
		n++;
	}
	pthread_mutex_unlock(&table->print_lock);
}

int	all_creation(int argc, char **argv, t_table *table)
{
	if (table_setup(argc, argv, table) == -1)
		return (-1);
	if (mutex_create(table) == -1)
		return (-1);
	if (thread_create(table) == -1)
		return (-1);
	return (0);
}

void	pseudo_philo_init(t_table *table)
{
	int	n;

	n = 0;
	while (n < table->philo_num)
	{
		table->philo[n].times_have_eaten = 0;
		table->philo[n].exited = false;
		table->philo[n].exit_check = false;
		n++;
	}
	return ;
}
