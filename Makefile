# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 17:22:01 by dpowdere          #+#    #+#              #
#    Updated: 2020/11/25 23:36:50 by dpowdere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBNAME = libft
CONTENTS = \
	atoi \
	bzero \
	calloc \
	isalnum \
	isalpha \
	isascii \
	isdigit \
	isprint \
	memccpy \
	memchr \
	memcmp \
	memcpy \
	memmove \
	memset \
	strchr \
	strdup \
	strlcat \
	strlcpy \
	strlen \
	strncmp \
	strnstr \
	strrchr \
	tolower \
	toupper \
\
	itoa \
	putchar_fd \
	putendl_fd \
	putnbr_fd \
	putstr_fd \
	split \
	strjoin \
	strmapi \
	strtrim \
	substr
BONUS = \
	lstadd_back \
	lstadd_front \
	lstclear \
	lstdelone \
	lstiter \
	lstlast \
	lstmap \
	lstnew \
	lstsize


NAME = $(LIBNAME).a
HEADER = $(LIBNAME).h
C = $(patsubst %, ft_%.c, $(CONTENTS))
O = $(patsubst %, ft_%.o, $(CONTENTS))
CBONUS = $(patsubst %, ft_%.c, $(BONUS))
OBONUS = $(patsubst %, ft_%.o, $(BONUS))
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
AR = ar
ARFLAGS = rcs

.PHONY: all bonus clean fclean re

$(NAME): $(O)
	$(AR) $(ARFLAGS) $@ $^

all: bonus

bonus: $(O) $(OBONUS)
	$(AR) $(ARFLAGS) $(NAME) $(O) $(OBONUS)

clean:
	$(RM) $(O) $(OBONUS) $(HEADER).gch

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

ft_atoi.o: ft_atoi.c
ft_bzero.o: ft_bzero.c libft.h
ft_calloc.o: ft_calloc.c libft.h
ft_isalnum.o: ft_isalnum.c
ft_isalpha.o: ft_isalpha.c
ft_isascii.o: ft_isascii.c
ft_isdigit.o: ft_isdigit.c
ft_isprint.o: ft_isprint.c
ft_itoa.o: ft_itoa.c
ft_lstadd_back.o: ft_lstadd_back.c libft.h
ft_lstadd_front.o: ft_lstadd_front.c libft.h
ft_lstclear.o: ft_lstclear.c libft.h
ft_lstdelone.o: ft_lstdelone.c libft.h
ft_lstiter.o: ft_lstiter.c libft.h
ft_lstlast.o: ft_lstlast.c libft.h
ft_lstmap.o: ft_lstmap.c libft.h
ft_lstnew.o: ft_lstnew.c libft.h
ft_lstsize.o: ft_lstsize.c libft.h
ft_memccpy.o: ft_memccpy.c
ft_memchr.o: ft_memchr.c
ft_memcmp.o: ft_memcmp.c
ft_memcpy.o: ft_memcpy.c
ft_memmove.o: ft_memmove.c
ft_memset.o: ft_memset.c
ft_putchar_fd.o: ft_putchar_fd.c
ft_putendl_fd.o: ft_putendl_fd.c libft.h
ft_putnbr_fd.o: ft_putnbr_fd.c libft.h
ft_putstr_fd.o: ft_putstr_fd.c libft.h
ft_split.o: ft_split.c
ft_strchr.o: ft_strchr.c libft.h
ft_strdup.o: ft_strdup.c libft.h
ft_strjoin.o: ft_strjoin.c libft.h
ft_strlcat.o: ft_strlcat.c libft.h
ft_strlcpy.o: ft_strlcpy.c
ft_strlen.o: ft_strlen.c libft.h
ft_strmapi.o: ft_strmapi.c libft.h
ft_strncmp.o: ft_strncmp.c
ft_strnstr.o: ft_strnstr.c libft.h
ft_strrchr.o: ft_strrchr.c
ft_strtrim.o: ft_strtrim.c libft.h
ft_substr.o: ft_substr.c libft.h
ft_tolower.o: ft_tolower.c
ft_toupper.o: ft_toupper.c
