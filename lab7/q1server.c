/*
Write a socket program in C using TCP where the client sends 2 integers to the server.
Now server calculates sum of these 2 numbers and sends the sum result to the client to display.
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
    int nums[2], sum;

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

    int recv_len = recv(fd, nums, sizeof(nums), 0);
    if (recv_len == -1)
    {
        printf("Receiving FAILURE.\n");
    }
    else
    {
        sum = nums[0] + nums[1];
        printf("Received numbers: %d, %d\n", nums[0], nums[1]);
        printf("Calculated sum: %d\n", sum);
    }

    send(fd, &sum, sizeof(sum), 0);

    close(fd);
    close(sockfd);

    return 0;
}