/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <ysaroyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 19:42:36 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/04/01 18:32:38 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules				*rules;
	t_philo				*philos;
	pthread_t			*threads;
	pthread_mutex_t		*forks;

	if (!is_valid_args(argc, argv))
		return (write(2, "Wrong usage\n", 12), 1);
	rules = creat_rules(argv);
	if (!rules)
		return (0);
	threads = (pthread_t *)malloc(rules->num_of_philos * sizeof(pthread_t));
	if (!threads)
		return (free(rules), 0);
	forks = (pthread_mutex_t *)malloc(rules->num_of_philos
			* sizeof(pthread_mutex_t));
	if (!forks)
		return (free(threads), free(rules), 0);
	philos = (t_philo *)malloc(rules->num_of_philos * sizeof(t_philo));
	if (!philos)
		return (free_structs(rules, threads, forks), 0);
	if (!create_threads_mutexes(rules, threads, forks, philos))
		return (0);
	return (clean_up(rules, philos, threads), free(philos), 0);
}
