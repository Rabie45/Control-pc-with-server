#include "server.hpp"
#include <algorithm>
#include <arpa/inet.h>
#include <iostream>
#include <ostream>
#include <sys/types.h>

uint8_t Server ::socketInit() {

  serverSocket = socket(AF_INET, SOCK_STREAM, 0); // ip v4, TCP,
  if (serverSocket < 0) {
    std::cerr << "Fital Error socketInit" << std::endl;
    return 0;
  }

  // Defining server address
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port =
      htons(8080); // htons(): This function is used to convert the unsigned int
                   // from machine byte order to network byte order.
  serverAddress.sin_addr.s_addr =
      INADDR_ANY; // INADDR_ANY: It is used when we don’t want to bind our
  return 1;
}
uint8_t Server::socketBind() {
  int val = bind(serverSocket, (struct sockaddr *)&serverAddress,
                 sizeof(serverAddress));
  if (val < 0) {
    std::cerr << "Fital Error socketBind" << std::endl;
  }
  return 1;
}

uint8_t Server::socketListen() {
  int val = listen(serverSocket, 5);
  if (val < 0) {
    std::cerr << "Fital Error socketListen" << std::endl;
  }
  return 1;
}
uint8_t Server::socketAccept() {

  clinetSocket = accept(serverSocket, nullptr, nullptr);
  std::cout << clinetSocket << std::endl;
  if (clinetSocket < 0) {
    std::cerr << "Problem with client connection" << std::endl;
    return 0;
  }
  return 1;
}

uint8_t Server ::socketRecv() {
  //   int dataReciver = recv(clinetSocket, static_cast<void *>(buffer.data()),
  //  buffer.size() - 1, 0);
  ssize_t byteread = recv(clinetSocket, static_cast<void *>(buffer.data()),
                          buffer.size() - 1, 0);
  std::cout << byteread << std::endl;
  if (byteread < 0) {
    std::cerr << "Error receiving data" << std::endl;
    // return "Error receiving data";
  } else if (byteread == 0) {
    std::cout << "Client closed connection" << std::endl;
    // return "Client closed connection";
  } else {
    std::string buffer_str(buffer.data(), byteread);
    std::cout << "Received message: " << buffer_str << std::endl;
    // return buffer_str;
  }
  return 1;
}
void Server::socketMsg() { std::cout << "msg:> " << buffer.data(); }
void Server::socketClose() { close(clinetSocket); }
void Server::sendMsg(const std::string &msg) {
  send(clinetSocket, msg.c_str(), msg.size(), 0);
}
