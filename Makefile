# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 17:22:01 by dpowdere          #+#    #+#              #
#    Updated: 2021/01/02 20:44:31 by dpowdere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBNAME := libft
CONTENTS := \
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
	ft_substr.c \
\
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c \
\
	ft_write.c

OBJS := $(CONTENTS:.c=.o)
DEPS := $(CONTENTS:.c=.d)
NAME := $(LIBNAME).a
SYSTEM := $(shell uname)

CC := gcc
CFLAGS := -Wall -Wextra -Werror -g3
DEPFLAGS = -MM -MP -MT "$(@:.d=.o) $@" -MF $@

AR := ar
ARFLAGS := rcusv
ifneq ($(SYSTEM), Darwin)
  ifeq ($(SYSTEM), Linux)
    ARFLAGS := rcuUsv
  else
    ARFLAGS := rcsv
  endif
endif

.PHONY: all clean fclean re

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

all: $(NAME)

clean:
	$(RM) *.o *.d *.gch

fclean: clean
	$(RM) $(NAME) *.dSYM

re: fclean all

%.o: %.c %.d
	$(CC) $(CFLAGS) -c -o $@ $<

%.d: %.c
	$(CPP) $(DEPFLAGS) $(@:.d=.c) -o /dev/null

-include $(DEPS)
