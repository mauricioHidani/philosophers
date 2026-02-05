/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:06:49 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/05 09:51:22 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define TRUE		0x01
# define FALSE		0x00

# define TAKE_FORK	"has taken a fork"
# define EAT		"is eating"
# define SLEEP		"is sleeping"
# define THINK		"is thinking"
# define DIE		"died"

typedef char			t_bool;
typedef struct s_table	t_table;
typedef struct s_philo	t_philo;

typedef struct s_table
{
	long			members;
	long			start_time;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			limit_meals;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	death;
	pthread_mutex_t	servings;
	pthread_t		thread;
	t_bool			stop;
}	t_table;

typedef struct s_philo
{
	size_t			id;
	long			meals;
	long			last_meal;
	pthread_mutex_t	meal;
	pthread_mutex_t	serving;
	pthread_t		thread;
	t_table			*table;
}	t_philo;

void	serve_meal(t_table *table);
void	*monitor_runtine(void *arg);
void	*philo_runtine(void *arg);
void	find_forks(t_philo *philo, int *first, int *second);
t_bool	take_forks(t_philo *philo, int first, int second);
t_bool	down_forks(t_philo *philo, int first, int second);
t_bool	should_stop(t_table *table);
t_bool	check_deaths(t_table *table);
t_bool	check_satisfaction(t_table *table);
void	psafe(t_philo *philo, const char *msg);

void	init_table(t_table *table, char **args);
void	wait_threads(t_table *table);
void	cleanup(t_table *table);

t_bool	checkin(int argc, char **argv);
int		phelper(void);

long	timestamp(void);
void	wait_time(t_table *table, long time);
long	ft_atol(const char *src);
t_bool	ft_isdigit(char c);
t_bool	ft_isspace(char c);

#endif