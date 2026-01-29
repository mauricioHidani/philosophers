/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 23:22:27 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/28 21:25:21 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;
	
	if (argc < 5 || argc > 6)
	{
		phelper();
		return (EXIT_SUCCESS);
	}
	table = set_table(argc, argv);
	serve_meal_at(table);
	unset_table(table);
	return (EXIT_SUCCESS);
}
