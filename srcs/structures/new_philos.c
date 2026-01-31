/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:48:30 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/29 17:38:51 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**new_philos(t_table *table)
{
	t_philo	**philos;
	size_t	i;

	if (!table)
		return (NULL);
	philos = ft_calloc(table->members + 1, sizeof(t_philo *));
	if (!philos)
	{
		cpinfo(ERROR, STDERR_FILENO, ERRMSG_ALLOC);
		return (NULL);
	}
	i = 0;
	while (i < table->members)
	{
		philos[i] = new_philo(table, i);
		if (!philos[i])
		{
			destroy_philos(philos);
			return (NULL);
		}
		i++;
	}
	return (philos);
}
