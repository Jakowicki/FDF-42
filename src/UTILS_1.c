/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UTILS_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:39:05 by mjakowic          #+#    #+#             */
/*   Updated: 2024/06/20 17:47:19 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	get_limit_z(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->hei)
	{
		x = -1;
		while (++x < map->wid)
		{
			if (map->z_mt[y][x] < map->min_z)
				map->min_z = map->z_mt[y][x];
			else if (map->z_mt[y][x] > map->max_z)
				map->max_z = map->z_mt[y][x];
		}
	}
}

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->z_mt)
	{
		i = -1;
		while (++i < map->hei)
		{
			if (map->z_mt[i])
				free(map->z_mt[i]);
		}
		free(map->z_mt);
	}
	if (map->color)
	{
		i = -1;
		while (++i < map->hei)
		{
			if (map->color[i])
				free(map->color[i]);
		}
		free(map->color);
	}
	free(map);
}

void	alloc_map(t_map *map)
{
	int	i;

	map->z_mt = (int **)malloc(sizeof(int *) * map->hei);
	map->color = (int **)malloc(sizeof(int *) * map->hei);
	if (!map->z_mt || !map->color)
	{
		free_map(map);
		error_quit("Error", MAL_ERROR);
	}
	i = -1;
	while (++i < map->hei)
	{
		map->z_mt[i] = (int *)malloc(sizeof(int) * map->wid);
		map->color[i] = (int *)malloc(sizeof(int) * map->wid);
		if (!map->z_mt[i] || !map->color[i])
		{
			free_map(map);
			error_quit("Error", MAL_ERROR);
		}
	}
}

static int	count_num(t_map *map, char *line, char *file)
{
	int		count;
	char	**split;

	if (!line)
	{
		free_map(map);
		error_quit(file, "Empty Map");
	}
	split = ft_split(line, ' ');
	if (!split)
	{
		free_map(map);
		error_quit("Error", MAL_ERROR);
	}
	count = 0;
	while (split[count])
		count++;
	free_split(split);
	return (count);
}

t_map	*init_map(char *file)
{
	int		fd;
	t_map	*map;
	char	*line;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(map);
		perror_quit(file);
	}
	line = get_next_line(fd);
	map->wid = count_num(map, line, file);
	while (line)
	{
		map->hei++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}
