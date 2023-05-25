# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 12:46:22 by mivendit          #+#    #+#              #
#    Updated: 2023/05/24 17:27:51 by mivendit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#For best and fluid experience add the -O2 flag at the end of CFLAGS var.
NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I./include -O2
LIBFT = ./mini-libft/libft.a
PRINTF = ./mini-libft/ft_printf/libftprintf.a

SEPARATOR = "\033[1m ******************************* \033[0m"
SRC = \
	sources/fractol.c \
	sources/complex_math.c \
	sources/hooks.c \
	sources/action_utils.c \
	fractals/julia.c \
	fractals/mandelbrot.c \
	fractals/tribrot.c \
	fractals/params.c 

OBJS = $(SRC:.c=.o)

ifeq ($(shell uname), Darwin)
    MLX_LIBS += -L./minilibx -lmlx -framework OpenGL -framework AppKit
else
    MLX_LIBS += -L./minilibx -lmlx -lXext -lX11 -lm
endif

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) --no-print-directory -C ./mini-libft
	@echo $(SEPARATOR)
	@echo "\033[1m Mini-LIBFT done \033[0m"
	@$(MAKE) > /dev/null 2>&1 --no-print-directory -C ./minilibx
	@echo "\033[1m MiniLibX done \033[0m"
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_LIBS) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo "\033[1m READY TO START! \033[0m"
	@echo $(SEPARATOR)

%.o: %.c
	@printf "\tCompiling $<...\n"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\tCompiled!\n"

clean:
	@$(MAKE) > /dev/null 2>&1 clean -C ./mini-libft
	@echo $(SEPARATOR)
	@rm -rf $(OBJS)
	@echo "\033[1m OBJ deleted \033[0m"

fclean: clean
	@$(MAKE) > /dev/null 2>&1 fclean -C ./mini-libft
	@rm -rf $(NAME)
	@echo "\033[1m $(NAME) deleted \033[0m"
	@echo $(SEPARATOR)
re: fclean all

.PHONY: all, clean, fclean, re, bonus
