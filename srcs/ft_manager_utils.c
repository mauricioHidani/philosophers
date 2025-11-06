/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manager_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:18:48 by mhidani           #+#    #+#             */
/*   Updated: 2025/11/06 15:24:56 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
