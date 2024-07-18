/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:35:55 by mjakowic          #+#    #+#             */
/*   Updated: 2024/06/20 17:48:00 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	char_tolower(unsigned int index, char *c)
{
	(void)index;
	*c = ft_tolower(*c);
}

static int	parse_color(t_map *map, char *s)
{
	while (*s && (ft_isdigit(*s) || *s == '-' || *s == '+' || *s == ','))
		s++;
	if (*s && *s == 'x')
	{
		map->iscolor = 1;
		ft_striteri(s + 1, char_tolower);
		return (ft_atoi_base(s + 1, 16));
	}
	else
		return (WHITE);
	return (0);
}

static void	matrix(t_map *map, int fd)
{
	int		x;
	int		y;
	char	*line;
	char	**split;

	y = -1;
	while (++y < map->hei)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		if (!split)
		{
			free(line);
			free_map(map);
			error_quit("Error", MAL_ERROR);
		}
		x = -1;
		while (++x < map->wid)
		{
			map->z_mt[y][x] = ft_atoi(split[x]);
			map->color[y][x] = parse_color(map, split[x]);
		}
		free_split(split);
		free(line);
	}
}

static void	parse_file(t_map *map, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free_map(map);
		perror_quit(file);
	}
	matrix(map, fd);
	close(fd);
}

void	handle_arg(t_map **map, int ac, char **av)
{
	char	*file;

	if (ac != 2)
		error_quit("ERROR 😭 ", "Invalid Arguments");
	ft_printf("Reading map...\n");
	file = av[1];
	*map = init_map(file);
	alloc_map(*map);
	parse_file(*map, file);
	get_limit_z(*map);
}
