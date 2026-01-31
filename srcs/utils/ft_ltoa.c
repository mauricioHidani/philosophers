/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:45:11 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/29 14:10:59 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	count_decimal_places(long nbr);

char	*ft_ltoa(long nbr)
{
	char			*str;
	size_t			dplace;
	unsigned long	aux;
 
	dplace = count_decimal_places(nbr);
	str = ft_calloc(dplace + 1, sizeof(char));
	if (!str)
		return (NULL);
	aux = nbr;
	if (nbr < 0)
	{
		str[0] = '-';
		aux = -nbr;
		dplace--;
	}
	while (aux >= 10)
	{
		str[dplace] = (aux % 10) + 48;
		aux /= 10;
		dplace--;
	}
	str[dplace] = (aux % 10) + 48;
	return (str);
}

static size_t	count_decimal_places(long nbr)
{
	size_t			decimal;
	unsigned long	aux;

	decimal = 0;
	aux = nbr;
	if (nbr < 0)
	{
		aux = -nbr;
		decimal++;
	}
	while (aux > 0)
	{
		aux /= 10;
		decimal++;
	}
	return (decimal);
}
