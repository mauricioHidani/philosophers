/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:03:40 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/29 14:11:07 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static size_t	count_decimal_places(int nbr);

char	*ft_itoa(int nbr)
{
	char			*str;
	size_t			dplace;
	unsigned int	aux;

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

static size_t	count_decimal_places(int nbr)
{
	size_t			dplace;
	unsigned int	aux;

	dplace = 0;
	aux = nbr;
	if (nbr < 0)
	{
		aux = -nbr;
		dplace++;
	}
	while (aux > 0)
	{
		aux /= 10;
		dplace++;
	}
	return (dplace);
}
