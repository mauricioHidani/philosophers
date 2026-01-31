/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 23:23:10 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/29 17:50:47 by mhidani          ###   ########.fr       */
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

typedef pthread_mutex_t	t_mutex;
typedef struct s_table	t_table;
typedef struct s_fork	t_fork;

typedef struct s_table
{
	int			members;
	long		start_time;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		limit_meals;
	t_bool		is_finished;
	t_fork		**forks;
	t_mutex		print_mtx;
	t_mutex		death_mtx;
}	t_table;

typedef struct s_fork
{
	int			id;
	t_mutex		fork;
}	t_fork;

typedef struct s_philo
{
	int			id;
	long		meals;
	long		last_meal;
	t_table		*table;
	pthread_t	thread;
	t_fork		*left_fork;
	t_fork		*right_fork;
}	t_philo;

#endif
