#ifndef SERVIDOR_H
#define SERVIDOR_H

#include "Usuario.h"
#include "CanalTexto.h"

// Servidor concentra todas as operações realizadas a partir da criação de um servidor
class Servidor {

  private:
    unsigned int id;
    Usuario* dono_servidor;
    std::string nome_servidor;
    std::string descricao_servidor = "";
    std::string codigoConvite = "";
    std::vector<CanalTexto> canaisTexto;
    std::vector<Usuario*> participantes;

  public:

    /*! Construtor padrão da classe Servidor
      @param dono o dono do servidor criado
      @param nome o nome do servidor criado
     */
    Servidor(Usuario* dono, std::string nome);

    /*! altera o valor da variavel descricao_servidor para o valor recebido
      @param desc a descrição na qual o servidor vai receber
     */
    void setDesc(std::string desc);

    /*! altera o valor da variavel codigoConvite para determinada frase que servirá para encontrar o canal por outros usuários
      @param codConvite o código de convite criado pelo criador do servidor
     */
    void setCodConvite(std::string codConvite);

    /*! Retorna o valor contido na variavel nome_servidor.
     @return nome cadastrado para o servidor
     */
    std::string getNome();

    /*! Retorna o valor contido na variavel descricao_servidor.
      @return descricao cadastrada para o servidor
     */
    std::string getDesc();

    /*! Retorna o valor contido na variavel condigoConvite.
      @return codigo cadastrado para localização do canal no servidor
     */
    std::string getCodConvite();

    /*! Retorna o valor contido na variavel dono_servidor.
      @return nome do dono do servidor
     */
    unsigned int getDono();

    /*! Retorna o valor contido na variavel id.
      @return id do servidor
     */
    unsigned int getId();

    /*! função que adiciona o canal no vector de canais canaisTexto
      @param o canal na qual deseja se adicionar na lista de canais daquele servidor
    */
    void insertCanal(CanalTexto canal);
    
    /*! função que deleta o canal passado retirando ele da lista de canais criados
      @param o nome do canal na qual deverá ser deletado da lista de canais criados
     */
    void deleteCanal(std::string nome);

    /*! função que lista todos os canais criados em um determinado servidor que o usuário se encontra logado
     */
    void listCanais();
    
    /*! funçãO que retorna o nome do canal baseado no valor de id passado como parametro
      @param id o id do canal que se deseja receber o nome
      @return nome do canal do id passado
     */
    std::string getcanalNome(unsigned int id);

    /*! função que retorna o id do canal a partir do nome que foi passado como parametro
      @param nome o nome do canal na qual se deseja receber o id
      @return id do canal que tem o nome passado pelo parametro nome
     */
    unsigned int getcanalId(std::string nome);

    /*! função que retorna um valor inteiro informando se o usuário é o dono ou não daquele canal/servidor
      @param id variavel passada como parametro equivalente ao id do usuário
      @return valor inteiro informando se é dono ou não é dono
     */
    unsigned int getcanalDono(unsigned int id);

    /*! Envia uma mensagem no canal na qual o usuário se encontra logado
      @param mensagem a mensagem na qual o usuário enviou em um determinado canal de texto
     */
    void serverMensagem(unsigned int idcanal, Mensagem msg);

    /*! Lista todas as mensagens de um canal de texto
      @param id canal
     */
    void listMensagens(unsigned int idcanal);

    
};

#endif