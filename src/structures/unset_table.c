/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:04:06 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/28 21:24:52 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	unset_table(t_table *table)
{
	size_t	i;

	if (!table)
		return ;
	i = 0;
	while (table->forks[i])
	{
		destroy_fork(table->forks[i]);
		i++;
	}	
	free(table);
}
