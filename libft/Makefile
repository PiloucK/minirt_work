# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clkuznie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 19:53:29 by clkuznie          #+#    #+#              #
#    Updated: 2020/07/28 16:36:32 by clkuznie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

SRCS			:= \
ft_atoi.c\
ft_bzero.c\
ft_calloc.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_isprint.c\
ft_iswspace.c\
ft_memccpy.c\
ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memmove.c\
ft_memset.c\
ft_strchr.c\
ft_strdup.c\
ft_strlcat.c\
ft_strlcpy.c\
ft_strlen.c\
ft_strncmp.c\
ft_strnstr.c\
ft_strrchr.c\
ft_tolower.c\
ft_toupper.c\
ft_substr.c\
ft_strjoin.c\
ft_strtrim.c\
ft_split.c\
ft_itoa.c\
ft_strmapi.c\
ft_putchar_fd.c\
ft_putstr_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_strndup.c\
ft_isinset.c\
ft_isinflow.c\
ft_nbrlen.c

B_SRCS			:= \
ft_lstnew.c\
ft_lstadd_front.c\
ft_lstsize.c\
ft_lstlast.c\
ft_lstadd_back.c\
ft_lstdelone.c\
ft_lstclear.c\
ft_lstiter.c\
ft_lstmap.c

OBJS			= $(SRCS:%.c=%.o)

B_OBJS			= $(B_SRCS:%.c=%.o)

CC				= gcc
CFLAGS			= -c -Wall -Wextra -Werror

RM				= rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o:			%.c
	$(CC) $(CFLAGS) $< -o $@

bonus:			$(OBJS) $(B_OBJS)
	ar rc $(NAME) $(B_OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean:			clean
	$(RM) $(NAME)

re:				fclean all
