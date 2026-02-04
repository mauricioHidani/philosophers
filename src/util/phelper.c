/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phelper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 21:47:13 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/03 23:38:12 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	phelper(int exit_code)
{
	printf("./bin/philo <1> <2> <3> <4> [5]\n");
	printf("\t1. Number of philosophers [mandatory]\n");
	printf("\t2. Time to die [mandatory]\n");
	printf("\t3. Time to ead [mandatory]\n");
	printf("\t4. Time to sleep [mandatory]\n");
	printf("\t5. Meal limit per philosopher [optional]\n");
	printf("*All information must be whole numbers");
	return (exit_code);
}
