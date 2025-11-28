/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 09:24:52 by mhidani           #+#    #+#             */
/*   Updated: 2025/11/28 11:54:50 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	ft_get_long(int argc, int idx, char **argv);

t_table	*ft_create_table(int argc, char **argv)
{
	t_table	*table;
	t_philo	*philos;
	int		meals;

	if (argc < 4)
		return (NULL);
	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->forks = (int)ft_get_long(argc, 1, argv);
	table->time_to_die = ft_get_long(argc, 2, argv);
	table->time_to_eat = ft_get_long(argc, 3, argv);
	table->time_to_sleep = ft_get_long(argc, 4, argv);
	meals = (int)ft_get_long(argc, 5, argv);
	table->philos = ft_create_philos(table->forks, meals);
	if (!table->philos)
		ft_clean_table(table);
	pthread_mutex_init(&(table->mtx), NULL);
	table->ready_to_work = TRUE;
	return (table);
}

void	ft_clean_table(t_table *table)
{
	if (!table)
		return ;
	ft_clean_philos(table->philos);
	free(table);
	table = NULL;
}

static long	ft_get_long(int argc, int idx, char **argv)
{
	if (idx < argc)
		return (ft_atol(argv[idx]));
	ft_putstr_fd("Error: cannot access argument vector.", STDERR_FILENO);
	return (-1);
}
