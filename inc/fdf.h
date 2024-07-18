/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:11:43 by mjakowic          #+#    #+#             */
/*   Updated: 2024/06/20 18:27:16 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// GNL
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// WINDOW
# ifndef WIN_H
#  define WIN_H 1080
# endif
# ifndef WIN_W
#  define WIN_W 1920
# endif

// MOVE MAP
# ifndef SHIFT
#  define SHIFT 10
# endif
# ifndef ROT_SHIFT
#  define ROT_SHIFT 0.1
# endif
# ifndef ZOOM_SHIFT
#  define ZOOM_SHIFT 1
# endif

// ERROR
# define MAL_ERROR "Memory allocation failed"

// COLORS
# define WHITE 0xFFFFFF

# ifndef COLOR_1
#  define COLOR_1 0x900C3F
# endif
# ifndef COLOR_2
#  define COLOR_2 0xC70039
# endif
# ifndef COLOR_3
#  define COLOR_3 0xF94C10
# endif
# ifndef COLOR_4
#  define COLOR_4 0xFD8D14
# endif
# ifndef COLOR_5
#  define COLOR_5 0xF8DE22
# endif

// KEYS
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_W 119
# define KEY_S 115
# define KEY_Q 113
# define KEY_E 101
# define KEY_A 97
# define KEY_D 100
# define KEY_P 112
# define KEY_MINUS 45
# define KEY_PLUS 61
# define KEY_R 114

// MOSUE
# define M_LEFT 1
# define M_UP 4
# define M_DOWN 5

// LIBS
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <unistd.h>

// STRUCTS
typedef struct s_map
{
	int		wid;
	int		hei;
	int		**z_mt;
	int		**color;
	int		iscolor;
	int		min_z;
	int		max_z;
}			t_map;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_l;
	int		end;
}			t_image;

typedef struct s_view
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_image	*img;
	int		shift_x;
	int		shift_y;
	float	zoom;
	int		iso;
	float	flat;
	float	rot_x;
	float	rot_y;
	float	rot_z;
	int		mouse_down;
	int		mouse_button;
	int		prev_x;
	int		prev_y;
}			t_view;

typedef struct s_spot
{
	int		x;
	int		y;
	int		z;
	int		color;
}			t_spot;

typedef struct s_menu
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*img_data;
	int		bpp;
	int		size_line;
	int		endian;
	int		y;
	int		bg_color;
	int		text_color;
}			t_menu;

// FUNCTIONS
void		free_split(char **split);
void		free_vr(t_view *vr);
void		free_all(t_view *vr);
t_spot		n_spot(int x, int y, t_view *vr);
t_spot		get_coords(t_view *vr, t_spot point);

void		error_quit(const char *err, const char *msg);
void		perror_quit(const char *str);

void		get_limit_z(t_map *map);
void		free_map(t_map *tab);
void		alloc_map(t_map *map);
t_map		*init_map(char *file);

void		handle_arg(t_map **map, int ac, char **av);

int			action(t_map *map);

int			close_win(t_view *vr);
int			key_hook(int keycode, t_view *vr);

int			update(t_view *vr);

void		draw_menu(t_view *vr);
void		reset_view(t_view *vr);
int			init_vr(t_view *vr, t_map *map);
void		init_mlx(t_view *vr);

void		draw(t_view *vr);

void		view_3d(t_view *vr, int *x, int *y, int z);
void		rot_x(t_view *vr, int *y, int *z);
void		rot_y(t_view *vr, int *x, int *z);
void		rot_z(t_view *vr, int *x, int *y);
void		img_pixel_put(t_view *vr, int x, int y, int color);

void		h_rot(int keycode, t_view *vr);
void		h_flatner(int keycode, t_view *vr);

int			mouse_release(int button, int x, int y, t_view *vr);
int			mouse_press(int button, int x, int y, t_view *vr);
int			mouse_move(int x, int y, t_view *vr);

int			get_color(t_spot current, t_spot start, t_spot end, t_spot delta);
int			get_z_color(t_view *vr, int cur_z);
int			main(int ac, char **av);

#endif
