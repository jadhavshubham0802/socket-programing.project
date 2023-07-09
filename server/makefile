CC=gcc

output: server.o servermain.o 
	$(CC) server.o servermain.o -o server.out

server.o:  server.c
	$(CC) -c server.c

servermain.o:  servermain.c
	$(CC) -c servermain.c

clean:
	rm *.o  server.out
	
