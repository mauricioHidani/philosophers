/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accommodate_philos_at.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:48:30 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/28 21:13:43 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**accommodate_philos_at(t_table *table)
{
	t_philo	**philomenas;
	size_t	i;

	if (!table)
		return (NULL);
	philomenas = ft_calloc(table->n_philos + 1, sizeof(t_philo *));
	if (!philomenas)
	{
		pinfo(ERROR, STDERR_FILENO, ERRMSG_ALLOC);
		return (NULL);
	}
	i = 0;
	while (i < table->n_philos)
	{
		philomenas[i] = new_philos(table);
		philomenas[i]->id = i + 1;
		philomenas[i]->right_fork = table->forks[i];
		i++;
	}
	return (philomenas);
}
