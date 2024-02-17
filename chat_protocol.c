#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ws2tcpip.h> // For Windows socket definitions and functions
#include <winsock2.h> // For TCP/IP protocols and internet functionality


#define PORT 8080  // Port number for the socket connection
#define SERVER "127.0.0.1"
#define BUFFER_SIZE 1024 // Buffer size for data transmission

struct sockaddr_in* createIP4Address(char *ip, int port);

SOCKET createTCPIp4Socket();

int connectToServer(SOCKET socketFD, struct sockaddr_in address);

struct sockaddr_in* createIP4Address(char *ip, int port){
    // Define the server address and port
//    char* ip = "142.250.188.46"; // IP address for the server
    struct sockaddr_in  *address = malloc(sizeof(struct sockaddr_in)); // Struct for storing the server address
    if(address == NULL){
        perror("Malloc failed");
        exit(EXIT_FAILURE);
    }

    address->sin_family = AF_INET; // Setting the address family to IPv4
    address->sin_port = htons(PORT); // Converting the PORT number to network byte order

    if(inet_pton(AF_INET, ip, &address->sin_addr)<=0){
        printf("Invalid address/ Address not supported \n");
        free(address);
        exit(EXIT_FAILURE);
    }
    return address;
}
int main() {

    return 0;
}

int connectToServer(SOCKET socketFD, struct sockaddr_in address) {
    int result = connect(socketFD, (struct sockaddr *)&address, sizeof(address));
    if (result == SOCKET_ERROR) {
        int errorCode = WSAGetLastError();
        printf("Connect failed with error: %ld\n", errorCode);
        if (errorCode == WSAETIMEDOUT) {
            printf("Connection timed out.\n");
        } else if (errorCode == WSAECONNREFUSED) {
            printf("Connection refused.\n");
        }
        closesocket(socketFD);
        WSACleanup();
        return -1;
    } else {
        printf("Connection was successful\n");
        return 0;
    }
}

SOCKET createTCPIp4Socket(){
    return socket(AF_INET, SOCK_STREAM, 0);
};