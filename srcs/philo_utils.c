/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 09:44:37 by mhidani           #+#    #+#             */
/*   Updated: 2025/11/28 14:13:48 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_start_philos(int forks, int meals, t_philo *philos);

t_philo	*ft_create_philos(int forks, int meals)
{
	t_philo	*philos;

	if (forks == -1)
		return (NULL);
	philos = malloc(forks * sizeof(t_philo));
	if (!philos)
		return (NULL);
	ft_start_philos(forks, meals, philos);
	return (philos);
}

void	ft_clean_philos(t_philo *philos)
{
	if (!philos)
		return ;
	free(philos);
}

void	ft_print_philo_state(t_philo *philo)
{
	char	*id;
	char	*tracker;

	pthread_mutex_lock(&(philo->table->mtx));
	id = ft_itoa(philo->id + 1);
	tracker = ft_itoa(philo->live_time.tv_usec / 1000);
	ft_putstr_fd("[Philosopher ", STDOUT_FILENO);
	ft_putstr_fd(id, STDOUT_FILENO);
	ft_putstr_fd("](", STDOUT_FILENO);
	ft_putstr_fd(tracker, STDOUT_FILENO);
	ft_putstr_fd("ms) ", STDOUT_FILENO);
	if (philo->status == NEUTRAL)
		ft_putstr_fd("😐 Neutral\n", STDOUT_FILENO);
	else if (philo->status = THINK)
		ft_putstr_fd("🤔 Thinking\n", STDOUT_FILENO);
	else if (philo->status = SLEEP)
		ft_putstr_fd("😴 Sleeping\n", STDOUT_FILENO);
	else if (philo->status == DEAD)
		ft_putstr_fd("💀 Dead\n", STDOUT_FILENO);
	pthread_mutex_unlock($(philo->table->mtx));
	free(id);
	free(tracker);
}

static void	ft_start_philos(int forks, int meals, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < forks)
	{
		(philos + i)->id = i;
		(philos + i)->meals = meals;
		(philos + i)->left_fork = TRUE;
		(philos + i)->rigth_fork = FALSE;
		(philos + i)->status = NEUTRAL;
		i++;
	}
}
