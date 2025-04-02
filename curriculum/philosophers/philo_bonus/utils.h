/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <ysaroyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:15:43 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/04/01 15:16:43 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		ft_atoi(const char *nptr);
int		get_ms(void);
int		is_valid_args(int argc, char **argv);
int		ft_strcmp(char *s1, char *s2);
int		ft_isdigit(int ch);
void	clean_up(t_philo *philo, pid_t *pids);
void	print_message(t_philo *philo, char *msg);
t_rules	*create_rules(char **argv);
void	unlink_sems(void);
void	close_sems(t_philo *philo);
void	open_sems(t_philo *philo);
void	init_sems(t_philo *philo);
void	close_term_sem(sem_t *term_sem);

#endif
