/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <ysaroyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:17:39 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/04/01 18:32:25 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(1000);
	sem_wait(philo->forks_sem);
	print_message(philo, "has taken a fork");
	sem_wait(philo->forks_sem);
	print_message(philo, "has taken a fork");
	print_message(philo, "is eating");
	philo->last_meal = get_ms();
	usleep(philo->rules->time_to_eat * 1000);
	sem_post(philo->forks_sem);
	sem_post(philo->forks_sem);
}

void	routine(t_philo *philo, pid_t *pids)
{
	pthread_t	thread;
	int			eat_count;

	philo->last_meal = get_ms();
	if (pthread_create(&thread, NULL, monitor_death, philo) != 0)
		return (clean_up(philo, pids));
	if (pthread_detach(thread) != 0)
		return (clean_up(philo, pids));
	eat_count = 0;
	while (1)
	{
		print_message(philo, "is thinking");
		take_forks(philo);
		eat_count++;
		if (philo->rules->must_eat != -1 && eat_count >= philo->rules->must_eat)
		{
			sem_post(philo->all_ate_sem);
			clean_up(philo, pids);
			exit(0);
		}
		print_message(philo, "is sleeping");
		usleep(philo->rules->time_to_sleep * 1000);
	}
	clean_up(philo, pids);
}

pid_t	*create_philos(t_philo *philo)
{
	pid_t	*pids;
	int		i;

	pids = malloc(philo->rules->num_of_philos * sizeof(pid_t));
	if (!pids)
	{
		free(philo->rules);
		return (NULL);
	}
	init_sems(philo);
	i = -1;
	while (++i < philo->rules->num_of_philos)
	{
		pids[i] = fork();
		if (pids[i] == -1)
			return (clean_up(philo, pids), NULL);
		if (pids[i] == 0)
		{
			philo->id = i;
			routine(philo, pids);
		}
	}
	return (pids);
}

int	main(int argc, char **argv)
{
	t_philo	philo;
	t_rules	*rules;
	pid_t	*pids;
	int		i;

	if (!is_valid_args(argc, argv))
		return (write(2, "Wrong usage\n", 12), 1);
	rules = create_rules(argv);
	if (!rules)
		return (1);
	rules->start_ms = get_ms();
	philo.rules = rules;
	pids = create_philos(&philo);
	if (!pids)
		return (0);
	monitor(pids, &philo);
	i = -1;
	while (++i < rules->num_of_philos)
		waitpid(pids[i], NULL, 0);
	clean_up(&philo, pids);
	return (0);
}
