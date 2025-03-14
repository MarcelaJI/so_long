# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingjimen <ingjimen@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 09:33:47 by ingjimen          #+#    #+#              #
#    Updated: 2024/11/11 12:04:38 by ingjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRC	= ft_printf.c ft_print_char.c\
      ft_print_hex.c ft_print_int.c\
      ft_print_ptr.c ft_print_str.c\
      ft_print_unsigned.c ft_strlen.c 

OBJ	= $(SRC:.c=.o)

FLAGS	= -Wall -Wextra -Werror

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	cc $(FLAGS) -c $< -o $@
	
all:  $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
