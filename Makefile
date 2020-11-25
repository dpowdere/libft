# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 17:22:01 by dpowdere          #+#    #+#              #
#    Updated: 2020/11/26 00:38:35 by dpowdere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBNAME = libft
CONTENTS = \
	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_tolower.c \
	ft_toupper.c \
\
	ft_itoa.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strjoin.c \
	ft_strmapi.c \
	ft_strtrim.c \
	ft_substr.c
BONUS = \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c

OBJS_MANDATORY = $(CONTENTS:.c=.o)
OBJS_BONUS = $(BONUS:.c=.o)
OBJS = $(OBJS_MANDATORY)
ifdef ADDBONUS
	OBJS += $(OBJS_BONUS)
endif

NAME = $(LIBNAME).a
HEADER = $(LIBNAME).h
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
AR = ar
ARFLAGS = rcs

.PHONY: all bonus clean fclean re

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

all: bonus

bonus:
	@ADDBONUS=1 $(MAKE) $(NAME)

clean:
	$(RM) $(OBJS_MANDATORY) $(OBJS_BONUS) $(HEADER).gch

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.c $HEADER
	$(CC) $(CFLAGS) -o $@ $<
