/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:12:12 by mhidani           #+#    #+#             */
/*   Updated: 2025/12/02 17:18:03 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	ft_isspace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

t_bool	ft_isdigit(char c)
{
	return (c >= 48 && c <= 57);
}

long	ft_atol(char *src)
{
	long	nbr;
	int		sign;
	size_t	i;

	if (!src)
		return (0);
	nbr = 0;
	sign = 1;
	i = 0;
	while (src[i] && ft_isspace(src[i]))
		i++;
	if (src[i] == 43 || src[i] == 45)
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
