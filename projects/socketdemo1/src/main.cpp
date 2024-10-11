#include "SocketFactory.h"
#include <iostream>

int main() {
    // Create and use a server socket
    Socket* serverSocket = SocketFactory::createSocket(SocketType::SERVER);
    serverSocket->create();
    serverSocket->connectOrBind();
    std::cout << "Message from client: " << serverSocket->receiveData() << std::endl;
    serverSocket->sendData("Hello from server");
    serverSocket->closeSocket();
    delete serverSocket;

    // Create and use a client socket
    Socket* clientSocket = SocketFactory::createSocket(SocketType::CLIENT);
    clientSocket->create();
    clientSocket->connectOrBind();
    clientSocket->sendData("Hello from client");
    std::cout << "Message from server: " << clientSocket->receiveData() << std::endl;
    clientSocket->closeSocket();
    delete clientSocket;

    return 0;
}