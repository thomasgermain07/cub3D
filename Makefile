# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 08:26:20 by thgermai          #+#    #+#              #
#    Updated: 2020/01/15 09:21:40 by thgermai         ###   ########.fr        #
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

all : $(NAME)

$(NAME) :
	@(gcc $(CFLAGS) $(MLX) $(SRCS) $(LIB) -I $(INCLUDES) -o $(NAME))
	@(echo "")
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
	git commit -m "$(LOGFILE)"
	git push

re : fclean all
