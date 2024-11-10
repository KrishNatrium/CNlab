/*
Write a socket program in C using TCP where the client sends an array with size to the server.
Now server finds the biggest and smallest number from this array and returns to the client.
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int sockfd, K, fd;
    struct sockaddr_in myaddr, client;
    socklen_t addrlen = sizeof(client);
    int arr[50], size, max, min;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Socket creation FAILURE for SERVER.\n");
        return 1;
    }
    else
    {
        printf("Socket creation SUCCESSFUL for SERVER.\n");
    }

    myaddr.sin_family = AF_INET;
    myaddr.sin_port = 3016;
    myaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    K = bind(sockfd, (struct sockaddr *)&myaddr, sizeof(myaddr));
    if (K == -1)
    {
        printf("Bind FAILURE for SERVER.\n");
        return 1;
    }
    else
    {
        printf("Bind SUCCESSFUL for SERVER.\n");
    }

    listen(sockfd, 5);
    fd = accept(sockfd, (struct sockaddr *)&client, &addrlen);

    recv(fd, &size, sizeof(size), 0);
    recv(fd, arr, sizeof(int) * size, 0);

    max = arr[0];
    min = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    printf("Received array of size %d\n", size);
    printf("Max: %d, Min: %d\n", max, min);

    send(fd, &max, sizeof(max), 0);
    send(fd, &min, sizeof(min), 0);

    close(fd);
    close(sockfd);

    return 0;
}