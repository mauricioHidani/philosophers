/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 09:11:50 by mhidani           #+#    #+#             */
/*   Updated: 2025/12/03 17:11:38 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_dining_table	*table;

	if (argc < 5 || argc > 6)
		return (FAILURE);
	table = ft_new_dining_table(argv, argc);
	if (ft_isvalid_dining_table(table) == FALSE)
		ft_destroy_dining_table(table);
	ft_dining_table_monitor(table);
	ft_destroy_dining_table(table);
	return (SUCCESS);
}
