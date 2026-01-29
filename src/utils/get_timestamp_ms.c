/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp_ms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:43:52 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/26 10:44:05 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

long	get_timestamp_ms(void)
{
	struct timeval	tvalue;
	long			timestamp;

	gettimeofday(&tvalue, NULL);
	timestamp = tvalue.tv_sec * 1000 + tvalue.tv_usec / 1000;
	return (timestamp);
}
