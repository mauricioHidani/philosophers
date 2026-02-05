/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:58:19 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/04 21:56:26 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	check_int_isnum(char **nums, int elms);

t_bool	checkin(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (FALSE);
	if (!check_int_isnum(argv, argc))
		return (FALSE);
	return (TRUE);
}

static t_bool	check_int_isnum(char **nums, int elms)
{
	size_t	i;
	size_t	j;

	if (!nums)
		return (FALSE);
	i = 1;
	while (i < (size_t)elms)
	{
		j = 0;
		while (nums[i][j] && ft_isspace(nums[i][j]))
			j++;
		if (nums[i][j] == '+' || nums[i][j] == '-')
			j++;
		while (nums[i][j])
		{
			if (!ft_isdigit(nums[i][j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
