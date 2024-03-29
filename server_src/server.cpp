#include "server.h"
#include "server_parser.h"
#include "server_metodo.h"
#include <iostream>
#include <fstream>


Server::Server(const std::string& service,
              const std::string& root_file):
      service(service), root_file(root_file),
      aceptador(),
      recursos(root_file),thread(){}

void Server::shutdown(){
  this->aceptador.cerrar_conexion(SHUT_RD);
  this->aceptador.cerrar();
  this->thread->join();
  delete this->thread;
}

void Server::run(){
  const char* servicio_aux = this->service.c_str();
  this->aceptador.bind_and_listen(INADDR_ANY,servicio_aux);
  this->thread = new ThAceptador(this->aceptador,recursos);
  (*this->thread)();
}

std::string Server::get_contenido_recurso(const std::string& recurso){
  return this->recursos.get_contenido_recurso(recurso);
}

void Server::guardar_recurso(const std::string& recurso,
                            const std::string& contenido){
  this->recursos.guardar_recurso(recurso,contenido);
}
