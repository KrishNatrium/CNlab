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
    struct sockaddr_in servaddr;
    char msg[50];
    int sent_len;
    socklen_t servaddr_len = sizeof(servaddr);

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

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = 3001;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    struct sockaddr_in localaddr;
    localaddr.sin_family = AF_INET;
    localaddr.sin_port = 0;
    localaddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&localaddr, sizeof(localaddr)) == -1)
    {
        printf("Bind FAILURE for CLIENT.\n");
        return 1;
    }
    else
    {
        printf("Bind SUCCESSFUL for CLIENT.\n");
    }

    while (1)
    {
        printf("Enter message to send: ");
        fgets(msg, sizeof(msg), stdin);
        msg[strcspn(msg, "\n")] = '\0';

        sent_len = sendto(sockfd, msg, strlen(msg), 0, (struct sockaddr *)&servaddr, servaddr_len);
        if (sent_len == -1)
        {
            printf("sendto FAILURE.\n");
            return 1;
        }

        sent_len = recvfrom(sockfd, msg, sizeof(msg) - 1, 0, NULL, NULL);
        if (sent_len == -1)
        {
            printf("recvfrom FAILURE.\n");
            return 1;
        }

        msg[sent_len] = '\0';
        printf("Received Response: %s\n", msg);

        if (strcmp(msg, "EXIT") == 0)
        {
            printf("EXIT received. Terminating.\n");
            break;
        }
    }

    return 0;
}