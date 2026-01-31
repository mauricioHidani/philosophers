/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 23:23:10 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/31 14:56:28 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include "type.h"
# include "utils.h"

# define MSG_TAKE_FORK "has taken a fork"
# define MSG_EATING "is eating"
# define MSG_SLEEPING "is sleeping"
# define MSG_THINKING "is thinking"
# define MSG_DIED "died"

typedef struct s_table	t_table;
typedef struct s_philo	t_philo;
typedef struct s_fork	t_fork;

typedef struct s_table
{
	int				members;
	long			start_time;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			limit_meals;
	t_bool			is_finished;
	t_philo			**philomenas;
	pthread_t		monitor;
	pthread_mutex_t	**forks;
	pthread_mutex_t	print_mtx;
	pthread_mutex_t	death_mtx;
}	t_table;

typedef struct s_philo
{
	int				id;
	long			meals;
	long			last_meal;
	t_table			*table;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

// Serve Meal At The Table -----------------------------------------------------

int	serve_meal_at(t_table *table);

// ----------------------------------------------------- Serve Meal At The Table

// Mainteiner ------------------------------------------------------------------

void	*monitor_runtine(void *ptr);
void	*philo_runtine(void *ptr);
void	philo_think(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_eat(t_philo *philo);
void	print_action(t_philo *philo, char *action);

// ------------------------------------------------------------------ Mainteiner

// Structures ------------------------------------------------------------------

t_bool	parse_input(int argc, char **argv, t_table **table);
t_table	*new_table(int argc, char **argv);
t_philo	*new_philo(t_table *table, int idx);
t_philo	**new_philos(t_table *table);
void	tidy_up_utensils(t_table *table);
void	destroy_philos(t_philo **philos);
void	destroy_forks(t_fork **forks);
void	cleanup(t_table *table);

// ------------------------------------------------------------------ Structures

#endif
