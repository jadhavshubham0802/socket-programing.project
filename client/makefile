CC=gcc

output: client.o clientmain.o 
	$(CC) client.o clientmain.o -o client.out

client.o:  client.c
	$(CC) -c client.c

clientmain.o:  clientmain.c
	$(CC) -c clientmain.c

clean:
	rm *.o  client.out
	
