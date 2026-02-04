/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 08:16:57 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/04 00:19:25 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table table;

	if (!check_input(argc, argv))
		return (phelper(EXIT_SUCCESS));
	if (!init_table(argv, &table))
		return (EXIT_FAILURE);
	serve_meal_at(&table);
	wait_for_end(&table);
	cleanup(&table);
	return (EXIT_SUCCESS);
}
