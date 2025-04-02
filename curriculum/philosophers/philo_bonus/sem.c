/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <ysaroyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:21:25 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/04/01 15:16:25 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	unlink_sems(void)
{
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/death");
	sem_unlink("/all_ate");
}

void	close_sems(t_philo *philo)
{
	sem_close(philo->forks_sem);
	sem_close(philo->print_sem);
	sem_close(philo->death_sem);
	sem_close(philo->all_ate_sem);
}

void	open_sems(t_philo *philo)
{
	philo->forks_sem = sem_open("/forks", O_CREAT, 0644,
			philo->rules->num_of_philos);
	philo->print_sem = sem_open("/print", O_CREAT, 0644, 1);
	philo->death_sem = sem_open("/death", O_CREAT, 0644, 0);
	philo->all_ate_sem = sem_open("/all_ate", O_CREAT, 0644, 0);
}

void	init_sems(t_philo *philo)
{
	unlink_sems();
	open_sems(philo);
}

void	close_term_sem(sem_t *term_sem)
{
	sem_close(term_sem);
	sem_unlink("/termination");
}
