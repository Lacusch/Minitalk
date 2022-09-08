all: server client

server: 
	gcc server.c -o server 

client:
	gcc client.c ../libft/libft.a -o client 
clean:
	rm -f server client
re: clean all