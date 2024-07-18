/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:19:11 by mjakowic          #+#    #+#             */
/*   Updated: 2024/06/18 12:02:08 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (!distance)
		return (1.0);
	return (placement / distance);
}

static int	get_light(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

int	get_color(t_spot current, t_spot start, t_spot end, t_spot delta)
{
	int		r;
	int		g;
	int		b;
	double	perc;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		perc = percent(start.x, end.x, current.x);
	else
		perc = percent(start.y, end.y, current.y);
	r = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF,
			perc);
	g = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF,
			perc);
	b = get_light(start.color & 0xFF, end.color & 0xFF, perc);
	return ((r << 16) | (g << 8) | b);
}

int	get_z_color(t_view *vr, int cur_z)
{
	double	perc;

	perc = percent(vr->map->min_z, vr->map->max_z, cur_z);
	if (perc < 0.2)
		return (COLOR_1);
	else if (perc < 0.4)
		return (COLOR_2);
	else if (perc < 0.6)
		return (COLOR_3);
	else if (perc < 0.8)
		return (COLOR_4);
	else
		return (COLOR_5);
}
