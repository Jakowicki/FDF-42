/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:50:13 by mjakowic          #+#    #+#             */
/*   Updated: 2024/06/18 12:02:35 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	h_flatner(int keycode, t_view *vr)
{
	if (keycode == KEY_PLUS)
	{
		if (vr->flat < 10)
			vr->flat += 0.1;
	}
	if (keycode == KEY_MINUS)
	{
		if (vr->flat > 0)
			vr->flat -= 0.1;
	}
}

void	h_rot(int keycode, t_view *vr)
{
	if (keycode == KEY_S)
		vr->rot_x += ROT_SHIFT;
	if (keycode == KEY_W)
		vr->rot_x -= ROT_SHIFT;
	if (keycode == KEY_D)
		vr->rot_y += ROT_SHIFT;
	if (keycode == KEY_A)
		vr->rot_y -= ROT_SHIFT;
	if (keycode == KEY_E)
		vr->rot_z += ROT_SHIFT;
	if (keycode == KEY_Q)
		vr->rot_z -= ROT_SHIFT;
}
