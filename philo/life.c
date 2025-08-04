/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:03:28 by lmiguel-          #+#    #+#             */
/*   Updated: 2024/06/03 16:20:28 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	certain_death(t_philo *philo)
{
	print_states(philo, 0);
	pthread_mutex_lock(&philo->philo_lock);
	better_usleep(philo->time_to_die, philo);
	printf("%ld %d died\n", philo->current_time_ms, philo->seat_num + 1);
	pthread_mutex_unlock(&philo->philo_lock);
	return ;
}

void	anti_deadlock(t_philo *philo)
{
	if (philo->seat_num % 2 != 0)
		usleep(500);
	else if (philo->seat_num == philo->philo_num - 1 
		&& philo->philo_num % 2 != 0)
		pseudo_sleep(philo, (philo->time_to_eat + 5));
}

void	pseudo_sleep(t_philo *philo, long time)
{
	pthread_mutex_lock(&philo->philo_lock);
	while (philo->current_time_ms < time)
	{
		usleep(100);
		get_current_time(philo, 0);
	}
	pthread_mutex_unlock(&philo->philo_lock);
}

void	*life(void *phill)
{
	t_philo	*philo;

	philo = (t_philo *)phill;
	pthread_mutex_lock(&philo->table->table_lock);
	philo->time_start_ms = philo->table->time_start_ms;
	get_current_time(philo, 0);
	philo->latest_meal = philo->time_start_ms;
	pthread_mutex_unlock(&philo->table->table_lock);
	if (philo->philo_num == 1)
		certain_death(philo);
	else
	{
		anti_deadlock(philo);
		philo_eat(philo);
	}
	return (NULL);
}
