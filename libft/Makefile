# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivendit <mivendit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 08:23:38 by mivendit          #+#    #+#              #
#    Updated: 2023/02/01 14:07:36 by mivendit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Werror -Wextra -Wall
RM = rm -rf
NAME = libft.a
SRC_DIR = ./sources
OBJ_DIR = obj

FILES = ft_isdigit.c ft_memset.c ft_strjoin.c ft_strtrim.c ft_isprint.c \
        ft_putchar_fd.c ft_strlcat.c ft_substr.c ft_atoi.c ft_itoa.c \
        ft_putendl_fd.c ft_strlcpy.c ft_tolower.c ft_bzero.c ft_memcpy.c \
        ft_putnbr_fd.c ft_strlen.c ft_toupper.c ft_calloc.c ft_memchr.c \
        ft_putstr_fd.c ft_strmapi.c ft_isalnum.c ft_memcmp.c ft_split.c \
        ft_strncmp.c ft_isalpha.c ft_memcpy.c ft_strchr.c ft_strnstr.c \
        ft_isascii.c ft_memmove.c ft_strdup.c ft_strrchr.c ft_striteri.c

FILES_B = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
        ft_lstiter.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_lstmap.c

SRCS = $(addprefix $(SRC_DIR)/, $(FILES))
SRCS_B = $(addprefix $(SRC_DIR)/, $(FILES_B))
OBJS = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
OBJS_B = $(addprefix $(OBJ_DIR)/, $(FILES_B:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "\033[104mdone with compilation\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJS_B)
	@ar rcs $(NAME) $(OBJS_B)

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus