/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 09:11:50 by mhidani           #+#    #+#             */
/*   Updated: 2025/11/29 17:38:09 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "philo.h"
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <sys/time.h>

#define TRUE  0x01
#define FALSE 0x00
typedef char t_bool;

typedef struct s_table
{
	t_bool	ready_to_work;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	t_philo	*philos;	
}	t_table;

/**
 * O filosofo sempre é inicializado com um garfo na mão esquerda, dessa forma,
 * quando ele estiver pensando, vai tentar pegar o garfo do filosofo a sua 
 * direita, dessa forma o gafo desse filosofo será o garfo a direita do que está
 * tentando commer.
 */
typedef struct s_philo
{
	int		id;
	char	*name;
	t_bool	left_fork;
	t_bool	right_fork;
	t_table	*table;
}	t_philo;

typedef struct s_timer
{
	struct timeval	start;
	struct timeval	current;
	struct timeval	end;
}	t_timer;

size_t	ft_putstr_fd(char *str, int fd)
{
	size_t	i;

	if (!str || fd < 0)
		return (0);
	i = 0;
	while (str[i])
		i += write(fd, &(str[i]), 1);
	return (i);
}

long	ft_read_lvalue(int argc, int idx, char **argv)
{
	if (idx < argv)
		return (ft_atol(argv[idx]));
	ft_putstr_fd("error: ft_read_lvalue\n", STDERR_FILENO);
}

t_table	*ft_create_table(int argc, char **argv)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
	{
		ft_putstr_fd("error", STDERR_FILENO);
		return (NULL);
	}
	table->ready_to_work = TRUE;
	table->time_to_die = ft_read_lvalue(argc, 1, argv);
	long	time_to_eat;
	long	time_to_sleep;
	t_philo	*philos;	
	return (table);
}

int	main(int argc, char **argv)
{
	(void)argc; (void)argv;
	return (0);
}
