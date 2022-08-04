# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slaszlo- <slaszlo-@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/04 06:18:07 by slaszlo-          #+#    #+#              #
#    Updated: 2022/08/04 07:03:32 by slaszlo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc
CFLAGS = -Wall - Wextra - Werror
NAME = minitalk
SERVER = server
LIBFT = libft

$(SERVER):
	gcc src/server.c libft/libft.a -o server
all: submodules libft server 
libft/libft.a:
	@make -C $(LIBFT)
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