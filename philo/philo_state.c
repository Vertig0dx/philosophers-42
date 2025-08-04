/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:52:08 by lmiguel-          #+#    #+#             */
/*   Updated: 2024/06/03 16:38:09 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	fork_lock(philo);
	pthread_mutex_lock(&philo->philo_lock);
	get_current_time(philo, 1);
	pthread_mutex_unlock(&philo->philo_lock);
	print_states(philo, 1);
	pthread_mutex_lock(&philo->philo_lock);
	better_usleep(philo->time_to_eat, philo);
	if (philo->times_must_eat > -1)
		philo->times_have_eaten++;
	if (philo->death == true || 
		philo->times_have_eaten == philo->times_must_eat)
		philo->exited = true;
	fork_unlock(philo);
	pthread_mutex_unlock(&philo->philo_lock);
	philo_sleep(philo);
}

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_lock);
	if (philo->death == true)
	{
		pthread_mutex_unlock(&philo->philo_lock);
		return ;
	}
	get_current_time(philo, 2);
	pthread_mutex_unlock(&philo->philo_lock);
	print_states(philo, 2);
	pthread_mutex_lock(&philo->philo_lock);
	better_usleep(philo->time_to_sleep, philo);
	pthread_mutex_unlock(&philo->philo_lock);
	philo_think(philo);
}

void	philo_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_lock);
	if (philo->death == true)
	{
		pthread_mutex_unlock(&philo->philo_lock);
		return ;
	}
	get_current_time(philo, 0);
	pthread_mutex_unlock(&philo->philo_lock);
	print_states(philo, 3);
	usleep(200);
	philo_eat(philo);
}

void	better_usleep(int time_to_wait, t_philo *philo)
{
	int	deadline;

	get_current_time(philo, 0);
	deadline = philo->current_time_ms + time_to_wait;
	while (philo->current_time_ms < deadline)
	{
		if (philo->death == true)
			return ;
		pthread_mutex_unlock(&philo->philo_lock);
		usleep(200);
		pthread_mutex_lock(&philo->philo_lock);
		get_current_time(philo, 0);
	}
}
