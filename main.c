#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ws2tcpip.h> // For Windows socket definitions and functions
#include <winsock2.h> // For TCP/IP protocols and internet functionality

#define PORT 8080  // Port number for the socket connection
#define BUFFER_SIZE 1024 // Buffer size for data transmission

struct = socket_in* createIP4Address(char *ip, int port);

int createTCPIp4Socket();
// I STOPED HERE
struct = socket_in* createIP4Address(char *ip, int port){
    // Define the server address and port
//    char* ip = "142.250.188.46"; // IP address for the server
    struct sockaddr_in  * address = malloc(sizeof(struct sockaddr_in)); // Struct for storing the server address
    address->sin_family = AF_INET; // Setting the address family to IPv4
    address->sin_port = htons(PORT); // Converting the PORT number to network byte order
    inet_pton(AF_INET, ip, &address.sin_addr); // Convert IP address from text to binary form
}

int main() {

    WSADATA wsaData; // Structure to hold information about the Windows Sockets implementation
    int iResult; // Variable to store the result of Winsock functions

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed: %d\n", iResult);
        return 1;
    }

    // Create a socket for the connection to the server
    SOCKET socketFD = createTCPIp4Socket();
    if (socketFD == INVALID_SOCKET) {
        printf("Error creating socket: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1; // Early return on failure
    }

    // Attempt to connect to the server
    int result = connect(socketFD, (struct sockaddr *)&address, sizeof(address));
    if (result == SOCKET_ERROR) {
        int errorCode = WSAGetLastError();
        printf("Connect failed with error: %ld\n", errorCode);

        if (errorCode == WSAETIMEDOUT) {
            printf("Connection timed out.\n");
        } else if (errorCode == WSAECONNREFUSED) {
            printf("Connection refused.\n");
        }
        closesocket(socketFD); // Close the socket on failure before cleanup
        WSACleanup(); // Clean up
        return 1;
    } else {
        printf("Connection was successful\n");
    }

    // Close the socket and perform cleanup after successful connection
    closesocket(socketFD);
    WSACleanup();
    return 0;
}
int createTCPIp4Socket(){
    socket(AF_INET, SOCK_STREAM, 0);
};