# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 08:26:20 by thgermai          #+#    #+#              #
#    Updated: 2020/01/25 16:50:53 by thgermai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
SRCS = ./srcs/*.c
INCLUDES = ./includes/cub3d.h
LIB = ./libft/libft.a
CFLAGS = -Wall -Wextra -Werror
DEBUG = -g3 -fsanitize=address
MLX = -lmlx -framework OpenGL -framework AppKit
LOGFILE = $(LOGPATH) `date +'%y.%m.%d %H:%M:%S'`
MAP = maps/map1.cub
MSG = ---

all : $(NAME)

$(NAME) :
	@(gcc $(MLX) $(CFLAGS) $(SRCS) $(LIB) -I $(INCLUDES) -o $(NAME))
	@(./$(NAME) $(MAP))

f : $(OBJS)
	@(gcc $(CFLAGS) $(MLX) $(DEBUG) $(SRCS) $(LIB) -I $(INCLUDES) -o $(NAME))
	@(./$(NAME) $(MAP))

clean :
	@(rm -f $(NAME))
	@(rm -rf cub3d.dSYM)

fclean : clean

git : fclean
	git add *
	git commit -m "$(LOGFILE) : $(MSG)"
	git push

re : fclean all
