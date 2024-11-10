/*
Write the codes for implementing complete datagram socket program for both client and receiver and print the message read.
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{

    int sockfd, K, src;
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

    int m = sizeof(src);
    char msg1[50];
    int r = recvfrom(sockfd, msg1, sizeof(msg1), 0, (struct sockaddr *)&src, &m);
    if (r == -1)
    {
        printf("recvfrom FAILURE.\n");
        return 1;
    }
    else
    {
        msg1[r] = '\0';
        printf("Received Message: %s\n", msg1);
    }
}