# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/30 08:42:51 by clkuznie          #+#    #+#              #
#    Updated: 2020/09/10 19:43:25 by clkuznie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=  minirt

SRCS			:= \
arg_reading.c\
clean_space.c\
error_handler.c\
inits.c\
main.c\
testing_prints.c\
utils.c

PARSE			:= \
ambiant_parse.c\
camera_parse.c\
color_parse.c\
double_parse_inrange.c\
light_parse.c\
parse_redirect.c\
position_parse.c\
resolution_parse.c\
sphere_parse.c\
vector_parse.c

PARSE_FILES		:= \
$(addprefix parse/, $(PARSE))

FILES			:= \
$(addprefix srcs/, $(SRCS))\
$(addprefix srcs/, $(PARSE_FILES))

OBJS			= $(FILES:%.c=%.o)

INCLUDES		= \
-I includes/libmlx\
-I includes/libmlx/X11\
-I includes\
-I includes/libft

LIB_SRCS		= \
includes/libft/libft.a\
includes/libmlx/libmlx.a

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
MLX_LINKS		= -lm -lbsd -lX11 -lXext

RM				= rm -f

all:			$(NAME)

$(NAME):		libcomp $(OBJS)
	@echo "\n\033[0;33mCompiling..."
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIB_SRCS) $(MLX_LINKS)

%.o:			%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ -g

libcomp:
	@echo "\n\033[0;33mLib_Compiling..."
	make -C includes/libft
	make -C includes/libmlx

clean:			cleanlib
	$(RM) $(OBJS)

fclean:			fcleanlib
	$(RM) $(OBJS)
	$(RM) $(NAME)

cleanlib:
	make --directory=includes/libft clean
	make --directory=includes/libmlx clean

fcleanlib:
	make --directory=includes/libft fclean
	make --directory=includes/libmlx clean

norme:
	norminette *.c *.h

re:				fclean all

.PHONY: all clean bonus norme re libcomp cleanlib fcleanlib
