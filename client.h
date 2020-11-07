#ifndef __CLIENT_H__
#define __CLIENT_H__
#include "socket.h"
#include <string>


class Client{
  private:
    Socket client;
    std::string host;
    std::string service;
  public:
    Client(const std::string& host,const std::string& service):
      client(),
      host(host),
      service(service)
      {}
    void enviar();
    void run();
};

#endif
