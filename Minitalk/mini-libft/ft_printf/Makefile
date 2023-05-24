# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 14:05:50 by spiacent          #+#    #+#              #
#    Updated: 2023/04/20 08:58:11 by mivendit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = $(SRC:.c=.o)
NAME = libftprintf.a
LIBC = ar rcs
RM = rm -f
CC = gcc 
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf_pointers.c ft_printf.c

$(NAME): $(OBJS)
		${LIBC} $(NAME) $(OBJS)

all: ${NAME}

clean:
		${RM} $(OBJS)

fclean: clean
		${RM} ${OBJS} ${NAME}

re: fclean all

.PHONY: all clean fclean re libft