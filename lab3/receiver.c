/*
3)Write the codes for datagram socket program implementing socket( ) and bind( ) functions and display the output.
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{

    int sockfd, K;
    struct sockaddr_in myaddr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1)
    {
        printf("Socket creation FAILURE for RECEIVER.\n");
        return 1;
    }
    else
    {
        printf("Socket creation SUCCESSFUL for RECEIVER.\n");
    }

    myaddr.sin_family = AF_INET;
    myaddr.sin_port = 3001;
    myaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    K = bind(sockfd, (struct sockaddr *)&myaddr, sizeof(myaddr));
    if (K == -1)
    {
        printf("Bind FAILURE for RECEIVER.\n");
        return 1;
    }
    else
    {
        printf("Bind SUCCESSFUL for RECEIVER.\n");
    }

    return 0;
}