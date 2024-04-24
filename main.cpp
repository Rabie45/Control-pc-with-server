#include "command.hpp"
#include "server.hpp"
#include <array>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <ostream>
#include <string>
#include <sys/socket.h>
#include <thread>
#include <unistd.h>

int main() {
  Server srv;
  CMD cmd;
  if (srv.socketInit()) {
    std::cout << "*****************Server Init ***************" << std::endl;
  } else {
    std::cout << "*****************Server Init erorr***************"
              << std::endl;
  }
  if (srv.socketBind()) {
    std::cout << "*****************Server Binded ***************" << std::endl;
  } else {
    std::cout << "*****************Server bind erorr***************"
              << std::endl;
  }
  if (srv.socketListen()) {
    std::cout << "*****************Server Liseting ***************"
              << std::endl;
  } else {
    std::cout << "*****************Server Liseting erorr***************"
              << std::endl;
  }

  std::string buffer;
  while (1) {

    if (srv.socketAccept()) {
      std::cout << "*****************Client is here ***************"
                << std::endl;

      while (1) {
        if (srv.socketRecv()) {

          buffer = srv.buffer.data();
          std::cout << buffer << std::endl;
          
          // std::this_thread::sleep_for(std::chrono::seconds(2));
        }
        if (buffer != "empty") {
          if (buffer == "Calculator") {
            buffer = cmd.openCalc();
            // server.server_send_msg(buffer);
            buffer = "empty"; // Reset buffer for next read
          } else if (buffer == "browser") {
            buffer = cmd.openBrowser();
            // server.server_send_msg(buffer);
            buffer = "empty"; // Reset buffer f
          } else if (buffer == "vscode") {
            buffer = cmd.openVScode();
            buffer = "empty"; // Reset buffer f
          } else if (buffer == "quit") {
            std::cout << "*****************Server Closed ***************"
                      // server.server_send_msg(buffer);
                      << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            srv.socketClose();
            exit(0);
          }
        }
      }
    }
  }
}
