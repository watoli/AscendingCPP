#ifndef SOCKET_H
#define SOCKET_H

#include <string>

class Socket {
public:
    virtual ~Socket() {}
    virtual void create() = 0;
    virtual void connectOrBind() = 0;
    virtual void sendData(const std::string &data) = 0;
    virtual std::string receiveData() = 0;
    virtual void closeSocket() = 0;
};

#endif // SOCKET_H