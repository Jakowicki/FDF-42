/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:42:26 by mjakowic          #+#    #+#             */
/*   Updated: 2024/06/20 17:51:32 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	close_win(t_view *vr)
{
	free_all(vr);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_hook(int keycode, t_view *vr)
{
	if (keycode == KEY_ESC)
		close_win(vr);
	if (keycode == KEY_R)
		reset_view(vr);
	if (keycode == KEY_Q || keycode == KEY_W || keycode == KEY_E
		|| keycode == KEY_A || keycode == KEY_S || keycode == KEY_D)
		h_rot(keycode, vr);
	if (keycode == KEY_MINUS || keycode == KEY_PLUS)
		h_flatner(keycode, vr);
	if (keycode == KEY_P)
	{
		if (vr->iso)
			vr->iso = 0;
		else
			vr->iso = 1;
	}
	draw(vr);
	return (0);
}
