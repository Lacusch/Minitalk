# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slaszlo- <slaszlo-@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/04 06:18:07 by slaszlo-          #+#    #+#              #
#    Updated: 2022/08/04 07:11:56 by slaszlo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc
CFLAGS = -Wall - Wextra - Werror
NAME = minitalk
SERVER = server
LIBFT = libft
DEPS = libft.a

all: submodules libft server 
libft:
	make -C ./libft
$(SERVER):
	gcc src/server.c libft/libft.a -o server
clean:
	Make -C libft/ clean
fclean: clean
	rm -f libft/libft.a
	rm -f server
re: fclean all
norm:
	norminette libft/ src/
submodules:
	git submodule update --recursive --remote
.PHONY: all clean fclean re libft