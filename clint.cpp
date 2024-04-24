

// C++ program to illustrate the client application in the
// socket programming
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <ostream>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  // creating socket
  int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

  // specifying address
  sockaddr_in serverAddress;
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons(8080);
  serverAddress.sin_addr.s_addr = INADDR_ANY;
  std::cout << "*****************Clinet start*******************" << std::endl;
  // sending connection request
  connect(clientSocket, (struct sockaddr *)&serverAddress,
          sizeof(serverAddress));

  // sending data
  std::string str;
  while (1) {
    std::cout << "enter the massge" << std::endl;
    std::cin >> str;
    const char *message = str.c_str();
    send(clientSocket, message, strlen(message), 0);
  }

  // closing socket
  close(clientSocket);

  return 0;
}