#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main()
{

    int sockfd, K;
    struct sockaddr_in myaddr;

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

    myaddr.sin_family = AF_INET;
    myaddr.sin_port = 6969;
    myaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    K = bind(sockfd, (struct sockaddr *)&myaddr, sizeof(myaddr));
    if (K == -1)
    {
        printf("Bind FAILURE for CLIENT.\n");
        return 1;
    }
    else
    {
        printf("Bind SUCCESSFUL for CLIENT.\n");
    }

    struct sockaddr_in dest;
    dest.sin_family = AF_INET;
    dest.sin_port = 3001;
    dest.sin_addr.s_addr = inet_addr("127.0.0.1");

    char msg[] = "Hello";
    int n = sendto(sockfd, msg, strlen(msg), 0, (struct sockaddr *)&dest, sizeof(dest));
    if (n == -1)
    {
        printf("sendto FAILURE for CLIENT.\n");
        return 1;
    }
    else
    {
        printf("Message Sent\n");
    }

    return 0;
}