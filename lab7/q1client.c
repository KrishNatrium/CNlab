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
    int nums[2], sum;

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

    printf("Enter number 1: ");
    scanf("%d", &nums[0]);
    printf("Enter number 2: ");
    scanf("%d", &nums[1]);

    send(sockfd, nums, sizeof(nums), 0);

    recv(sockfd, &sum, sizeof(sum), 0);
    printf("Received sum from server: %d\n", sum);

    close(sockfd);

    return 0;
}