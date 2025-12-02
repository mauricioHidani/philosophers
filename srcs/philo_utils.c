/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:59:39 by mhidani           #+#    #+#             */
/*   Updated: 2025/12/02 20:18:32 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	ft_destroy_philos(t_philo **philos, size_t size)
{
	size_t	i;

	if (!philos && !philos[0]->table)
		return (FALSE);
	i = 0;
	size = philos[i]->table->number_of_philos;
	while (i < size)
	{
		free(philos[i]);
		i++;
	}
	free(philos[i]);
	return (TRUE);
}

t_philo	**ft_new_philos(t_dining_table *table)
{
	t_philo	**philos;
	size_t	i;
	size_t	size;

	if (!table)
		return (NULL);
	i = 0;
	size = table->number_of_philos;
	philos = ft_calloc(size + 1, sizeof(t_philo *));
	if (!philos)
		return (NULL);
	while (i < size)
	{
		philos[i] = ft_calloc(1, sizeof(t_philo));
		if (!philos[i])
		{
			ft_destroy_philos(philos, table->number_of_philos);
			return (NULL);
		}
		philos[i]->id = i;
		philos[i]->table = table;
		ft_locate_forks_to_philo(philos[i]);
		i++;
	}
	return (philos);
}
