/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:29:15 by mhidani           #+#    #+#             */
/*   Updated: 2025/12/03 00:09:44 by mhidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	ft_destroy_forks(pthread_mutex_t **forks, size_t size)
{
	size_t	i;

	if (!forks)
		return (FALSE);
	i = 0;
	while (i < size)
	{
		if (pthread_mutex_destroy(forks[i]) != 0)
			return (FALSE);
		free(forks[i]);
		i++;
	}
	free(forks);
	return (TRUE);
}

pthread_mutex_t	**ft_new_forks(t_dining_table *table)
{
	pthread_mutex_t	**forks;
	size_t			size;
	size_t			i;

	if (!table || table->number_of_philos <= 0)
		return (NULL);
	size = table->number_of_philos;
	forks = ft_calloc(size + 1, sizeof(pthread_mutex_t *));
	if (!forks)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (pthread_mutex_init(forks[i], NULL) != 0)
		{
			ft_destroy_forks(forks, size);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

void	ft_locate_forks_to_philo(t_philo *philo)
{
	int	left;
	int	right;

	if (!philo)
		return ;
	left = philo->id;
	right = philo->id - 1;
	if (right < 0)
		right = philo->table->number_of_philos - 1;
	philo->left_fork = philo->table->forks_mtx[left];
	philo->right_fork = philo->table->forks_mtx[right];
}
