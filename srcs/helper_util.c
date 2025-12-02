/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:38:00 by mhidani           #+#    #+#             */
/*   Updated: 2025/12/02 16:51:30 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_help(void)
{
	printf("How can you enter the philosopher application\n");
	printf("help? $> ./bin/philo ");
	printf("<number_of_philosophers> <time_to_die> <time_to_eat> ");
	printf("<time_to_sleep> [number_of_times_they_should_eat]\n");
	printf("\nHow do you enter the values:\n");
	printf("You don't need write the sings, only the values!\n");
	printf("<value>: between the '<' and '>' signs, are mandatory fields\n");
	printf("[value]: between the '[' and ']' sings, are optional fields\n");
}
