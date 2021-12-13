#ifndef MENSAGEM_H
#define MENSAGEM_H

#include "Usuario.h"


// Mensagem concentra todas as operações realizadas a partir da criação de mensagens nos canais de texto
class Mensagem {
  
  private:
    unsigned int id;
    std::string dataHora;
    Usuario* enviadaPor;
    std::string conteudo;

  public:

    /*! Construtor padrão da classe Mensagem
      @param dono é uma referencia do dono que criou a Mensagem
      @param texto é o texto na qual o usuário enviou
     */
    Mensagem(Usuario* dono, std::string texto);

    /*! Altera o valor da variavel dataHora para a hora na qual foi enviada a mensagem do usuário
     */
    void setDataHora();

    /*! Retorna o valor contido na variavel dataHora.
      @return hora na qual a mensagem foi enviada
     */
    std::string getDataHora();
    
    /*! Retorna o nome de quem enviou a mensagem.
      @return string com o nome de quem enviou.
    */
    std::string getEnviadapor();
    
    /*! Retorna o conteudo da mensagem enviada.
      @return string com o texto da mensagem
    */
    std::string getConteudo();

};

#endif