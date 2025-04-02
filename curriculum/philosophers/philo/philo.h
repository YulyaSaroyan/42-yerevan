/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <ysaroyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:16:35 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/04/01 18:12:02 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include "struct.h"
# include "utils.h"

void	*monitor_routine(void *args);
int		init_philos_and_forks(t_rules *rules, pthread_t *threads,
			pthread_mutex_t *forks, t_philo *philos);
int		wait_for_threads(t_rules *rules, pthread_t *threads,
			pthread_mutex_t *forks, t_philo *philos);
int		create_threads_mutexes(t_rules *rules, pthread_t *threads,
			pthread_mutex_t *forks, t_philo *philos);
#endif
