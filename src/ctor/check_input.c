/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:13:15 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/04 09:15:37 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	check_isnum(const char *src);

t_bool	check_input(int argc, char **argv)
{
	size_t	i;

	if (argc < 5 || argc > 6)
		return (FALSE);
	i = 1;
	while (i < (size_t)argc)
	{
		if (!check_isnum(argv[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static t_bool	check_isnum(const char *src)
{
	size_t	i;

	if (!src)
		return (FALSE);
	i = 0;
	while (src[i] == 32 || (src[i] >= 9 && src[i] <= 13))
		i++;
	if (src[i] == '+' || src[i] == '-')
		i++;
	while (src[i])
	{
		if (!(src[i] >= 48 && src[i] <= 57))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
