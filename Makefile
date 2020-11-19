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
HBONUS = $(LIBNAME)_bonus.h
CBONUS = $(patsubst %, ft_%.c, $(BONUS))
OBONUS = $(patsubst %, ft_%.o, $(BONUS))
CFLAGS = -Wall -Wextra -Werror
SHELL = /bin/bash  # Unless $(SHELL) variable is redefined, Make uses
# /bin/sh as its shell command by default. We need to use bash instead so that
# the ascii escape codes for color output can work.
GREEN = \x1b[32m
RESET = \x1b[0m\n
DONE = printf "$(GREEN)DONE$(RESET)"

all: $(NAME)

bonus: HEADER += $(HBONUS)
bonus: C += $(CBONUS)
bonus: O += $(OBONUS)
bonus: $(OBONUS) $(NAME)

clean:
	@printf "Remove relocatable object files... "
	@$(RM) $(O) $(OBONUS) $(HEADER).gch $(HBONUS).gch
	@$(DONE)

fclean: clean
	@printf "Remove '$(NAME)' static library file... "
	@$(RM) $(NAME)
	@$(DONE)

re: fclean all

.SECONDEXPANSION:
$(NAME): $$(O)
	@printf "Compose '$@' static library... "
	@ar rcDs $@ $(O)  # \
		# $^ instead of $(O) doesn't work properly in the bonus case. It \
		# expands to plain $(O) without respect to bonus target-specific \
		# redefinition of $(O) with $(OBONUS) addition.
	@$(DONE)

$(O) $(OBONUS): $$(HEADER) $$(C)
	@printf "Compile relocatable object files... "
	@$(CC) $(CFLAGS) -c $(C)
	@$(DONE)

.PHONY: all bonus clean fclean re
