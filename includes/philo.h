/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:33:06 by mhidani           #+#    #+#             */
/*   Updated: 2025/12/02 20:22:26 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>

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
	pthread_mutex_t	print_mtx;
	pthread_mutex_t	**forks_mtx;
	pthread_t		death_monitor_thread;
	t_philo			**philos;
}			t_dining_table;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_dining_table	*table;
}	t_philo;

// Dining Table Utilities ------------------------------------------------------
t_dining_table	*ft_new_dining_table(char **srcs, int size);
t_bool			ft_destroy_dining_table(t_dining_table *table);
t_bool			ft_isvalid_dining_table(t_dining_table *table);

// Forks Utilities -------------------------------------------------------------
pthread_mutex_t	**ft_new_forks(t_dining_table *table);
t_bool			ft_destroy_forks(pthread_mutex_t **forks, size_t size);
void			ft_locate_forks_to_philo(t_philo *philo);

// Philosopher Utilities -------------------------------------------------------
t_philo			**ft_new_philos(t_dining_table *table);
t_bool			ft_destroy_philos(t_philo **philos, size_t size);

// Utilities -------------------------------------------------------------------
void	ft_print_help(void);
void	*ft_calloc(size_t nmemb, size_t size);
t_bool	ft_isspace(char c);
t_bool	ft_isdigit(char c);
long	ft_atol(char *src);
long	ft_get_lvalue(char **vector, int size, int idx);
