/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:07:52 by mjakowic          #+#    #+#             */
/*   Updated: 2024/06/18 18:05:47 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	ft_abs(int a)
{
	if (a < 0)
		return (-(a));
	return (a);
}

static void	init_bresenham(t_spot *start, t_spot *end, t_spot *delta,
		t_spot *sign)
{
	delta->x = ft_abs(end->x - start->x);
	delta->y = ft_abs(end->y - start->y);
	sign->x = -1;
	sign->y = -1;
	if (start->x < end->x)
		sign->x = 1;
	if (start->y < end->y)
		sign->y = 1;
}

static void	bresenham(t_view *vr, t_spot start, t_spot end)
{
	t_spot	cur;
	t_spot	sign;
	t_spot	delta;
	int		line;
	int		tmp;

	init_bresenham(&start, &end, &delta, &sign);
	line = delta.x - delta.y;
	cur = start;
	while (cur.x != end.x || cur.y != end.y)
	{
		img_pixel_put(vr, cur.x, cur.y, get_color(cur, start, end, delta));
		tmp = line * 2;
		if (tmp > -delta.y)
		{
			line -= delta.y;
			cur.x += sign.x;
		}
		if (tmp < delta.x)
		{
			line += delta.x;
			cur.y += sign.y;
		}
	}
}

void	draw(t_view *vr)
{
	int	x;
	int	y;

	ft_bzero(vr->img->addr, WIN_H * WIN_W * (vr->img->bpp / 8));
	if (vr->zoom)
	{
		y = -1;
		while (++y < vr->map->hei)
		{
			x = -1;
			while (++x < vr->map->wid)
			{
				if (x < vr->map->wid - 1)
					bresenham(vr, get_coords(vr, n_spot(x, y, vr)),
						get_coords(vr, n_spot(x + 1, y, vr)));
				if (y < vr->map->hei - 1)
					bresenham(vr, get_coords(vr, n_spot(x, y, vr)),
						get_coords(vr, n_spot(x, y + 1, vr)));
			}
		}
	}
	mlx_put_image_to_window(vr->mlx, vr->win, vr->img->img, 0, 0);
	draw_menu(vr);
}
