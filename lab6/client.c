#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int sockfd, K;
    struct sockaddr_in myaddr;
    char msg[50] = {0};

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Socket creation FAILURE for CLIENT.\n");
        return 1;
    }
    else
    {
        printf("Socket creation SUCCESSFUL for CLIENT.\n");
    }

    myaddr.sin_family = AF_INET;
    myaddr.sin_port = 3016;
    myaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    K = connect(sockfd, (struct sockaddr *)&myaddr, sizeof(myaddr));
    if (K == -1)
    {
        printf("Connect FAILURE for CLIENT.\n");
        return 1;
    }
    else
    {
        printf("Connect SUCCESSFUL for CLIENT.\n");
    }

    snprintf(msg, sizeof(msg), "Hello, Server!");

    send(sockfd, msg, strlen(msg), 0);

    recv(sockfd, msg, sizeof(msg), 0);
    printf("Received from server: %s\n", msg);

    close(sockfd);

    return 0;
}