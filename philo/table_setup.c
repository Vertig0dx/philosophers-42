/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:37:03 by lmiguel-          #+#    #+#             */
/*   Updated: 2024/05/29 15:04:42 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	fork_setup(t_table *table)
{
	int	n;

	n = 0;
	table->fork = malloc(sizeof(pthread_mutex_t) * (table->philo_num));
	if (!table->fork)
		return (-1);
	while (n < table->philo_num)
	{
		if (pthread_mutex_init(&table->fork[n], NULL) != 0)
		{
			printf ("\n Mutex init for fork[%d] has failed.\n", n);
			return (-1);
		}
		n++;
	}
	return (0);
}

int	table_setup(int argc, char **argv, t_table *table)
{
	long	n;

	table->philo = malloc(sizeof(t_philo) * (table->philo_num));
	if (!table->philo)
		return (-1);
	n = 0;
	while (n < table->philo_num)
	{
		table->philo[n].table = table;
		pthread_mutex_init(&table->philo[n].philo_lock, NULL);
		if (argc == 6)
			table->philo[n].times_must_eat = ft_atol(argv[5]);
		else
			table->philo[n].times_must_eat = -1;
		table->philo[n].philo_num = ft_atol(argv[1]);
		table->philo[n].time_to_die = ft_atol(argv[2]);
		table->philo[n].time_to_eat = ft_atol(argv[3]);
		table->philo[n].time_to_sleep = ft_atol(argv[4]);
		table->philo[n].seat_num = n;
		table->philo[n].death = false;
		n++;
	}
	if (fork_setup(table) == -1)
		return (-1);
	return (0);
}
