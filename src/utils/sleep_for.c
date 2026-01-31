/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_for.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 23:48:06 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/29 15:47:52 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_for(long duration, t_bool no_action)
{
	long	start;
	long	current;

	start = get_timestamp_ms();
	current = get_timestamp_ms() - start;
	while (current <= duration && !no_action)
	{
		current = get_timestamp_ms() - start;
		usleep(250);
	}
}
