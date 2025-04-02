/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <ysaroyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:58:00 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/04/01 18:03:17 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	monitor_death(t_rules_and_philos *general, int *all_ate)
{
	int	i;

	i = -1;
	while (++i < general->rules->num_of_philos)
	{
		pthread_mutex_lock(&general->philos[i].meal_mutex);
		if ((get_ms() - general->philos[i].last_meal)
			> general->rules->time_to_die)
		{
			pthread_mutex_unlock(&general->philos[i].meal_mutex);
			pthread_mutex_lock(&general->rules->death_mutex);
			if (!general->rules->someone_died)
			{
				general->rules->someone_died = 1;
				print_message(&general->philos[i], "died");
			}
			pthread_mutex_unlock(&general->rules->death_mutex);
			return (0);
		}
		if (general->rules->must_eat != -1
			&& general->philos[i].eat_count < general->rules->must_eat)
			*all_ate = 0;
		pthread_mutex_unlock(&general->philos[i].meal_mutex);
	}
	return (1);
}

void	*monitor_routine(void *args)
{
	t_rules_and_philos	*general;
	int					all_ate;

	general = (t_rules_and_philos *)args;
	while (!check_death(general->rules))
	{
		usleep(1000);
		all_ate = 1;
		if (!monitor_death(general, &all_ate))
			return (NULL);
		if (general->rules->must_eat != -1 && all_ate)
		{
			pthread_mutex_lock(&general->rules->death_mutex);
			general->rules->someone_died = 1;
			pthread_mutex_unlock(&general->rules->death_mutex);
			return (NULL);
		}
	}
	return (NULL);
}
