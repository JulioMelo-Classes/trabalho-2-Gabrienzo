#include "Usuario.h"

/*TODO implementação da classe*/

Usuario::Usuario(std::string email, std::string senha, std::string nome){
    m_nome = nome;
    m_senha = senha;
    m_email = email;
}

std::string Usuario::getEmail(){
    return m_email;
}