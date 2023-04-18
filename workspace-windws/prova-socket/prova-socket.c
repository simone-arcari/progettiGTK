#include <stdio.h>
#include <stdlib.h>
#include <sys/unistd.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(1234);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 5) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Socket listening on port %d\n", ntohs(addr.sin_port));

    // Rest of your code goes here

    close(sockfd);
    return 0;
}
