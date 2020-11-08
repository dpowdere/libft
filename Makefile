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
SHELL = /bin/bash
# By default Make uses /bin/sh as its shell. Unless $(SHELL) variable is
# redefined to bash, the ascii color escape codes will not work.
DONE = @printf "\x1b[32mDONE\x1b[0m\n"

all: $(NAME)

bonus: ISBONUS = 1
bonus: O += $(OBONUS)
bonus: C += $(CBONUS)
bonus: HEADER += $(HBONUS)
bonus: $(NAME)

clean:
	@printf "Remove relocatable object files... "
	@rm -f $(O) $(OBONUS) $(HEADER).gch $(HBONUS).gch
	$(DONE)

fclean: clean
	@printf "Remove static library file... "
	@rm -f $(NAME)
	$(DONE)

re: fclean all

$(NAME): $(O)
	@printf "Compose static library... "
	@ar rcDs $@ $^
	$(DONE)

$(O): $(HEADER) $(C)
	@printf "Compile relocatable object files... "
	@gcc $(COMPILE_FLAGS) -DBONUS=${ISBONUS} -c $(C)
	$(DONE)

.PHONY: all clean fclean re
