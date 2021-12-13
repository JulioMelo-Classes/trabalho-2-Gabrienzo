#include "../include/Usuario.h"

/*TODO implementação da classe*/
unsigned int iduser=1;

Usuario::Usuario(std::string email, std::string senha, std::string nome){
  m_nome = nome;
  m_senha = senha;
  m_email = email;
  m_id = iduser;
  iduser++;
}

std::string Usuario::getEmail(){
  return m_email;
}

std::string Usuario::getNome(){
  return m_nome;
}

std::string Usuario::getSenha(){
  return m_senha;
}

unsigned int Usuario::getId(){
  return m_id;
}