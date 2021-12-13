#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include "Usuario.h"
#include "Mensagem.h"

// CanalTexto concentra todas as operações realizadas a partir da criação de canais de texto
class CanalTexto {
  
  private:
    unsigned int id;
    std::string m_nome;
    Usuario* m_dono;
    std::vector<Mensagem> mensagens;
    
  public:

    /*! Construtor padrão da classe CanalTexto
      @param nome o nome do canal de texto
      @param dono a referencia do criador do canal de texto
     */
    CanalTexto(std::string nome, Usuario* dono);

    /*! Retorna o valor contido na variavel m_nome
      @return nome do canal de texto
     */
    std::string getNome();

    /*! Retorna o valor contido na variavel id
      @return id do canal de texto
     */
    unsigned int getId();

    /*! Retorna o valor contido na variavel m_dono
      @return dono nome do dono/criador do canal de texto
     */
    unsigned int getDono();
    
    /*! Envia uma mensagem no canal na qual o usuário se encontra logado
      @param mensagem a mensagem na qual o usuário enviou em um determinado canal de texto
     */
    void sendMensagem(Mensagem mensagem);
    
    /*! Imprime todas as mensagens de um canal.
     */
    void listMensagens();
    
};

#endif