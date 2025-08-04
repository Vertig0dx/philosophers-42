/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:56:29 by lmiguel-          #+#    #+#             */
/*   Updated: 2024/06/03 16:40:03 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arg_checker(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
	{
		printf("Invalid Arguments.\n");
		return (-1);
	}
	if (ac == 6)
	{
		if (ft_atol(av[5]) <= 0)
		{
			printf("Invalid Arguments.\n");
			return (-1);
		}
	}
	while (i < 5)
	{
		if (ft_atol(av[i++]) <= 0)
		{
			printf("Invalid Arguments.\n");
			return (-1);
		}
	}
	return (0);
}

int	mutex_create(t_table *table)
{
	int	n;

	n = 0;
	if (pthread_mutex_init(&table->print_lock, NULL) != 0)
	{
		printf ("\n Mutex init for print_lock has failed.\n");
		return (-1);
	}
	if (pthread_mutex_init(&table->table_lock, NULL) != 0)
	{
		printf ("\n Mutex init for table_lock has failed.\n");
		return (-1);
	}
	while (n < table->philo_num)
	{
		if (pthread_mutex_init(&table->philo[n].time_lock, NULL) != 0)
		{
			printf ("\n Mutex init for time_lock number %d has failed.\n", n);
			return (-1);
		}
		n++;
	}
	return (0);
}

int	thread_create(t_table *table)
{
	int				n;
	int				error;
	struct timeval	tv;

	n = 0;
	pthread_mutex_lock(&table->table_lock);
	while (n < table->philo_num)
	{
		error = pthread_create((&table->philo[n].thread_id), 
				NULL, life, &table->philo[n]);
		if (error != 0)
		{
			printf("\n Thread can't be created, error number:[%d]\n", error);
			return (-1);
		}
		n++;
	}
	pseudo_philo_init(table);
	gettimeofday(&tv, NULL);
	table->time_start_ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	pthread_mutex_unlock(&table->table_lock);
	return (0);
}

int	start_routine(t_table *table, int philo_num)
{
	int	n;

	n = 0;
	if (table->philo_num == 1)
		pthread_join(table->philo[n].thread_id, NULL);
	while (n < philo_num && philo_num > 1)
	{
		pthread_mutex_lock(&table->table_lock);
		if (routine_check(&table->philo[n]) == -1)
		{
			death_march(table, n);
			pthread_mutex_unlock(&table->table_lock);
			break ;
		}
		if (table->exit_num == table->philo_num)
		{
			death_march(table, -2);
			pthread_mutex_unlock(&table->table_lock);
			break ;
		}
		pthread_mutex_unlock(&table->table_lock);
		if (++n == philo_num)
			n = 0;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	table;
	int		philo_num;

	if (arg_checker(argc, argv) == -1)
		return (-1);
	table.philo_num = ft_atol(argv[1]);
	philo_num = table.philo_num;
	table.exit_num = 0;
	if (all_creation(argc, argv, &table) == -1)
	{
		clean_and_destroy(&table);
		return (-1);
	}
	usleep(7000);
	start_routine(&table, philo_num);
	clean_and_destroy(&table);
	return (0);
}

/* FOR HELGRIND:

USE THIS AND PLACE IT BEFORE THE INCREMENTING OF N = usleep(50); */