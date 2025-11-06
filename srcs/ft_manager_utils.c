/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manager_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:18:48 by mhidani           #+#    #+#             */
/*   Updated: 2025/11/06 16:27:36 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_manager_assign(int argc, char **argv, t_manager *manager)
{
	manager->number_of_philosophers = ft_atol(argv[1]);
	manager->time_to_die = ft_atol(argv[2]);
	manager->time_to_eat = ft_atol(argv[3]);
	manager->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		manager->times_you_should_eat = ft_atol(argv[5]);
}

t_manager	*ft_new_manager(void)
{
	t_manager	*manager;

	manager = malloc(sizeof(t_manager));
	if (!manager)
	{
		ft_putstr_fd("Error: memory allocation new manager\n", stderr);
		return (NULL);
	}
	return (manager);
}

void	ft_clean_manager(void *ptr)
{
	if (!ptr)
		return ;
	free(ptr);
}
