/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:31:34 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/11 18:33:04 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		calculate_error(int dx, int dy);
void	calculate_step_direction(int start, int end, int *step);
void	throw_error(char *message);
void	allocate_points(t_map *map);

#endif
