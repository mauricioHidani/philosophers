/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_table_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:29:32 by mhidani           #+#    #+#             */
/*   Updated: 2025/12/02 20:22:09 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	ft_destroy_dining_table(t_dining_table *table)
{
	if (!table)
		return (FALSE);
	ft_destroy_forks(table->forks_mtx, table->number_of_philos);
	ft_destroy_philos(table->philos, table->number_of_philos);
	pthread_mutex_destroy(&table->print_mtx);
	free(table);
	return (TRUE);
}

t_dining_table	*ft_new_dining_table(char **srcs, int size)
{
	t_dining_table	*table;

	table = ft_calloc(1, sizeof(t_dining_table));
	if (!table)
		return (NULL);
	table->number_of_philos = ft_get_lvalue(srcs, size, 1);
	table->time_to_die = ft_get_lvalue(srcs, size, 2);
	table->time_to_eat = ft_get_lvalue(srcs, size, 3);
	table->time_to_sleep = ft_get_lvalue(srcs, size, 4);
	table->number_of_meals = ft_get_lvalue(srcs, size, 5);
	table->forks_mtx = ft_new_forks(table);
	table->philos = ft_new_philos(table);
	pthread_mutex_init(&table->print_mtx, NULL);
	return (table);
}

t_bool	ft_isvalid_dining_table(t_dining_table *table)
{
	if (!table)
		return (FALSE);
	if (table->number_of_philos <= 0)
		return (FALSE);
	if (table->time_to_die < 0)
		return (FALSE);
	if (table->time_to_eat < 0)
		return (FALSE);
	if (table->time_to_sleep < 0)
		return (FALSE);
	if (table->forks_mtx == NULL)
		return (FALSE);
	if (table->philos == NULL)
		return (FALSE);
	return (TRUE);
}
