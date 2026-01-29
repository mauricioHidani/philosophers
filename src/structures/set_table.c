/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:45:26 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/28 21:16:24 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*set_table(int argc, char **argv)
{
	t_table	*table;

	if (argc < 5 || !argv)
		return (NULL);
	table = ft_calloc(1, sizeof(t_table));
	if (!table)
	{
		pinfo(ERROR, STDERR_FILENO, ERRMSG_ALLOC);
		return (NULL);
	}
	table->n_philos = (int)ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	if (argc > 5)
		table->limit_meals = ft_atol(argv[5], DECIMAL_BASE);
	table->is_finished = FALSE;
	table->forks = ft_calloc(table->n_philos + 1, sizeof(t_fork *));
	if (!table->forks)
	{
		pinfo(ERROR, STDERR_FILENO, ERRMSG_ALLOC);
		destroy_table(table);
		return (NULL);
	}
	return (table);
}
