
#include"client.h"

/**
 *  @Brief  Extract IP address from system and communicate with server.
 *  Run ifconfig linux command using System() function and store result in info.txt file'
 *  Run awk command to extract mac from info.txt file and move to ip.txt.
 *  using file pointer ptr read the IP from file ip.txt
 *  Argument is file discriptor of socket function.
 *  bzero() fuction used to empty buffer.
 *  read () and Write() functions used to send and receive messages.
 *  @Return : void type function return nothing.
 */



void forip(int socketfd)
{
        system("ifconfig > info.txt");

        system(" awk '/inet/ {print $2 }' info.txt > ip.txt");

        FILE* ip;
        ip = fopen("ip.txt","r");

        if (NULL == ip){
                printf("file can't be opened \n");
        }

        fgets(buff,14,ip);

        printf("To server: %s",buff);
        fclose(ip);
        write(socketfd, buff, 15);
        bzero(buff, sizeof(buff));
        read(socketfd, buff, sizeof(buff));
        printf("\nFrom Server : %s\n", buff);

}

/**
 *  @Brief  Extract mac from system and communicate with server.
 *  Run ifconfig linux command using System() function and store result in info.txt file'
 *  Run awk command to extract mac from info.txt file and move to mac.txt.
 *  using file pointer ptr read the mac from file mac.txt
 *  Argument is file discriptor of socket function.
 *  bzero() fuction used to empty buffer.
 *  read () and Write() functions used to send and receive messages.
 *  fclose() is used to close the file.
 *  @Return : return nothing.
 */


void formac(int socketfd)
{
        system("ifconfig > info.txt");
        system(" awk '/ether/ {print $2 }' info.txt > mac.txt");
        FILE* ptr;
        ptr = fopen("mac.txt","r");
        if (NULL == ptr){
                printf("file can't be opened \n");
        }
        fgets(buff,18,ptr);
        printf("To server: %s\n",buff);
        fclose(ptr);
        write(socketfd, buff, sizeof(buff));
        bzero(buff, sizeof(buff));
        read(socketfd, buff, sizeof(buff));
        printf("From Server : %s\n", buff);

}
