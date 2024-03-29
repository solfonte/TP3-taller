#ifndef __RECURSOS_PROTEGIDOS_H__
#define __RECURSOS_PROTEGIDOS_H__

#include <map>
#include <string>
#include <mutex>

class Recursos_protegidos{
  private:
    std::string root_file;
    std::map<std::string,std::string> recursos;
    std::mutex m;
  public:
    explicit Recursos_protegidos(const std::string& root_file):
      root_file(root_file),
      m()
      {}
    Recursos_protegidos(Recursos_protegidos&& other);
    std::string get_contenido_recurso(const std::string& recurso);
    void guardar_recurso(const std::string& recurso,
                        const std::string& contenido);
    std::string get_contenido_archivo_root();
};

#endif
