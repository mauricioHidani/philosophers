/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:17:03 by mhidani           #+#    #+#             */
/*   Updated: 2025/11/27 13:30:14 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_create_philo(t_table *table, int n_meals)
{
	t_philo	*philo;

	if (!table)
		return (NULL);
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->n_meals = n_meals;
	philo->left_fork = TRUE;
	philo->right_fork = FALSE;
	philo->table = table;
	return (philo);
}

void	ft_clean_philo(void *ptr)
{
	if (!ptr)
		return ;
	free(ptr);
}
