#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int sockfd;
    struct sockaddr_in myaddr, cliaddr;
    socklen_t cliaddr_len = sizeof(cliaddr);
    char msg[50];
    int recv_len;

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

    if (bind(sockfd, (struct sockaddr *)&myaddr, sizeof(myaddr)) == -1)
    {
        printf("Bind FAILURE for RECEIVER.\n");
        return 1;
    }
    else
    {
        printf("Bind SUCCESSFUL for RECEIVER.\n");
    }

    while (1)
    {
        recv_len = recvfrom(sockfd, msg, sizeof(msg) - 1, 0, (struct sockaddr *)&cliaddr, &cliaddr_len);
        if (recv_len == -1)
        {
            printf("recvfrom FAILURE.\n");
            return 1;
        }

        msg[recv_len] = '\0';
        printf("Received Message: %s\n", msg);

        if (strcmp(msg, "EXIT") == 0)
        {
            printf("EXIT received. Terminating.\n");
            break;
        }

        if (sendto(sockfd, msg, recv_len, 0, (struct sockaddr *)&cliaddr, cliaddr_len) == -1)
        {
            printf("sendto FAILURE.\n");
            return 1;
        }
    }

    return 0;
}