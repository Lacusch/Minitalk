# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slaszlo- <slaszlo-@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/04 06:18:07 by slaszlo-          #+#    #+#              #
#    Updated: 2022/09/29 02:50:41 by slaszlo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc
CFLAGS = -Wall - Wextra - Werror
NAME = minitalk
SERVER = server
CLIENT = client
LIBFT = libft/libft.a

all: $(LIBFT) server client
$(LIBFT):
	git submodule update --init --recursive --remote
	make -C ./libft
$(SERVER):
	gcc src/server.c libft/libft.a -o server
$(CLIENT):
	gcc src/client.c libft/libft.a -o client
clean:
	make clean -C ./libft
fclean: clean
	make fclean -C ./libft
	rm -f server client
re: fclean all
norm:
	norminette libft/ src/
.PHONY: all clean fclean re libft
