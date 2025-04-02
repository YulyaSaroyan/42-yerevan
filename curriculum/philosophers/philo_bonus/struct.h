/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <ysaroyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:13:06 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/04/01 15:38:52 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "philo.h"

typedef struct s_rules
{
	int	num_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat;
	int	start_ms;
}	t_rules;

typedef struct s_philo
{
	int		id;
	int		last_meal;
	int		eat_count;
	int		*someone_died;
	sem_t	*forks_sem;
	sem_t	*print_sem;
	sem_t	*death_sem;
	sem_t	*all_ate_sem;
	t_rules	*rules;
}	t_philo;

typedef struct s_monitor_args
{
	int		num_philos;
	sem_t	*death_sem;
	sem_t	*all_ate_sem;
	sem_t	*termination_sem;
}	t_monitor_args;

typedef struct s_general
{
	t_philo	*philo;
	pid_t	*pids;
}	t_general;

#endif
