#include <array>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

class Server {
public:
  Server() {}
  ~Server() {

    if (serverSocket != -1)
      close(serverSocket);
    else {
      close(clinetSocket);
    }
  }
  std::array<char, 5000> buffer;
  int serverSocket;
  sockaddr_in serverAddress;
  int clinetSocket;
  uint8_t socketListen();
  uint8_t socketBind();
  uint8_t socketAccept();
  uint8_t socketRecv();
  uint8_t socketInit();
  void socketMsg();
  void socketClose();
  void sendMsg(const std::string &msg);
  void trim_end(std::string &str);
  std::string server_read();
};
