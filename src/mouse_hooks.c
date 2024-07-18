/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:35:19 by mjakowic          #+#    #+#             */
/*   Updated: 2024/06/18 12:03:57 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	mouse_press(int button, int x, int y, t_view *vr)
{
	(void)x;
	(void)y;
	if (button == M_UP)
	{
		vr->zoom += ZOOM_SHIFT;
		draw(vr);
	}
	else if (button == M_DOWN)
	{
		vr->zoom -= ZOOM_SHIFT;
		draw(vr);
	}
	else
	{
		vr->mouse_down = 1;
		vr->mouse_button = button;
		vr->prev_x = x;
		vr->prev_y = y;
	}
	return (0);
}

int	mouse_release(int button, int x, int y, t_view *vr)
{
	(void)x;
	(void)y;
	(void)button;
	vr->mouse_down = 0;
	return (0);
}

int	mouse_move(int x, int y, t_view *vr)
{
	int	dx;
	int	dy;

	if (vr->mouse_down)
	{
		dx = x - vr->prev_x;
		dy = y - vr->prev_y;
		if (vr->mouse_button == M_LEFT)
		{
			vr->shift_x += dx;
			vr->shift_y += dy;
		}
		vr->prev_x = x;
		vr->prev_y = y;
		draw(vr);
	}
	return (0);
}
