/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_for.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 23:48:06 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/26 10:44:41 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_for(long duration)
{
	long	start;
	long	current;

	start = get_timestamp_ms();
	current = get_timestamp_ms() - start;
	while (current <= duration)
	{
		current = get_timestamp_ms() - start;
		usleep(250);
	}
}
