/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <ysaroyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:36:14 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/03/31 20:02:33 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philo *philo, char *msg)
{
	sem_wait(philo->print_sem);
	printf("%d %d %s\n", get_ms() - philo->rules->start_ms, philo->id + 1, msg);
	sem_post(philo->print_sem);
}

t_rules	*create_rules(char **argv)
{
	t_rules	*rules;

	rules = (t_rules *)malloc(sizeof(t_rules));
	if (!rules)
		return (NULL);
	rules->num_of_philos = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	rules->must_eat = -1;
	if (argv[5])
		rules->must_eat = ft_atoi(argv[5]);
	return (rules);
}
