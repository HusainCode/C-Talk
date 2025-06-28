#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>



#define PORT 8080  // port number
#define BUFFER_SIZE 1024 // MAX message size



int main() {

    int server_fd, new_socket;
    struct sockaddr_in address;
    int adderln = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    
    // create the server socket (ipv4, TCP)
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        printf("Socket failed"); // print error if socket fails
        exit(EXIT_FAILURE);
    }

    read(new_socket, buffer, BUFFER_SIZE); // store client data in buffer
    printf("Received: %s\n", buffer);

    char *response = "Hello from the server!\n";
    send(new_socket, response, strlen(response), 0);



    close(new_socket);
    close(server_fd);
    
    
   
    return 0;
};
