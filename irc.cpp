#include <iostream>
#include <string>
#include <cstring>
#include <WinSock2.h>

int main() {
    std::cout << "Hello World" << std::endl;
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed." << std::endl;
        return 1;
    }
    std::string server = "irc.freenode.net";
    int port = 1234;
    std::string channel = "#your_channel";
    std::string botname =  "IRC-SampleBot";
    char buffer[4096];

    SOCKET sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd == INVALID_SOCKET) {
        std::cerr << "Error creating socket." << std::endl;
        WSACleanup();
        return 1;
    }

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(server.c_str());

    if (connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Failed to connect to server." << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    return 0;
}