/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:37:30 by mjakowic          #+#    #+#             */
/*   Updated: 2024/06/19 21:09:01 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int ac, char **av)
{
	t_map	*map;

	map = NULL;
	handle_arg(&map, ac, av);
	action(map);
	return (0);
}
