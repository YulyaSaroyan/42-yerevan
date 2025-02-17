/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_calculations.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:35:50 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/12 18:35:26 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CALCULATIONS_H
# define MAP_CALCULATIONS_H

void	calculate_offsets(t_map *map);
void	init_map(t_map *map);
void	reset_map(t_map *map);
void	calculate_scale(t_map *map);
void	calculate_bounds(t_map *map);
void	calculate_iso_bounds(t_map *map, t_isopoint point);

#endif
