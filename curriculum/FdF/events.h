/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:46:30 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/11 16:21:55 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

enum e_keys
{
	PLUS_KEY = 69,
	MINUS_KEY = 78,
	UP_KEY = 126,
	DOWN_KEY = 125,
	LEFT_KEY = 123,
	RIGHT_KEY = 124,
	W_KEY = 13,
	S_KEY = 1,
	A_KEY = 0,
	D_KEY = 2,
	E_KEY = 14,
	Q_KEY = 12,
	ESC_KEY = 53,
	ONE_KEY = 18,
	TWO_KEY = 19
};

enum e_buttons
{
	LEFT_BUTTON = 1,
	RIGHT_BUTTON = 2,
	MIDDLE_BUTTON = 3,
	SCROLL_UP = 4,
	SCROLL_DOWN = 5	
};

enum e_events
{
	ON_MOUSECLICK = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_DESTROY = 17
};

int	handle_key(int key, void *param);
int	handle_mouse(int button, int x, int y, void *param);
int	close_window(void *param);
int	handle_mouse_press(int button, int x, int y, void *param);
int	handle_mouse_release(int button, int x, int y, void *param);
int	handle_mouse_move(int x, int y, void *param);

#endif
