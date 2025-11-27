/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:12:56 by mhidani           #+#    #+#             */
/*   Updated: 2025/11/27 13:20:28 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define SUCCESS 0x00
# define FAILURE 0x01

# define TRUE 0x01
# define FALSE 0x00

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <sys/time.h>
# include <pthread.h>
# include "clist.h"

typedef char			t_bool;
typedef unsigned int	t_uint;
typedef unsigned long	t_ulong;

typedef struct s_philo
{
	int				n_meals;
	t_bool			left_fork;
	t_bool			right_fork;
	t_table			*table;
}	t_philo;

typedef struct s_table
{
	pthread_mutex_t	meal_mtx;
	t_ulong			starvation_time;
	t_ulong			eat_time;
	t_ulong			sleep_time;
	t_clist			*philos;
}	t_table;

t_bool		ft_isspace(char c);
long		ft_atol(char *str);
t_bool		ft_isdigit(char c);
size_t		ft_putstr_fd(char *str, int fd);

// Philo Utils -----------------------------------------------------------------
t_philo		*ft_create_philo(t_table *table, int n_meals);
void		ft_clean_philo(void *ptr);

#endif
