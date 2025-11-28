/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:12:56 by mhidani           #+#    #+#             */
/*   Updated: 2025/11/28 14:19:27 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define SUCCESS 0x00
# define FAILURE 0x01

# define TRUE 0x01
# define FALSE 0x00

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <sys/time.h>

typedef char		t_bool;

enum e_status
{
	NEUTRAL,
	THINK,
	SLEEP,
	DEAD
};

typedef struct s_philo
{
	int				id;
	enum e_status	status;
	pthread_t		thread;
	t_table			*table;
	int				meals;
	t_bool			left_fork;
	t_bool			rigth_fork;
	struct timeval	live_time;
}					t_philo;

typedef struct s_table // cannot modify in threads
{
	int				forks;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	pthread_mutex_t	mtx;
	t_bool			ready_to_work;
	t_philo			*philos;
}					t_table;

typedef struct s_timer
{
	struct timeval	start;
	struct timeval	current;
	struct timeval	end;
}	t_timer;

// Meal ------------------------------------------------------------------------
void	ft_serve_meal(t_table *table);

// Utilities -------------------------------------------------------------------
t_bool	ft_isspace(char c);
t_bool	ft_isdigit(char c);
long	ft_atol(char *src);
char	*ft_itoa(long nbr);
void	*ft_calloc(size_t nmemb, size_t size);

// Philosophers Utilities ------------------------------------------------------
t_philo	*ft_create_philos(int forks, int meals);
void	ft_clean_philos(t_philo *philos);
void	ft_print_philo_state(t_philo *philo);

// Table Utilities -------------------------------------------------------------
t_table	*ft_create_table(int argc, char **argv);
void	ft_clean_table(t_table *table);

// Timer Utilities -------------------------------------------------------------
t_timer	ft_create_timer(long end_offset);
t_bool	ft_its_not_over(t_timer timer);

#endif
