#ifndef CLIENT_SOCKET_H
#define CLIENT_SOCKET_H

#include "Socket.h"
#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

class ClientSocket : public Socket {
private:
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

public:
    void create() override {
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            std::cerr << "Socket creation error" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    void connectOrBind() override {
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(PORT);

        if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
            std::cerr << "Invalid address/ Address not supported" << std::endl;
            exit(EXIT_FAILURE);
        }

        if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            std::cerr << "Connection Failed" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    void sendData(const std::string &data) override {
        send(sock, data.c_str(), data.length(), 0);
    }

    std::string receiveData() override {
        read(sock, buffer, BUFFER_SIZE);
        return std::string(buffer);
    }

    void closeSocket() override {
        close(sock);
    }
};

#endif // CLIENT_SOCKET_H