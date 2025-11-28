/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 09:32:26 by mhidani           #+#    #+#             */
/*   Updated: 2025/11/28 09:40:08 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(char *src)
{
	long	nbr;
	long	sign;
	size_t	i;

	if (!src)
		return (0);
	nbr = 0;
	sign = 1;
	while (src[i] && ft_isspace(src[i]))
		i++;
	if (src[i] && (src[i] == 45 || src[i] == 43))
	{
		if (src[i] == 45)
			sign = -1;
		i++;
	}
	while (src[i] && ft_isdigit(src[i]))
	{
		nbr = 10 * nbr + (src[i] - 48);
		i++;
	}
	return (nbr * sign);
}
