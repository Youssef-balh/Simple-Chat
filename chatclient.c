#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define MAX_LEN 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[MAX_LEN] = {0};

    sock = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(1550);

    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    while (1) {
        printf("Client: ");
        fgets(buffer, MAX_LEN, stdin);
        send(sock, buffer, strlen(buffer), 0);

        if (strcmp(buffer, "exit\n") == 0) {
            break;
        }

        memset(buffer, 0, MAX_LEN);
        read(sock, buffer, MAX_LEN);
        printf("Server: %s\n", buffer);
    }

    close(sock);
    return 0;
}
