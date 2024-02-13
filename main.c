#include <stdio.h>
#include <stdlib.h>
#include <ws2tcpip.h> // Windows socket definitions  and function
#include <winsock2.h> // TCP/IP protocols and internet functionality

#define PORT 8080  // Port number for socket connection
#define BUFFER_SIZE 1024 // Buffer size for data transmission

int main() {

    WSADATA wsaData; // Structure  to hold information  about the windows Sockets implementation
    int iResult; // Variable to store the result of Winsock function

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if(iResult != 0){
        // if WSAsrartup fails, print error message then exit
        printf("WSAStartup failed: %d\n", iResult);
        return 1;
    }


    //Create a socket for connection to the server
    // AF_INET,the IPv4 address family
    // SOCK_STREAM , a stream socket
    // 0 for the default protocol, TCP
    int socketFD = (AF_INET,SOCK_STREAM,0);
    if(socketFD == INVALID_SOCKET){
        // If the socket creation fails, print error message, cleanup then exit
        printf("Error creating socket, %ld\n",WSAGetLastError());
        WSACleanup();
        // Exit
        return 1;
    }


    // Define server address and port
    char* ip = "142.250.188.46"; // IP address for the server
    struct sockaddr_in address; // struc for storing the server address
    address.sin_family = AF_INET; // Setting the fially addres to IPv4
    address.sin_port = htons(PORT); // Converting the PORT number to network byte
    // Convert IP address from text to binary form and store in address structure
    inet_pton(AF_INET,ip,&address.sin_addr);

    // Attempt to connect to the server
    int result = connect(socketFD,(struct sockaddr *)&address, sizeof(address));
    if(result == SOCKET_ERROR){
        // If connection fails, print an error message, close the socket, perform cleanup, and exit
        printf("Connect failed with error: %ld\n", WSAGetLastError());
        closesocket(socketFD); // Close the socket
        WSACleanup(); // Clean up
        return 1;

    }

   // Cleanup
    WSACleanup();
    return 0;
}
