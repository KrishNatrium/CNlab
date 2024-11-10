/*
Write a sender and receiver program in c using connectionless socket.
Now sender sends an integer to the receiver.
The receiver calculates sum of series upto n and return the sum result to the sender for display purpose.
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int sockfd, K;
    struct sockaddr_in myaddr, clientaddr;
    socklen_t clientlen = sizeof(clientaddr);
    int num, sum;
    char buffer[50];

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
    myaddr.sin_addr.s_addr = INADDR_ANY;

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

    int recvlen = recvfrom(sockfd, &num, sizeof(num), 0, (struct sockaddr *)&clientaddr, &clientlen);
    if (recvlen == -1)
    {
        printf("recvfrom FAILURE.\n");
        return 1;
    }

    sum = (num * (num + 1)) / 2;

    int sentlen = sendto(sockfd, &sum, sizeof(sum), 0, (struct sockaddr *)&clientaddr, clientlen);
    if (sentlen == -1)
    {
        printf("sendto FAILURE.\n");
        return 1;
    }
    else
    {
        printf("Sent sum %d back to sender.\n", sum);
    }

    return 0;
}