/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <ysaroyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:51:46 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/04/01 16:56:54 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philo *philo, char *msg)
{
	long	now;

	pthread_mutex_lock(&philo->rules->print_mutex);
	now = get_ms() - philo->rules->start_ms;
	if (!philo->rules->someone_died || ft_strcmp(msg, "died") == 0)
		printf("%ld %d %s\n", now, philo->id, msg);
	pthread_mutex_unlock(&philo->rules->print_mutex);
}

int	check_death(t_rules *rules)
{
	int	ret;

	pthread_mutex_lock(&rules->death_mutex);
	ret = rules->someone_died;
	pthread_mutex_unlock(&rules->death_mutex);
	return (ret);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	update_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_ms();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->meal_mutex);
}

t_rules	*creat_rules(char **argv)
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
