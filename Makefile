# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 08:26:20 by thgermai          #+#    #+#              #
#    Updated: 2020/01/10 16:22:46 by thgermai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
SRCS = ./srcs/main.c\
		./srcs/utiles.c\
		./srcs/parsing.c\
		./srcs/get_map.c\
		./srcs/check_map.c\
		./srcs/verify_map.c
INCLUDES = ./includes/cub3d.h
LIB = ./libft/libft.a
CFLAGS = -Wall -Wextra -Werror
LOGFILE=$(LOGPATH) `date +'%y.%m.%d %H:%M:%S'`

all : $(NAME)

$(NAME) :
	@(gcc $(CFLAGS) $(SRCS) $(LIB) -I $(INCLUDES) -o $(NAME))
	@(echo "")
	@(./$(NAME) map.cub)

f : $(OBJS)
	@(gcc $(CFLAGS) -g3 -fsanitize=address $(SRCS) $(LIB) -I $(INCLUDES) -o $(NAME))
	@(./$(NAME) map.cub)

clean :
	@(rm -f $(NAME))
	@(rm -rf cub3d.dSYM)

fclean : clean


git : fclean
	git add *
	git commit -m "$(LOGFILE)"
	git push

re : fclean all
