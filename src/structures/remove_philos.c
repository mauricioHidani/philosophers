/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 21:22:41 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/28 21:24:23 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	remove_philos(t_philo **philos)
{
	size_t	i;

	if (!philos)
		return ;
	i = 0;
	while (philos[i])
	{
		free(philos[i]);
		i++;
	}
	free(philos);
}
