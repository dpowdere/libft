# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 17:22:01 by dpowdere          #+#    #+#              #
#    Updated: 2021/12/08 17:42:26 by dpowdere         ###   ########.fr        #
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
	ft_strcmp.c \
	ft_strdup.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtod.c \
	ft_strtof.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_wcslen.c \
	ft_wcstombs.c \
	ft_wctomb.c \
	ft_write.c \
\
	ft_free_null.c \
	ft_get_next_line.c \
	ft_get_next_line_utils.c \
	ft_is_big_endian.c \
	ft_itoa.c \
	ft_jbase.c \
	ft_ptrarr_len.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_split_const.c \
	ft_strjoin.c \
	ft_strmapi.c \
	ft_strtoi.c \
	ft_strtrim.c \
	ft_str_index.c \
	ft_str_xwith.c \
	ft_substr.c \
	ft_wcstombs_len.c \
	ft_wctomb_len.c \
\
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstconv.c \
	ft_lstdelone.c \
	ft_lstdetach.c \
	ft_lstinsert.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstpipeline.c \
	ft_lstpop.c \
	ft_lstpopconv.c \
	ft_lstpopreduce.c \
	ft_lstreduce.c \
	ft_lstsize.c

AR := ar
ARFLAGS := crs

CC := gcc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -MMD -MP
ifdef DEBUG
  CFLAGS += -g3
endif

NAME := $(LIBNAME).a
OBJS := $(CONTENTS:.c=.o)
DEPS := $(OBJS:.o=.d)

################################################################################

.PHONY: all clean fclean re

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

#%.o: %.c
#	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

all: $(NAME)

clean:
	$(RM) *.o *.d *.gch

fclean: clean
	$(RM) $(NAME) *.dSYM

re: fclean all

-include $(DEPS)
