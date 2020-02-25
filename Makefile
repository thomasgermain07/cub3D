# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 08:26:20 by thgermai          #+#    #+#              #
#    Updated: 2020/02/25 19:23:09 by thgermai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SRCSDIR = srcs
OBJSDIR = .objs
SRCS = check_outline_utils.c\
		check_map.c\
		bmp_image.c\
		check_outline.c\
		main.c\
		get_map.c\
		get_texture.c\
		parsing_utiles.c\
		parsing.c\
		open_window.c\
		moving.c\
		raycasting_utiles.c\
		rotating.c\
		sprite_utiles.c\
		raycasting_calcul.c\
		raycasting.c\
		utiles.c\
		sprite.c\
		verify_map.c
OBJS = $(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))
DPDCS = $(OBJS:.o=.d)
INCLUDES = -I includes/ -I libft/
LIB = -Llibft -lft
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit
LOGFILE = $(LOGPATH) `date +'%y.%m.%d %H:%M:%S'`
MSG = ---


opti :
	@(make -j all)

all : $(NAME)

-include $(DPDCS)

$(NAME) : $(LIB) $(OBJS)
	@(gcc $(MLX) $(CFLAGS) $(OBJS) $(LIB) $(INCLUDES) -o $(NAME))
	@(echo "cub3D created")

$(LIB) :
	@(make all -C libft)

$(OBJSDIR)/%.o : $(SRCSDIR)/%.c | $(OBJSDIR)
	@(echo "Compiling -> $^")
	@(gcc $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@)

$(OBJSDIR) :
	@(mkdir -p .objs)

clean :
	@(rm -f $(NAME))
	@(rm -f image.bmp)
	@(rm -rf cub3d.dSYM)

fclean : clean
	@(rm -rf $(OBJSDIR))

git : fclean
	@(make fclean -C libft)
	@(git add *)
	@(git commit -m "$(LOGFILE) : $(MSG)")
	@(git push)

re : fclean all
