/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 09:11:50 by mhidani           #+#    #+#             */
/*   Updated: 2025/12/02 23:58:37 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_dining_table	*table;

	if (argc < 5 || argc > 6)
		return (FAILURE);
	table = ft_new_dining_table(argv, argc);
	ft_dining_table_monitor(table);
	ft_destroy_dining_table(table);
	return (SUCCESS);
}
