#include"server.h"


/**
 *@Brief driver function to make connection with client and also close socket at end
 *socket() function used to create new socket.
 *bind() function used to bind socket to given ip.
 *listen() function used to listen client requests
 *accept() function accept the client request based on address.
 *formac() user defined function which communicate with client and validate mac usnig isValidMacAddress() function.
 *forip() is user defined function which communicate with client and validate IP using validate_ip() function.
 *used infinite whle loop with switch case for menu driven program.
 *close() used to close the created socket
 *@Return : return 0
 * */

int main()
{
        int socketfd, acceptfd, length, choice;
        struct sockaddr_in serveraddr, clientaddr;

        /* socket create and verification*/
        socketfd = socket(AF_INET, SOCK_STREAM, 0);
        if (socketfd == -1)
        {
                printf("socket creation failed...\n");
                exit(0);
        }
        else
                printf("Socket successfully created..\n");

        bzero(&serveraddr, sizeof(serveraddr));

        /* assign IP, PORT*/
        serveraddr.sin_family = AF_INET;
        serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
        serveraddr.sin_port = htons(PORT);

        /* Binding newly created socket to given IP and verification*/
        if ((bind(socketfd, (SA*)&serveraddr, sizeof(serveraddr))) != 0) {
                printf("socket bind failed...\n");
                exit(0);
        }
        else
                printf("Socket successfully binded..\n");

        /* Now server is ready to listen and verification*/
        if ((listen(socketfd, 5)) != 0) {
                printf("Listen failed...\n");
                             exit(0);
        }
        else
                printf("Server listening..\n");
        length = sizeof(clientaddr);

        acceptfd = accept(socketfd, (SA*)&clientaddr, &length);
        if (acceptfd < 0) {
                printf("server accept failed...\n");
                exit(0);
        }
        else
                printf("server accept the client...\n\n");


         while(1)
    {

                printf("Enter 1 To Validate MAC Address\n");
                printf("Enter 2 To Validate IP Address\n");
                printf("Enter 0 to Exit \n");
                printf("Enter your choice : ");

                scanf("%d",&choice);


                switch (choice)
                {
                case 1 :  formac(acceptfd);
                                break;

                case 2 :  forip(acceptfd);
                                break;

                case 0  : strcpy(buff,"Server Exited.... Please exit");
                              write(acceptfd, buff, sizeof(buff));
                                    exit(0);

                        default:
                          printf("Please enter valid choice\n\n");
            }
     }

        close(socketfd);
        return 0;
}
