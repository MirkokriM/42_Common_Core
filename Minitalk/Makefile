# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 08:58:23 by mivendit          #+#    #+#              #
#    Updated: 2023/04/20 08:58:26 by mivendit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Werror -Wextra
CC = gcc
NAME_S = server
NAME_C = client
NAME = minitalk

SRC_S = server.c 
SRC_C = client.c \
		mini-libft/ft_atoi.c

OBJ_S = $(SRC_S.O=.c)
OBJ_C = $(SRC_C.O=.c)

FTPRINTF := ./mini-libft/ft_printf/

SEPARATOR = "\033[1m ******************************* \033[0m"

all: $(NAME)
	@$(MAKE) > /dev/null 2>&1 --no-print-directory -C $(FTPRINTF)
	@$(CC) $(FLAGS) $(SRC_S) mini-libft/ft_printf/libftprintf.a -o $(NAME_S)
	@$(CC) $(FLAGS) $(SRC_C) mini-libft/ft_printf/libftprintf.a -o $(NAME_C)

$(NAME): 
	@$(MAKE) > /dev/null 2>&1 --no-print-directory -C $(FTPRINTF)
	@echo "\033[1m Mini-LIBFT done \033[0m"
	@$(CC) $(FLAGS) $(SRC_S) mini-libft/ft_printf/libftprintf.a -o $(NAME_S)
	@$(CC) $(FLAGS) $(SRC_C) mini-libft/ft_printf/libftprintf.a -o $(NAME_C)
	@mv $(NAME_S) $(NAME)
	@echo "\033[1m READY TO START! \033[0m"
	@echo $(SEPARATOR)

server: 
	@$(MAKE) > /dev/null 2>&1 --no-print-directory -C $(FTPRINTF)
	@$(CC) $(FLAGS) $(SRC_S) mini-libft/ft_printf/libftprintf.a -o $(NAME_S)

client: 
	@$(MAKE) > /dev/null 2>&1 --no-print-directory -C $(FTPRINTF)
	2$(CC) $(FLAGS) $(SRC_C) mini-libft/ft_printf/libftprintf.a -o $(NAME_C)

clean: 
	@$(MAKE) > /dev/null 2>&1 --no-print-directory clean -C $(FTPRINTF)
	@echo $(SEPARATOR)
	@rm -f $(OBJ_S)
	@rm -f $(OBJ_C)
	@echo "\033[1m OBJ deleted \033[0m"
	
fclean:	clean
	@$(MAKE) > /dev/null 2>&1 --no-print-directory fclean -C $(FTPRINTF)
	@rm -f $(NAME_S)
	@echo "\033[1m $(NAME_S) deleted \033[0m"
	@rm -f $(NAME_C)
	@echo "\033[1m $(NAME_C) deleted \033[0m"
	@rm -f $(NAME)
	@echo $(SEPARATOR)

re:	fclean all clean

.PHONY: server client clean fclean re libft