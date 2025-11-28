/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:53:00 by mhidani           #+#    #+#             */
/*   Updated: 2025/11/28 13:49:20 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	ft_count_digits(long nbr);

char	*ft_itoa(long nbr)
{
	long	size;
	long	i;
	char	*res;

	size = ft_count_digits(nbr);
	res = ft_calloc(size + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	if (nbr < 0)
	{
		res[i] = '-';
		nbr = -nbr;
		i++;
	}
	i = size - 1;
	while (i >= 0 && nbr >= 10)
	{
		res[i] = (nbr % 10) + 48;
		nbr /= 10;
		i--;
	}
	res[i] = (nbr % 10) + 48;
	return (res);
}

static long	ft_count_digits(long nbr)
{
	long	count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		count++;
	while (nbr > 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}
