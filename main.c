// #include <stdio.h>
// #include <stdlib.h>
// #include <malloc.h>
// // Switching to Linux Ubuntu
// // #include <ws2tcpip.h> // For Windows socket definitions and functions
// // #include <winsock2.h> // For TCP/IP protocols and internet functionality
// #include <netinet/in.h>
// #include <arpa/inet.h>
// #incldue <sys/socket.h>
// #include <unistd.h>

// #define PORT 8080  // Port number for the socket connection
// #define SERVER "127.0.0.1"
// #define BUFFER_SIZE 1024 // Buffer size for data transmission





// //////////////////////////////// MAIN /////////////////////////////////////////////////////////////////////
// int main() {

//     WSADATA wsaData; // Structure to hold information about the Windows Sockets implementation
//     // Initialize Winsock
//     // Variable to store the result of Winsock functions
//     int iResult  = WSAStartup(MAKEWORD(2,2), &wsaData);
//     if (iResult != 0) {
//         printf("WSAStartup failed: %d\n", iResult);
//         return 1;
//     }

//     // Create a socket for the connection to the server
//     SOCKET socketFD = createTCPIp4Socket();
//     if (socketFD == INVALID_SOCKET) {
//         printf("Error creating socket: %ld\n", WSAGetLastError());
//         WSACleanup();
//         return 1;
//     }

//     struct sockaddr_in* addressPtr = createIP4Address(SERVER, PORT);
//     if (!addressPtr) {
//         closesocket(socketFD);
//         WSACleanup();
//         return 1;
//     }
//     int result = connectToServer(socketFD, *addressPtr); // Dereference pointer when passing

//     // Cleanup
//     free(addressPtr); //free the allocated memory
//     closesocket(socketFD);
//     WSACleanup();
//     return result; // Use the result of the connection attempt
// }
// /////////////////////////////// END OF MAIN////////////////////////////////////////////////////////////
