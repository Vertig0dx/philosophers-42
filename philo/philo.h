/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:45:37 by lmiguel-          #+#    #+#             */
/*   Updated: 2024/06/03 16:02:55 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <errno.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_philo
{
	bool			exited;
	bool			exit_check;
	bool			death;
	int				seat_num;
	int				philo_num;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			times_must_eat;
	long			times_have_eaten;
	long			time_spent_eating;
	long			time_spent_sleeping;
	long			time_since_meal;
	long			latest_meal;
	long			current_time_ms;
	long			time_start_ms;
	struct s_table	*table;
	pthread_t		thread_id;
	pthread_mutex_t	philo_lock;
	pthread_mutex_t	time_lock;
}	t_philo;

typedef struct s_table
{
	int				philo_num;
	int				philos_exited;
	int				exit_num; 
	long			time_start_ms;
	t_philo			*philo;
	pthread_mutex_t	table_lock;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print_lock;
}	t_table;
//char and char* go here

//int, unsigned int and long go here
int		all_creation(int argc, char **argv, t_table *table);
int		fork_setup(t_table *table);
int		mutex_create(t_table *table);
int		routine_check(t_philo *philo);
int		table_setup(int argc, char **argv, t_table *table);
int		thread_create(t_table *table);
long	ft_atol(const char *str);

//void goes here
void	anti_deadlock(t_philo *philo);
void	better_usleep(int time_to_wait, t_philo *philo);
void	clean_and_destroy(t_table *table);
void	death_march(t_table *table, int n);
void	fork_lock(t_philo *philo);
void	fork_unlock(t_philo *philo);
void	get_current_time(t_philo *philo, int update);
void	*life(void *phill);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
void	print_states(t_philo *philo, int print_num);
void	pseudo_philo_init(t_table *table);
void	pseudo_sleep(t_philo *philo, long time);

#endif