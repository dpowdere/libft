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
	isalnum \
	isalpha \
	isascii \
	isdigit \
	isprint \
	strlen \
	tolower \
	toupper

NAME = $(LIBNAME).a
HEADER = $(LIBNAME).h
GCH = $(HEADER).gch
C = $(patsubst %, ft_%.c, $(CONTENTS))
O = $(patsubst %, ft_%.o, $(CONTENTS))
COMPILE_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

clean:
	rm -f $(O) $(GCH)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME): $(O)
	ar -cru $@ $^
	ranlib $@

$(O): $(HEADER) $(C)
	gcc $(COMPILE_FLAGS) -c $(C)

.PHONY: all clean fclean re