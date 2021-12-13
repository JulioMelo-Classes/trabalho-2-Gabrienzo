#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <chrono>
#include <ctime>

// Usuario deve concentrar todas as operações com Usuario
class Usuario {
    private:
      std::string m_nome;
      std::string m_senha;
      std::string m_email;
      unsigned int m_id;

    public:

      /*! Construtor padrão da classe Usuario.
      */
      Usuario(std::string email, std::string senha, std::string nome);

      /*! Retorna o valor contido na variavel email do usuário.
        @param email cadastrado pelo usuário
      */
      std::string getEmail();

      /*! retorna o valor contido na variavel nome do usuário.
        @param nome cadastrado pelo usuário
      */
      std::string getNome();

      /*! retorna o valor contido na variavel senha do usuário
        @param senha cadastrada pelo usuário
      */
      std::string getSenha();

      /*! retorna o valor contido na variavel id do usuário
        @param id unico atribuido ao usuário
      */
      unsigned int getId();

};

#endif