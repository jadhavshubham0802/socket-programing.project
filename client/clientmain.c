
#include"client.h"

/**
 * @Brief : Driver  function to make connection with server and also close socket at end
 * socket() is function used to create new socket.
 * connect() is function connect to client request based on address.
 * formac() is user defined function which communicate with server and send mac address usnig formac() function.
 * forip() is user defined function which communicate with server and send Ip address.
 * used infinite whle loop with switch case for menu driven program.
 * close() is used to close the created socket
 * @Return : return zero
 */

int main()
{
        int socketfd,  choice;
        struct sockaddr_in serveraddr;

        /**
         * socket create and verification
         */
        socketfd = socket(AF_INET, SOCK_STREAM, 0);
        if (socketfd == -1) {
                printf("socket creation failed...\n");
                exit(0);
        }
        else
        printf("Socket successfully created..\n");
        bzero(&serveraddr, sizeof(serveraddr));

        /**
         *  assign IP, PORT
         */
        serveraddr.sin_family = AF_INET;
        serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        serveraddr.sin_port = htons(PORT);
        /**
         * connect the client socket to server socket
         */
        if (connect(socketfd, (SA*)&serveraddr, sizeof(serveraddr))!= 0)
        {
                printf("connection with the server failed...\n");
                exit(0);
        }
        else
                printf("connected to the server..\n");
                            printf("\n\n");

        /**
         * infinite loop for chat
         */


   while(1)
    {
       read(socketfd, buff, sizeof(buff));
        printf("\nFrom Server : %s\n", buff);



        printf("Enter 1 To Send MAC Address\n");
        printf("Enter 2 To Send IP Address\n");
        printf("Enter 0 to Exit \n");
        printf("Enter expected choice ");

        scanf("%d",&choice);


        switch (choice)
        {
            case 1 :  formac(socketfd);
                        break;

            case 2 :  forip(socketfd);
                        break;

            case 0  : exit(0);

            default:
            printf("Please enter valid choice");
        }
    }
        /* close the socket*/
        close(socketfd);
        return 0;
}
