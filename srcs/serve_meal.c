/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serve_meal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:06:57 by mhidani           #+#    #+#             */
/*   Updated: 2025/11/28 14:19:02 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void *ft_bring_to_life(void *prt);

void	ft_serve_meal(t_table *table)
{
	int		i;
	t_philo	*philo;

	if (!table)
		return ;
	i = 0;
	while (i < table->forks)
	{
		philo = (table->philos + i);
		if (pthread_create(&philo, NULL, &ft_bring_to_life, philo) != 0)
		{
			ft_putstr_fd("Error: failed to create the thread.", STDERR_FILENO);
			table->ready_to_work = FALSE;
		}
		if (pthread_join(philo->thread, NULL) != 0)
		{
			ft_putstr_fd("Error: failed execution thread.", STDERR_FILENO);
			table->ready_to_work = FALSE;
		}
		i++;
	}
}

static void	*ft_bring_to_life(void *ptr)
{
	t_philo	*philo;
	t_bool	*ready_to_work;
	t_timer timer;

	if (!ptr)
		return (NULL);
	philo = (t_philo *)ptr;
	timer = ft_create_timer(philo->table->time_to_die);
	philo->live_time = timer.start;
	while (philo->table->ready_to_work && ft_its_not_over(timer))
	{
		// verificar se deve pensar (pega o garfo quando está pensando)
		// verificar se pode comer
		// verificar se deve dormir
		usleep(250);
		gettimeofday(&timer.current, NULL);
	}
	philo->status = DEAD;
	ft_print_philo_state(philo);
}
