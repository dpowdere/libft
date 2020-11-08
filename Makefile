# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 17:22:01 by dpowdere          #+#    #+#              #
#    Updated: 2020/11/02 17:34:34 by dpowdere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBNAME = libft
CONTENTS = \
	atoi \
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
	put \
	split \
	strjoin \
	strmapi \
	strtrim \
	substr
BONUS = \
	lstnew


NAME = $(LIBNAME).a
HEADER = $(LIBNAME).h
C = $(patsubst %, ft_%.c, $(CONTENTS))
O = $(patsubst %, ft_%.o, $(CONTENTS))
HBONUS = $(LIBNAME)_bonus.h
CBONUS = $(patsubst %, ft_%.c, $(BONUS))
OBONUS = $(patsubst %, ft_%.o, $(BONUS))
COMPILE_FLAGS = -Wall -Wextra -Werror
ISBONUS = 0

all: $(NAME)

bonus: ISBONUS = 1
bonus: O += $(OBONUS)
bonus: C += $(CBONUS)
bonus: HEADER += $(HBONUS)
bonus: $(NAME)

clean:
	@rm -f $(O) $(OBONUS) $(HEADER).gch $(HBONUS).gch

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME): $(O)
	ar rcDs $@ $^

$(O): $(HEADER) $(C)
	gcc $(COMPILE_FLAGS) -DBONUS=${ISBONUS} -c $(C)

.PHONY: all clean fclean re
