#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <string>
#include <string.h>
#include <vector>

class Usuario {
    private:
        std::string m_nome;
        std::string m_senha;
        std::string m_email;

    public:
        Usuario(std::string email, std::string senha, std::string nome);

        std::string getEmail();

};

#endif