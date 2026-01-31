/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:26:45 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/29 17:52:25 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	parse_input(int argc, char **argv, t_table **table)
{
	*table = new_table(argc, argv);
	if (!table)
		return (FALSE);
	(*table)->philomenas = new_philos(*table);
	if (!(*table)->philomenas)
	{
		cleanup(*table);
		return (FALSE);
	}
	return (TRUE);
}
