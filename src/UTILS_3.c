/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UTILS_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:45:13 by mjakowic          #+#    #+#             */
/*   Updated: 2024/06/20 17:51:23 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	reset_view(t_view *vr)
{
	vr->zoom = ft_max((WIN_W / vr->map->wid / 2), (WIN_H / vr->map->hei / 2));
	vr->shift_x = WIN_W / 2 + 50;
	vr->shift_y = WIN_H / 2 - 50;
	vr->iso = 1;
	vr->flat = 1;
	vr->rot_x = 0;
	vr->rot_y = 0;
	vr->rot_z = 0;
}

int	init_vr(t_view *vr, t_map *map)
{
	vr->mouse_down = 0;
	vr->map = map;
	vr->img = (t_image *)malloc(sizeof(t_image));
	if (!vr->img)
		return (1);
	reset_view(vr);
	return (0);
}

void	init_mlx(t_view *vr)
{
	vr->mlx = mlx_init();
	vr->img->img = mlx_new_image(vr->mlx, WIN_W, WIN_H);
	vr->img->addr = mlx_get_data_addr(vr->img->img, &vr->img->bpp,
			&vr->img->size_l, &vr->img->end);
	vr->win = mlx_new_window(vr->mlx, WIN_W, WIN_H, "///FDF///");
}
