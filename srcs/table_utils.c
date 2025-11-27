/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 09:34:35 by mhidani           #+#    #+#             */
/*   Updated: 2025/11/27 13:31:10 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*ft_init_table(int c, char **v)
{
	t_table	*table;

	table = malloc(1 * sizeof(t_table));
	if (table == NULL)
	{
		ft_putstr_fd("Error: allocate table in the memory.", STDERR_FILENO);
		return (NULL);
	}
	table->n_philo = ft_take_lvalue(c, 1, v);
	table->time_to_die = ft_take_lvalue(c, 2, v);
	table->time_to_eat = ft_take_lvalue(c, 3, v);
	table->time_to_sleep = ft_take_lvalue(c, 4, v);
	table->n_meals = ft_take_lvalue(c, 5, v);
	table->philos[table->n_philo];
	return (table);
}

unsigned long	ft_take_lvalue(int c, int i, char **v)
{
	if (i < c)
		return (atoi(v[i]));
	return (0);
}
