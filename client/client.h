#include <arpa/inet.h> // inet_addr()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h> // bzero()
#include <sys/socket.h>
#include <unistd.h> // read(), write(), close()


/**
 * defination of macros used in whole program.
 */

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

/**
 * Globle variable ie Character array used in all functions program
 */

char buff [MAX];

void forip(int socketfd);
void formac(int socketfd);
