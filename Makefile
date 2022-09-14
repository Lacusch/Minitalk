# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slaszlo- <coder@slaszlo-@student.42heib    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/04 06:18:07 by slaszlo-          #+#    #+#              #
#    Updated: 2022/09/14 20:45:11 by slaszlo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc
CFLAGS = -Wall - Wextra - Werror
NAME = minitalk
SERVER = server
CLIENT = client
LIBFT = libft
DEPS = libft.a

all: submodules libft server client
libft:
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
submodules:
	git submodule update --init --recursive --remote
.PHONY: all clean fclean re libft
