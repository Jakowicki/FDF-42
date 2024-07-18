/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:43:41 by mjakowic          #+#    #+#             */
/*   Updated: 2024/06/20 17:51:55 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	action(t_map *map)
{
	t_view	vr;

	ft_printf("Starting FDF...\n");
	if (init_vr(&vr, map))
	{
		free_all(&vr);
		error_quit("ERROR 😭", MAL_ERROR);
	}
	init_mlx(&vr);
	mlx_hook(vr.win, 2, 1L << 0, key_hook, &vr);
	mlx_hook(vr.win, 17, 1L << 17, close_win, &vr);
	mlx_hook(vr.win, 4, 1L << 2, mouse_press, &vr);
	mlx_hook(vr.win, 5, 1L << 3, mouse_release, &vr);
	mlx_hook(vr.win, 6, 1L << 6, mouse_move, &vr);
	draw(&vr);
	mlx_loop(vr.mlx);
	return (EXIT_SUCCESS);
}
