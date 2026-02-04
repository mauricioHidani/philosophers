/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:21:40 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/04 00:00:04 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

# define TRUE 0x01
# define FALSE 0x00

# define BLUE "\033[0;38;2;98;160;234;49m"
# define RED "\033[0;38;2;237;51;59;49m"
# define RED_ITALIC "\033[3;38;2;237;51;59;49m"
# define GREEN "\033[0;38;2;87;227;137;49m"
# define ORANGE "\033[0;38;2;255;163;72;49m"
# define ITALIC "\033[3m"
# define RST "\033[0m"

# define TAKE_FORK "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DIED "died"

typedef char			t_bool;
typedef struct s_table	t_table;
typedef struct s_philo	t_philo;

typedef struct s_table
{
	long			members;
	long			start;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			limit_meals;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	state;
	t_bool			finished;
	pthread_t		thread;
}					t_table;

typedef struct s_philo
{
	int				id;
	long			last_meal;
	long			meals;
	pthread_mutex_t	meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread;
	t_table			*table;
	t_bool			satisfied;
}					t_philo;

void	*monitor_runtine(void *arg);
void	*philo_runtine(void *arg);
t_bool	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

void	serve_meal_at(t_table *table);
void	wait_for_end(t_table *table);
t_bool	should_stop(t_table *table);

int		phelper(int exit_code);
void	perr(const char *src);
void	pinfo(const char *src);
void	pwarning(const char *src);
void	psafe(t_philo *philo, const char *src);

long	get_timestamp(void);
void	wait_ms(t_table *table, long ms);

t_bool	check_input(int argc, char **argv);
t_bool	init_table(char **in, t_table *table);
void	cleanup(t_table *table);

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
long	ft_atol(const char *src);

#endif
