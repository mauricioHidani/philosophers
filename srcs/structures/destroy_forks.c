/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 18:51:26 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/29 17:48:32 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_forks(t_fork **forks)
{
	size_t	i;

	if (!forks)
		return ;
	i = 0;
	while (forks[i])
	{
		pthread_mutex_destroy(forks[i]);
		free(forks[i]);
		i++;
	}
	free(forks);
}
