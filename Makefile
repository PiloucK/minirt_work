# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/30 08:42:51 by clkuznie          #+#    #+#              #
#    Updated: 2020/11/14 14:22:44 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=  minirt

CHANGE			:= \
change_camera.c\
change_cylinder.c\
change_light.c\
change_nothing.c\
change_plane.c\
change_sphere.c\
change_square.c\
change_triangle.c\
rotate.c\
translate.c\
var_scale.c

COLOR			:= \
color_add.c\
color_mult.c\
color_sub.c

INTERSECT		:= \
intersect_cylinder.c\
intersect_nothing.c\
intersect_plane.c\
intersect_square.c\
intersect_sphere.c\
intersect_triangle.c\
set_bounce.c

MAIN			:= \
camera_switch.c\
clean_space.c\
error_handler.c\
fill_image.c\
key_hooked.c\
light_switch.c\
main.c\
mouse_hooked.c\
testing_prints.c\
utils.c

PARSE			:= \
ambiant_parse.c\
arg_reading.c\
camera_parse.c\
color_parse.c\
cylinder_parse.c\
double_parse_inrange.c\
light_parse.c\
parse_redirect.c\
plane_parse.c\
position_parse.c\
rafl_parse.c\
resolution_parse.c\
sphere_parse.c\
square_parse.c\
triangle_parse.c\
vector_parse.c

RAY				:= \
camera_ray_gen.c\
find_closest.c\
ray_bounce.c

SETUP			:= \
inits.c\
intersect_setup.c\
change_setup.c

VECTOR			:= \
vecangle.c\
veccross.c\
vecdot.c\
vecis.c\
vecmag.c\
vecmult.c\
vecnew.c\
vecnewvalues.c\
vecnorm.c\
vecprod.c\
vecscale.c\
vecsub.c\
vecsum.c\
vectranslat.c\
veczero.c

SRCS			:= \
$(addprefix change/, $(CHANGE))\
$(addprefix color/, $(COLOR))\
$(addprefix intersect/, $(INTERSECT))\
$(addprefix main/, $(MAIN))\
$(addprefix parse/, $(PARSE))\
$(addprefix ray/, $(RAY))\
$(addprefix setup/, $(SETUP))\
$(addprefix vector/, $(VECTOR))

SRCS_FILES			:= \
$(addprefix srcs/, $(SRCS))

OBJS			= $(SRCS_FILES:%.c=%.o)

INCLUDES		= \
-I includes/libmlx\
-I includes/libmlx/X11\
-I includes\
-I includes/libft\

LIB_SRCS		= \
includes/libft/libft.a\
includes/libmlx/libmlx.a

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
SANITIZE		= -g3 -fsanitize=address
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

clean:
	$(RM) $(OBJS)

fclean:			clean
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
