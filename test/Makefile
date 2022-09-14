CC= cc
CFLAGS= -Wall -Wextra -Werror
LIBFT = ./libft
all: server client

server: 
	gcc server.c -o server 
client:
	gcc client.c ../libft/libft.a -o client 
clean:
	make clean -C ./libft
re: clean all
