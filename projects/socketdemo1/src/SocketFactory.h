#ifndef SOCKET_FACTORY_H
#define SOCKET_FACTORY_H

#include "Socket.h"
#include "ServerSocket.h"
#include "ClientSocket.h"

enum class SocketType {
    SERVER,
    CLIENT
};

class SocketFactory {
public:
    static Socket* createSocket(SocketType type) {
        switch (type) {
            case SocketType::SERVER:
                return new ServerSocket();
            case SocketType::CLIENT:
                return new ClientSocket();
            default:
                return nullptr;
        }
    }
};

#endif // SOCKET_FACTORY_H