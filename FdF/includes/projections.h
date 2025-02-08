/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:45:49 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/05 17:13:18 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTIONS_H
# define PROJECTIONS_H

void	isometric(t_point point, t_isopoint *isopoint, t_map map);
void	perspective(t_point point, t_isopoint *isopoint, t_map map);
void	parallel(t_point point, t_isopoint *isopoint, t_map map);

#endif
