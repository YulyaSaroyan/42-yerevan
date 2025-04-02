/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <ysaroyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:05:08 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/04/01 18:05:34 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_structs(t_rules *rules, pthread_t *threads,
	pthread_mutex_t *forks)
{
	free(threads);
	free(forks);
	free(rules);
}

int	clean_up(t_rules *rules, t_philo *philos, pthread_t *threads)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&rules->print_mutex);
	pthread_mutex_destroy(&rules->death_mutex);
	while (++i < rules->num_of_philos)
	{
		pthread_mutex_destroy(&rules->forks[i]);
		pthread_mutex_destroy(&philos[i].meal_mutex);
	}
	free_structs(rules, threads, rules->forks);
	return (0);
}

void	creat_philo(t_philo *philo, t_rules *rules, int i)
{
	philo->id = i + 1;
	philo->rules = rules;
	philo->left_fork = &rules->forks[i];
	philo->right_fork = &rules->forks[(i + 1) % rules->num_of_philos];
	philo->last_meal = rules->start_ms;
	philo->eat_count = 0;
}
