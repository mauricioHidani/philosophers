/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:33:06 by mhidani           #+#    #+#             */
/*   Updated: 2025/12/05 16:25:40 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>

# define SUCCESS 0x00
# define FAILURE 0x01
# define TRUE 0x01
# define FALSE 0x00

typedef char	t_bool;

typedef struct s_dining_table
{
	int				number_of_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			number_of_meals;
	long			lifetime;
	t_bool			someone_died;
	pthread_mutex_t	lifetime_mtx;
	pthread_mutex_t	print_mtx;
	pthread_mutex_t	**forks_mtx;
	pthread_t		death_monitor;
	struct s_philo	**philos;
}					t_dining_table;

typedef struct s_philo
{
	int						id;
	long					last_meal;
	long					meals_eaten;
	pthread_t				thread;
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			*right_fork;
	struct s_dining_table	*table;
}							t_philo;

// Dining Table Utilities ------------------------------------------------------
t_dining_table	*ft_new_dining_table(char **srcs, int size);
t_bool			ft_destroy_dining_table(t_dining_table *table);
t_bool			ft_isvalid_dining_table(t_dining_table *table);
void			ft_dining_table_monitor(t_dining_table *table);
void			*ft_routine_monitor(void *ptr);
void			*ft_death_monitor(void *ptr);

// Forks Utilities -------------------------------------------------------------
pthread_mutex_t	**ft_new_forks(t_dining_table *table);
t_bool			ft_destroy_forks(pthread_mutex_t **forks, size_t size);
void			ft_locate_forks_to_philo(t_philo *philo);

// Philosopher Utilities -------------------------------------------------------
t_philo			**ft_new_philos(t_dining_table *table);
t_bool			ft_destroy_philos(t_philo **philos, size_t size);
void			ft_think(t_philo *philo);
void			ft_eat(t_philo *philo);
void			ft_sleep(t_philo *philo);

// Time Utilities --------------------------------------------------------------
long			ft_get_time(void);
void			ft_wait_for_time(long ms);

// Utilities -------------------------------------------------------------------
void			ft_print_help(void);
void			*ft_calloc(size_t nmemb, size_t size);
t_bool			ft_isspace(char c);
t_bool			ft_isdigit(char c);
long			ft_atol(char *src);
long			ft_get_lvalue(char **vector, int size, int idx);
void			ft_print_status(t_philo *philo, char *status);
void			ft_print_locked(t_philo *philo, char *status);
