/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:43:09 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/28 20:48:00 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*new_philo(t_table *table)
{
	t_philo	*philo;

	if (!table)
		return (NULL);
	philo = ft_calloc(1, sizeof(t_philo));
	if (!philo)
	{
		pinfo(ERROR, STDERR_FILENO, ERRMSG_ALLOC);
		return (NULL);
	}
	philo->id = -1;
	philo->meals = 0;
	philo->last_meal = 0;
	philo->table = table;
	philo->left_fork = NULL;
	philo->right_fork = NULL;
	return (philo);
}
