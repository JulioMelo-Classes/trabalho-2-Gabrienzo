#include "../include/Servidor.h"


/*TODO implementação da classe*/
unsigned int idserver=1;

Servidor::Servidor(Usuario* dono, std::string nome){
  dono_servidor = dono;
  nome_servidor = nome;
  id = idserver;
  idserver++;
}

std::string Servidor::getNome(){
  return nome_servidor;
}

void Servidor::setDesc(std::string desc){
  descricao_servidor = desc;
}

std::string Servidor::getDesc(){
  return descricao_servidor;
}

void Servidor::setCodConvite(std::string codConvite){
  codigoConvite = codConvite;
}

std::string Servidor::getCodConvite(){
  return codigoConvite;
}

unsigned int Servidor::getId(){
  return id;
}

void Servidor::insertCanal(CanalTexto canal){
  canaisTexto.push_back(canal);
}

void Servidor::listCanais(){
  for(auto &canal : canaisTexto){
    std::cout << "-> " << canal.getNome() << std::endl;
  }
}

void Servidor::deleteCanal(std::string nome){
   for(auto it=canaisTexto.begin();it!=canaisTexto.end();it++){
      if(it->getNome() == nome){
        canaisTexto.erase(it);
        break;
      }
  }
}

unsigned int Servidor::getcanalId(std::string nome){

  for(auto &canal : canaisTexto){
    return canal.getId();
  }
  return 0;
}

std::string Servidor::getcanalNome(unsigned int id){
  std::string nome;

  for(auto &canal : canaisTexto){
    if(canal.getId() == id){
      nome = canal.getNome();
      break;
    }
  }
  
  return nome;
}

unsigned int Servidor::getDono(){
  return dono_servidor->getId();
}

unsigned int Servidor::getcanalDono(unsigned int id){
  unsigned int dono;

  for(auto &canal : canaisTexto){
    if(canal.getId() == id){
      dono = canal.getDono();
      break;
    }
  }

  return dono;
}

void Servidor::serverMensagem(unsigned int idcanal, Mensagem msg){

  for(auto &canal : canaisTexto){
    if(canal.getId() == idcanal){
      canal.sendMensagem(msg);
      break;
    }
  }

}

void Servidor::listMensagens(unsigned int idcanal){

  for(auto &canal : canaisTexto){
    if(canal.getId() == idcanal){
      canal.listMensagens();
    }
  }
  
}