#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>           // for close()
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080              // Port number
#define SERVER "127.0.0.1"     // Server IP address
#define BUFFER_SIZE 1024       // Buffer size for data transmission

int main() {
    int socketFD;
    struct sockaddr_in serverAddr;
    char buffer[BUFFER_SIZE] = {0};

    // Create a TCP socket
    socketFD = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFD < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Setup the server address struct
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, SERVER, &serverAddr.sin_addr) <= 0) {
        perror("Invalid address");
        close(socketFD);
        return 1;
    }

    // Connect to the server
    if (connect(socketFD, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Connection failed");
        close(socketFD);
        return 1;
    }

    printf("Connected to the server.\n");

    // Example: Send a message to server
    char *message = "Hello from Linux client!";
    send(socketFD, message, strlen(message), 0);

    // Receive response from server
    int bytes = read(socketFD, buffer, BUFFER_SIZE - 1);
    if (bytes > 0) {
        buffer[bytes] = '\0'; // Null-terminate the received data
        printf("Server says: %s\n", buffer);
    }

    // Clean up
    close(socketFD);
    return 0;
}
