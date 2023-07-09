/**
 * server client program of tcp type using socket programming
 */

#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h> // read(), write(), close()
#include <ctype.h> //  isxdigit()



/**
 * defination of macros used in whole program as constant.
 */
#define MAX 80
#define PORT 8080
#define SA struct sockaddr



/**
 * Globle variable ie Character array used in all functions of program
 */
char buff[MAX];

int validate_number(char *str);
int validate_ip(char *ip);
void forip(int acceptfd);
int isValidMacAddress(char* mac);
void formac(int acceptfd);
