/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <ysaroyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:19:16 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/04/01 18:29:07 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*death_monitor(void *arg)
{
	t_monitor_args	*args;

	args = (t_monitor_args *)arg;
	sem_wait(args->death_sem);
	sem_post(args->termination_sem);
	return (NULL);
}

static void	*completion_monitor(void *arg)
{
	t_monitor_args	*args;
	int				i;

	args = (t_monitor_args *)arg;
	i = -1;
	while (++i < args->num_philos)
		sem_wait(args->all_ate_sem);
	sem_post(args->termination_sem);
	return (NULL);
}

void	monitor(pid_t *pids, t_philo *philo)
{
	sem_t			*termination_sem;
	pthread_t		death_thread;
	pthread_t		completion_thread;
	t_monitor_args	args;
	int				i;

	sem_unlink("/termination");
	termination_sem = sem_open("/termination", O_CREAT, 0644, 0);
	args.death_sem = philo->death_sem;
	args.all_ate_sem = philo->all_ate_sem;
	args.num_philos = philo->rules->num_of_philos;
	args.termination_sem = termination_sem;
	if (pthread_create(&death_thread, NULL, death_monitor, &args) != 0)
		return (close_term_sem(termination_sem), clean_up(philo, pids));
	if (pthread_create(&completion_thread, NULL,
			completion_monitor, &args) != 0)
		return (close_term_sem(termination_sem), clean_up(philo, pids));
	sem_wait(termination_sem);
	i = -1;
	while (++i < philo->rules->num_of_philos)
		kill(pids[i], SIGKILL);
	close_term_sem(termination_sem);
}

void	*monitor_death(void *arg)
{
	t_philo	*philo;
	int		time_since_last_meal;
	int		current_time;

	philo = (t_philo *)arg;
	while (1)
	{
		usleep(1000);
		current_time = get_ms();
		time_since_last_meal = current_time - philo->last_meal;
		if (time_since_last_meal > philo->rules->time_to_die)
		{
			sem_wait(philo->print_sem);
			printf("%d %d %s\n", current_time
				- philo->rules->start_ms, philo->id + 1, "died");
			sem_post(philo->death_sem);
			exit(0);
		}
	}
	return (NULL);
}
