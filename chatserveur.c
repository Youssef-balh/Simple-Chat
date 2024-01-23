#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define MAX_LEN 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[MAX_LEN] = {0};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_port = htons(1550);
    address.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t)&addrlen);

    while (1) {
        memset(buffer, 0, MAX_LEN);
        read(new_socket, buffer, MAX_LEN);
        printf("Client: %s\n", buffer);

        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        printf("Server: ");
        memset(buffer, 0, MAX_LEN);
        fgets(buffer, MAX_LEN, stdin);
        send(new_socket, buffer, strlen(buffer), 0);
    }

    close(new_socket);
    close(server_fd);
    return 0;
}
