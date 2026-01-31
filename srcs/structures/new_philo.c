/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:43:09 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/29 17:36:38 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*new_philo(t_table *table, int idx)
{
	t_philo	*philo;

	if (!table)
		return (NULL);
	philo = ft_calloc(1, sizeof(t_philo));
	if (!philo)
	{
		cpinfo(ERROR, STDERR_FILENO, ERRMSG_ALLOC);
		return (NULL);
	}
	philo->id = idx + 1;
	philo->meals = 0;
	philo->last_meal = 0;
	philo->table = table;
	philo->right_fork = table->forks[idx];
	philo->left_fork = table->forks[0];
	if (table->forks[idx + 1])
		philo->left_fork = table->forks[idx + 1];
	return (philo);
}
