#include "../include/CanalTexto.h"

/*TODO implementação da classe*/
unsigned int idcanal=1;

CanalTexto::CanalTexto(std::string nome, Usuario* dono){
  m_nome = nome;
  m_dono = dono;
  id = idcanal;
  idcanal++;
}

std::string CanalTexto::getNome(){
  return this->m_nome;
}

unsigned int CanalTexto::getId(){
  return this->id;
}

unsigned int CanalTexto::getDono(){
  return this->m_dono->getId();
}

void CanalTexto::sendMensagem(Mensagem mensagem){
  mensagens.push_back(mensagem);
}

void CanalTexto::listMensagens(){
  std::cout << "Numero de mensagens neste canal: " << mensagens.size() << std::endl;
  for(auto mensagem=mensagens.begin(); mensagem!=mensagens.end(); mensagem++){  
    std::cout << mensagem->getEnviadapor() << "<" + mensagem->getDataHora() << ">: " << mensagem->getConteudo() << std::endl;
  }
}