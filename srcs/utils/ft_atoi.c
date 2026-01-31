/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:41:30 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/30 18:41:51 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_atoi(char *nbr)
{
	size_t	i;
	int		num;
	int		sign;

	if (!nbr)
		return (0);
	i = 0;
	num = 0;
	sign = 1;
	while (nbr[i] && ft_isifs(nbr[i]))
		i++;
	if (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign = -1;
		i++;
	}
	while (nbr[i])
	{
		num = num * 10 + nbr[i] - 48;
		i++;
	}
	return (num * sign);
}