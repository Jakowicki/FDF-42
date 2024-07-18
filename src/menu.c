/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:47:28 by mjakowic          #+#    #+#             */
/*   Updated: 2024/06/20 17:47:05 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	init_menu(t_menu *menu, t_view *vr, int wid, int hei)
{
	menu->mlx = vr->mlx;
	menu->win = vr->win;
	menu->bg_color = 0x750E21;
	menu->text_color = 0xFFFFFF;
	menu->y = 0;
	menu->img = mlx_new_image(menu->mlx, wid, hei);
	menu->img_data = (int *)mlx_get_data_addr(menu->img, &menu->bpp,
			&menu->size_line, &menu->endian);
	ft_memset(menu->img_data, menu->bg_color, wid * hei * sizeof(int));
}

static void	display_controls(t_menu *menu)
{
	mlx_string_put(menu->mlx, menu->win, 70, menu->y += 40, menu->text_color,
		"_______FDF_______");
	mlx_string_put(menu->mlx, menu->win, 70, menu->y += 15, menu->text_color,
		"Made by mjakowic");
	menu->y += 60;
	mlx_string_put(menu->mlx, menu->win, 75, menu->y, menu->text_color,
		"Controls");
	menu->y += 20;
	mlx_string_put(menu->mlx, menu->win, 15, menu->y += 15, menu->text_color,
		"Reset -->             R");
	mlx_string_put(menu->mlx, menu->win, 15, menu->y += 15, menu->text_color,
		"Move -->              Left Click");
	mlx_string_put(menu->mlx, menu->win, 15, menu->y += 15, menu->text_color,
		"Zoom -->              Scroll");
	mlx_string_put(menu->mlx, menu->win, 15, menu->y += 15, menu->text_color,
		"Flattening -->        + / -");
	menu->y += 40;
}

static void	display_rotation(t_menu *menu)
{
	mlx_string_put(menu->mlx, menu->win, 75, menu->y, menu->text_color,
		"Rotation");
	menu->y += 20;
	mlx_string_put(menu->mlx, menu->win, 15, menu->y += 15, menu->text_color,
		"  x (+ / -) -->       W / S");
	mlx_string_put(menu->mlx, menu->win, 15, menu->y += 15, menu->text_color,
		"  y (+ / -) -->       A / D");
	mlx_string_put(menu->mlx, menu->win, 15, menu->y += 15, menu->text_color,
		"  z (+ / -) -->       Q / E");
	menu->y += 40;
}

static void	display_perspective(t_menu *menu)
{
	mlx_string_put(menu->mlx, menu->win, 75, menu->y, menu->text_color,
		"Perspective");
	menu->y += 20;
	mlx_string_put(menu->mlx, menu->win, 15, menu->y += 15, menu->text_color,
		"Perspective -->       P");
	mlx_string_put(menu->mlx, menu->win, 15, menu->y += 15, menu->text_color,
		"(Isometric and Parallel)");
}

void	draw_menu(t_view *vr)
{
	t_menu	menu;
	int		width;
	int		height;

	width = 250;
	height = WIN_H;
	init_menu(&menu, vr, width, height);
	mlx_put_image_to_window(menu.mlx, menu.win, menu.img, 0, 0);
	display_controls(&menu);
	display_rotation(&menu);
	display_perspective(&menu);
	mlx_destroy_image(menu.mlx, menu.img);
}
