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
    struct sockaddr_in serveraddr, localaddr;
    int num, recv_sum;
    socklen_t serverlen = sizeof(serveraddr);
    socklen_t localaddrlen = sizeof(localaddr);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1)
    {
        printf("Socket creation FAILURE for CLIENT.\n");
        return 1;
    }
    else
    {
        printf("Socket creation SUCCESSFUL for CLIENT.\n");
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = 3001;
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    localaddr.sin_family = AF_INET;
    localaddr.sin_port = 0;
    localaddr.sin_addr.s_addr = INADDR_ANY;

    K = bind(sockfd, (struct sockaddr *)&localaddr, sizeof(localaddr));
    if (K == -1)
    {
        printf("Bind FAILURE for CLIENT.\n");
        return 1;
    }
    else
    {
        printf("Bind SUCCESSFUL for CLIENT.\n");
    }

    printf("Enter an integer: ");
    scanf("%d", &num);

    int sentlen = sendto(sockfd, &num, sizeof(num), 0, (struct sockaddr *)&serveraddr, serverlen);
    if (sentlen == -1)
    {
        printf("sendto FAILURE.\n");
        return 1;
    }

    int recvlen = recvfrom(sockfd, &recv_sum, sizeof(recv_sum), 0, (struct sockaddr *)&serveraddr, &serverlen);
    if (recvlen == -1)
    {
        printf("recvfrom FAILURE.\n");
        return 1;
    }

    printf("Received sum from receiver: %d\n", recv_sum);

    return 0;
}