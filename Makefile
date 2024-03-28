# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/31 17:22:06 by mvalerio          #+#    #+#              #
#    Updated: 2024/03/28 18:43:35 by mvalerio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CC = cc

STANDARD_FLAGS 	= -Wall -Werror -Wextra -g #-fsanitize=address

INCLUDE = -Iincludes

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

MINITALK_LIB = minitalk.a

CLIENT = client
SERVER = server

CLIENT_SRC = src/client.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

SERVER_SRC = src/server.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)

%.o: %.c
	@$(CC) $(STANDARD_FLAGS) -o $@ -c $<

all: $(SERVER) $(CLIENT)

$(CLIENT): $(CLIENT_OBJ) $(OBJ)
	@echo "Compiling $@"
	@make -C $(LIBFT_DIR) > /dev/null
	@$(CC) $(STANDARD_FLAGS) $(INCLUDE) $(CLIENT_OBJ) $(LIBFT_A)  -o client > /dev/null
	@echo "client has been created."

$(SERVER): $(SERVER_OBJ) $(OBJ)
	@echo "Compiling $@"
	@make -C $(LIBFT_DIR) > /dev/null
	@$(CC) $(STANDARD_FLAGS) $(INCLUDE) $(SERVER_OBJ) $(LIBFT_A)  -o server > /dev/null
	@echo "server has been created."

clean:
	@rm -f src/*.o
	@rm -f bonus_src/*.o
	@make -C $(LIBFT_DIR) clean > /dev/null
	@echo Object files have been deleted.

fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@make -C $(LIBFT_DIR) fclean > /dev/null
	@echo All created files have been deleted.

re: fclean all

.PHONY: fclean clean all re
