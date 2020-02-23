# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 08:26:20 by thgermai          #+#    #+#              #
#    Updated: 2020/02/23 17:33:46 by thgermai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SRCS = ./srcs/check_outline_utils.c\
		./srcs/check_map.c\
		./srcs/bmp_image.c\
		./srcs/check_outline.c\
		./srcs/main.c\
		./srcs/get_map.c\
		./srcs/get_texture.c\
		./srcs/parsing_utiles.c\
		./srcs/parsing.c\
		./srcs/open_window.c\
		./srcs/moving.c\
		./srcs/raycasting_utiles.c\
		./srcs/rotating.c\
		./srcs/sprite_utiles.c\
		./srcs/raycasting_calcul.c\
		./srcs/raycasting.c\
		./srcs/utiles.c\
		./srcs/sprite.c\
		./srcs/verify_map.c
INCLUDES = ./includes/cub3d.h
LIB = ./libft/libft.a
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit
LOGFILE = $(LOGPATH) `date +'%y.%m.%d %H:%M:%S'`
MAP = maps/map1.cub
MSG = ---

all : $(NAME)

$(NAME) : $(LIB)
	@(gcc $(MLX) $(CFLAGS) $(SRCS) $(LIB) -I $(INCLUDES) -o $(NAME))
	@(echo "cub3D created")

$(LIB) :
	make -C libft
	make clean -C libft

clean :
	@(rm -f $(NAME))
	@(rm -f image.bmp)
	@(rm -rf cub3d.dSYM)

fclean : clean

git : fclean
	git add *
	git commit -m "$(LOGFILE) : $(MSG)"
	git push

re : fclean all
