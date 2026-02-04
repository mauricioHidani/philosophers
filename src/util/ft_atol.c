/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:22:35 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/03 15:25:36 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(const char *src)
{
	long	nbr;
	int		sign;
	size_t	i;

	if (!src)
		return (0);
	i = 0;
	nbr = 0;
	sign = 1;
	while (src[i] == 32 || (src[i] >= 9 && src[i] <= 13))
		i++;
	if (src[i] == '-')
		sign = -1;
	if (src[i] == '+' || src[i] == '-')
		i++;
	while (src[i] && src[i] >= 48 && src[i] <= 57)
	{
		nbr = (nbr * 10) + (src[i] - 48);
		i++;
	}
	return (nbr * sign);
}
