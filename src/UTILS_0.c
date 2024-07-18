/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UTILS_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:46:27 by mjakowic          #+#    #+#             */
/*   Updated: 2024/06/20 17:51:42 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

void	free_vr(t_view *vr)
{
	free(vr->img);
	free_map(vr->map);
	free(vr->mlx);
}

void	free_all(t_view *vr)
{
	mlx_destroy_image(vr->mlx, vr->img->img);
	mlx_destroy_window(vr->mlx, vr->win);
	mlx_destroy_display(vr->mlx);
	free_vr(vr);
}

t_spot	n_spot(int x, int y, t_view *vr)
{
	t_spot	out;

	out.x = x;
	out.y = y;
	out.z = vr->map->z_mt[y][x];
	if (vr->map->iscolor)
		out.color = vr->map->color[y][x];
	else
		out.color = get_z_color(vr, out.z);
	return (out);
}

t_spot	get_coords(t_view *vr, t_spot point)
{
	int	center_x;
	int	center_y;

	center_x = (vr->map->wid - 1) / 2;
	center_y = (vr->map->hei - 1) / 2;
	point.x -= center_x;
	point.y -= center_y;
	point.x *= vr->zoom;
	point.y *= vr->zoom;
	point.z *= (vr->zoom / 10) * vr->flat;
	rot_x(vr, &point.y, &point.z);
	rot_y(vr, &point.x, &point.z);
	rot_z(vr, &point.x, &point.y);
	view_3d(vr, &point.x, &point.y, point.z);
	point.x += center_x + vr->shift_x;
	point.y += center_y + vr->shift_y;
	return (point);
}
