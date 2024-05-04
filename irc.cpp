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

    return 0;
}