/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <ysaroyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:15:43 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/04/01 18:08:39 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		get_ms(void);
int		is_valid(char *num);
int		ft_atoi(const char *nptr);
int		check_death(t_rules *rules);
int		ft_strcmp(char *s1, char *s2);
int		is_valid_args(int argc, char **argv);
int		clean_up(t_rules *rules, t_philo *philos, pthread_t *threads);
void	release_forks(t_philo *philo);
void	update_last_meal(t_philo *philo);
void	print_message(t_philo *philo, char *msg);
void	free_structs(t_rules *rules, pthread_t *threads,
			pthread_mutex_t *forks);
void	creat_philo(t_philo *philo, t_rules *rules, int i);
t_rules	*creat_rules(char **argv);

#endif
