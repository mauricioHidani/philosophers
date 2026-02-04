/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phelper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 21:47:13 by mhidani           #+#    #+#             */
/*   Updated: 2026/02/04 11:19:46 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	phelper(int exit_code)
{
	char	*mandatory;
	char	*optional;

	mandatory = "[\033[0;38;2;237;51;59;49mmandatory\033[0m]";
	optional = "[\033[0;38;2;255;163;72;49moptional\033[0m]";
	pinfo("Use this format for inserting fields\n");
	printf("./bin/philo <%s1%s> <%s2%s> <%s3%s> <%s4%s> [%s5%s]\n", 
		RED, RST, RED, RST, RED, RST, RED, RST, ORANGE, RST);
	printf("\t%s1%s. Number of philosophers %s\n", RED, RST, mandatory);
	printf("\t%s2%s. Time to die %s\n", RED, RST, mandatory);
	printf("\t%s3%s. Time to eat %s\n", RED, RST, mandatory);
	printf("\t%s4%s. Time to sleep %s\n", RED, RST, mandatory);
	printf("\t%s5%s. Meal limit per philosopher %s\n", ORANGE, RST, optional);
	pwarning("All information must be whole numbers\n");
	return (exit_code);
}
