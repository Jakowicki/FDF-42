/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UTILS_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:00:28 by mjakowic          #+#    #+#             */
/*   Updated: 2024/06/20 13:25:04 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	view_3d(t_view *vr, int *x, int *y, int z)
{
	int	pre_x;
	int	pre_y;

	if (!vr->iso)
		return ;
	pre_x = *x;
	pre_y = *y;
	*x = (pre_x - pre_y) * cos(0.523599);
	*y = -z + (pre_x + pre_y) * sin(0.523599);
}

void	rot_x(t_view *vr, int *y, int *z)
{
	float	pre_y;

	pre_y = *y;
	*y = (pre_y * cos(vr->rot_x)) + (*z * sin(vr->rot_x));
	*z = (-pre_y * sin(vr->rot_x)) + (*z * cos(vr->rot_x));
}

void	rot_y(t_view *vr, int *x, int *z)
{
	float	pre_x;

	pre_x = *x;
	*x = (*x * cos(vr->rot_y)) + (*z * sin(vr->rot_y));
	*z = (-pre_x * sin(vr->rot_y)) + (*z * cos(vr->rot_y));
}

void	rot_z(t_view *vr, int *x, int *y)
{
	float	pre_x;

	pre_x = *x;
	*x = (*x * cos(vr->rot_z)) - (*y * sin(vr->rot_z));
	*y = (pre_x * sin(vr->rot_z)) + (*y * cos(vr->rot_z));
}

void	img_pixel_put(t_view *vr, int x, int y, int color)
{
	int	pixel;

	if (y >= WIN_H || x >= WIN_W || y < 0 || x < 0)
		return ;
	pixel = (y * vr->img->size_l) + (x * (vr->img->bpp / 8));
	if (vr->img->end == 1)
	{
		vr->img->addr[pixel + 0] = (color >> 24);
		vr->img->addr[pixel + 1] = (color >> 16) & 0xFF;
		vr->img->addr[pixel + 2] = (color >> 8) & 0xFF;
		vr->img->addr[pixel + 3] = (color) & 0xFF;
	}
	else if (vr->img->end == 0)
	{
		vr->img->addr[pixel + 0] = (color) & 0xFF;
		vr->img->addr[pixel + 1] = (color >> 8) & 0xFF;
		vr->img->addr[pixel + 2] = (color >> 16) & 0xFF;
		vr->img->addr[pixel + 3] = (color >> 24);
	}
}
