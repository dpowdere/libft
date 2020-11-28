# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 17:22:01 by dpowdere          #+#    #+#              #
#    Updated: 2020/11/27 14:44:08 by dpowdere         ###   ########.fr        #
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
	ft_split_const.c \
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
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
AR = ar
ARFLAGS = rcusv

.PHONY: all bonus clean fclean re

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

all: bonus

bonus:
	@$(MAKE) $(NAME) ADDBONUS=1

clean:
	$(RM) *.o *.gch

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

# Only get targets that depend on libft.h
# :r!gcc -MM *.c | grep libft.h
ft_bzero.o: ft_bzero.c libft.h
ft_calloc.o: ft_calloc.c libft.h
ft_lstadd_back.o: ft_lstadd_back.c libft.h
ft_lstadd_front.o: ft_lstadd_front.c libft.h
ft_lstclear.o: ft_lstclear.c libft.h
ft_lstdelone.o: ft_lstdelone.c libft.h
ft_lstiter.o: ft_lstiter.c libft.h
ft_lstlast.o: ft_lstlast.c libft.h
ft_lstmap.o: ft_lstmap.c libft.h
ft_lstnew.o: ft_lstnew.c libft.h
ft_lstsize.o: ft_lstsize.c libft.h
ft_putendl_fd.o: ft_putendl_fd.c libft.h
ft_putnbr_fd.o: ft_putnbr_fd.c libft.h
ft_putstr_fd.o: ft_putstr_fd.c libft.h
ft_split.o: ft_split.c libft.h
ft_strchr.o: ft_strchr.c libft.h
ft_strdup.o: ft_strdup.c libft.h
ft_strjoin.o: ft_strjoin.c libft.h
ft_strlcat.o: ft_strlcat.c libft.h
ft_strlen.o: ft_strlen.c libft.h
ft_strmapi.o: ft_strmapi.c libft.h
ft_strnstr.o: ft_strnstr.c libft.h
ft_strtrim.o: ft_strtrim.c libft.h
ft_substr.o: ft_substr.c libft.h
