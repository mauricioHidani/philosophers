/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:30:24 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/04 21:56:24 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (!checkin(argc, argv))
		return (phelper());
	init_table(&table, argv);
	serve_meal(&table);
	wait_threads(&table);
	cleanup(&table);
	return (EXIT_SUCCESS);
}
