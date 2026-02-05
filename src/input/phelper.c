/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phelper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:07:59 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/04 20:12:49 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	phelper(void)
{
	printf("./bin/philo <1> <2> <3> <4> [5]\n");
	printf("1. Members of meal [mandatory]\n");
	printf("2. Time to die [mandatory]\n");
	printf("3. Time to eat [mandatory]\n");
	printf("4. Time to sleep [mandatory]\n");
	printf("5. Limit meals of each member [optional]\n");
	printf("* The information must be whole numbers, not decimal\n");
	return (EXIT_SUCCESS);
}
