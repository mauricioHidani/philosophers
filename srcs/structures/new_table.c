/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:45:26 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/29 17:28:10 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*new_table(int argc, char **argv)
{
	t_table	*table;

	if (argc < 5 || !argv)
		return (NULL);
	table = ft_calloc(1, sizeof(t_table));
	if (!table)
	{
		cpinfo(ERROR, STDERR_FILENO, ERRMSG_ALLOC);
		return (NULL);
	}
	table->members = ft_atoi(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	if (argc > 5)
		table->limit_meals = ft_atol(argv[5]);
	table->is_finished = FALSE;
	table->forks = ft_calloc(table->members + 1, sizeof(t_fork *));
	if (!table->forks)
	{
		cpinfo(ERROR, STDERR_FILENO, ERRMSG_ALLOC);
		destroy_table(table);
		return (NULL);
	}
	return (table);
}
