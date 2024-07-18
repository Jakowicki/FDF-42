# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 19:07:40 by mjakowic          #+#    #+#              #
#    Updated: 2024/05/30 19:18:16 by mjakowic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = clang
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I inc
LIBFT = lib/libft/libft.a
FT_PRINTF = lib/ft_printf/libftprintf.a
MINILIBX = lib/minilibx-linux/libmlx.a
LIBS = $(LIBFT) $(FT_PRINTF) $(MINILIBX) -lm -lX11 -lXext -g
SRCS = src/action.c src/control.c src/draw.c src/error.c src/fdf.c src/handle_arg.c src/hooks.c\
       src/menu.c src/mouse_hooks.c src/rgb_set.c src/UTILS_0.c src/UTILS_1.c src/UTILS_2.c src/UTILS_3.c
OBJS = $(SRCS:.c=.o)

MINILIBX_REPO = https://github.com/42Paris/minilibx-linux.git
MINILIBX_DIR = lib/minilibx-linux

all: $(MINILIBX_DIR) $(NAME)

$(MINILIBX_DIR):
	@if [ ! -d "$(MINILIBX_DIR)" ]; then \
		git clone $(MINILIBX_REPO) $(MINILIBX_DIR); \
	fi
	make -C $(MINILIBX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF) $(MINILIBX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(INCLUDES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(LIBFT):
	make -C lib/libft

$(FT_PRINTF):
	make -C lib/ft_printf

clean:
	make -C lib/libft clean
	make -C lib/ft_printf clean
	make -C $(MINILIBX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C lib/libft fclean
	make -C lib/ft_printf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


