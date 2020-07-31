# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clkuznie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/30 08:42:51 by clkuznie          #+#    #+#              #
#    Updated: 2020/07/30 08:42:54 by clkuznie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=  minirt

SRCS			:= \
err_print.c\
minirt.c

LIB				:= \
includes/libft

FILES			:= \
$(addprefix srcs/, $(SRCS))

OBJS			= $(FILES:%.c=%.o)

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
MLX_LINKS		= -lmlx -framework OpenGL -framework AppKit

RM				= rm -f

all:			$(NAME)

$(NAME):		libcomp $(OBJS)
	@echo "\n\033[0;33mCompiling..."
	$(CC) $(CFLAGS) -o $@ $(MLX_LINKS) $(OBJS) $(LIB)/libft.a

%.o:			%.c
	$(CC) $(CFLAGS) -I $(LIB) -I includes -c $< -o $@

libcomp:
	@echo "\n\033[0;33mLib_Compiling..."
	make -C $(LIB)

clean:			cleanlib
	$(RM) $(OBJS)

fclean:			fcleanlib
	$(RM) $(OBJS)
	$(RM) $(NAME)

cleanlib:
	make --directory=$(LIB) clean

fcleanlib:
	make --directory=$(LIB) fclean

norme:
	norminette *.c *.h

re:				fclean all

.PHONY: all clean bonus norme re libcomp cleanlib fcleanlib
