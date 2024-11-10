#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int sockfd, K, size;
    struct sockaddr_in myaddr;
    int arr[50], max, min;

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

    printf("Enter size of the array: ");
    scanf("%d", &size);

    printf("Enter %d elements: \n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    send(sockfd, &size, sizeof(size), 0);
    send(sockfd, arr, sizeof(int) * size, 0);

    recv(sockfd, &max, sizeof(max), 0);
    recv(sockfd, &min, sizeof(min), 0);

    printf("Received from server: Max = %d, Min = %d\n", max, min);

    close(sockfd);

    return 0;
}