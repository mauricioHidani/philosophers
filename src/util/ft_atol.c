/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:31:14 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/04 20:01:22 by mhidani          ###   ########.fr       */
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
	sign = 1;
	nbr = 0;
	while (src[i] && ft_isspace(src[i]))
		i++;
	if (src[i] == '-')
		sign = -1;
	if (src[i] == '+' || src[i] == '-')
		i++;
	while (src[i] && ft_isdigit(src[i]))
	{
		nbr = (nbr * 10) + (src[i] - 48);
		i++;
	}
	return (nbr * sign);
}
