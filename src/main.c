/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 23:22:27 by mhidani           #+#    #+#             */
/*   Updated: 2026/01/29 17:53:05 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;
	
	if (argc < 5 || argc > 6)
		return (phelper());
	if (!parse_input(argc, argv, &table))
		return (phelper());
	serve_meal_at(table);
	cleanup(table);
	return (EXIT_SUCCESS);
}
