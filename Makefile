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
srcs/minirt.c

OBJS			= $(SRCS:%.c=%.o)

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
MLX_LINKS		= -lmlx -framework OpenGL -framework AppKit

RM				= rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
	$(CC) $(CFLAGS) $(MLX_LINKS) -o $@ $<

bonus:			all

clean:
	$(RM) $(OBJS)

fclean:			clean
	$(RM) $(NAME)

norme:
	norminette *.c *.h

re:				fclean all

.PHONY: all clean bonus norme re
