/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <ysaroyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:10:01 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/04/01 18:12:57 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(1000);
	pthread_mutex_lock(philo->left_fork);
	print_message(philo, "has taken a fork");
	if (check_death(philo->rules))
		return (pthread_mutex_unlock(philo->left_fork), 0);
	if (philo->rules->num_of_philos == 1)
		return (pthread_mutex_unlock(philo->left_fork), 0);
	pthread_mutex_lock(philo->right_fork);
	print_message(philo, "has taken a fork");
	if (check_death(philo->rules))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	return (1);
}

static void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (!check_death(philo->rules))
	{
		print_message(philo, "is thinking");
		if (!take_forks(philo))
			break ;
		print_message(philo, "is eating");
		update_last_meal(philo);
		usleep(philo->rules->time_to_eat * 1000);
		release_forks(philo);
		print_message(philo, "is sleeping");
		usleep(philo->rules->time_to_sleep * 1000);
	}
	return (NULL);
}

int	init_philos_and_forks(t_rules *rules, pthread_t *threads,
	pthread_mutex_t *forks, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < rules->num_of_philos)
		pthread_mutex_init(&forks[i], NULL);
	rules->forks = forks;
	rules->start_ms = get_ms();
	rules->someone_died = 0;
	i = -1;
	while (++i < rules->num_of_philos)
	{
		creat_philo(&philos[i], rules, i);
		pthread_mutex_init(&philos[i].meal_mutex, NULL);
	}
	i = -1;
	while (++i < rules->num_of_philos)
	{
		if (pthread_create(&threads[i], NULL, &routine, &philos[i]) != 0)
			return (free_structs(rules, threads, forks), 0);
	}
	return (1);
}

int	wait_for_threads(t_rules *rules, pthread_t *threads,
	pthread_mutex_t *forks, t_philo *philos)
{
	pthread_t			monitor;
	t_rules_and_philos	general;
	int					i;

	general.philos = philos;
	general.rules = rules;
	if (pthread_create(&monitor, NULL, &monitor_routine, &general) != 0)
		return (clean_up(rules, philos, threads));
	if (pthread_join(monitor, NULL) != 0)
		return (clean_up(rules, philos, threads));
	i = -1;
	while (++i < rules->num_of_philos)
		if (pthread_join(threads[i], NULL) != 0)
			return (pthread_mutex_destroy(&forks[i]),
				free_structs(rules, threads, forks), 0);
	return (1);
}

int	create_threads_mutexes(t_rules *rules, pthread_t *threads,
	pthread_mutex_t *forks, t_philo *philos)
{
	pthread_mutex_init(&rules->print_mutex, NULL);
	pthread_mutex_init(&rules->death_mutex, NULL);
	if (!init_philos_and_forks(rules, threads, forks, philos))
		return (0);
	if (!wait_for_threads(rules, threads, forks, philos))
		return (0);
	return (1);
}
