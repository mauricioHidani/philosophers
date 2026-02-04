/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 00:00:37 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/04 00:08:19 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_for_end(t_table *table)
{
	size_t	i;
	t_philo	*philos;

	i = 0;
	philos = table->philos;
	while (i < (size_t)table->members)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
		{
			perr("");
			printf("%sWait for philo %d failed%s\n", RED, i + 1, RST);
		}
		i++;
	}
	if (pthread_join(table->thread, NULL) != 0)
		perr("Wait for monitor failed\n");
}
