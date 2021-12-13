#include "../include/Sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

#include "../include/Sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>

/* COMANDOS */
string Sistema::quit() {
  return "Saindo...";
}

bool Sistema::verif_login(int id){
  for(auto it=usuariosLogados.begin();it!=usuariosLogados.end();it++){
    if(it->first == id){
      return true;
    }
  }

  return false;
}

string Sistema::create_user (const string email, const string senha, const string nome) {

  //verificar se o email ja é cadastrado
	for(auto &user : usuarios){
	
		if(user->getEmail() == email){
			return "Email ja cadastrado!";
		}
	}
  
  //criar usuario
	Usuario* usuario = new Usuario(email,senha,nome);
	usuarios.push_back(usuario);

	return "Usuário criado!";
}

std::string Sistema::delete_user (const std::string email, const std::string senha){

  for(auto &user : usuarios){

    if(email == user->getEmail()){
      if(senha == user->getSenha()){
        if(verif_login(user->getId()) == true){
          return "O usuario está logado!";

        }else{
          delete user;
          return "Usuario deletado com sucesso!";
        
        }
      }else{
        return "Senha incorreta...";

      }
    }
  }
  
	return "Email não encontrado...";
}

string Sistema::login(const string email, const string senha) {

  for(auto &user : usuarios){
    if(email == user->getEmail()){
      if(senha == user->getSenha()){
        if(verif_login(user->getId()) == true){
          return "O usuario já está logado!";
        
        }else{
          usuariosLogados.insert({user->getId(), pair<unsigned int,unsigned int>(0,0)});

        }

        return "Usuario logado!";

      }else{
        return "Senha incorreta...";
      }
    }
  }
  
	return "Email não encontrado...";
}

string Sistema::disconnect(int id) {

  for(auto user : usuariosLogados){
      if(user.first == id){
        std::string dis_email;
        usuariosLogados.erase(id);

        for(auto email : usuarios){
          if(email->getId() == id){
            dis_email = email->getEmail();
            break;
          }
        }

        return "Usuario " + dis_email + " Desconectado!";
      }
    }

	return "Usuario não está logado!";
}

string Sistema::create_server(int id, const string nome) {

  if(verif_login(id) == false){
    return "O usuario não está logado...";
    
  } else {
    for(auto &name : Servidores){
      if(name.getNome() == nome){
        return "Erro na criação do servidor: servidor com nome já existente...";
        
      }
    }
    for(auto &user : usuarios){
      if(user->getId() == id){
        Servidor servidor(user, nome);
        Servidores.push_back(servidor);
            
        return "Servidor \"" + nome + "\" criado!";
      }
    }    
  }
    
	return "Erro ao criar o servidor!";
}

string Sistema::set_server_desc(int id, const string nome, const string descricao) {

  if(verif_login(id) != true){
    return "O usuario não está logado...";
    
  }else{
    for(auto it=Servidores.begin();it!=Servidores.end();it++){
      if(it->getNome() == nome){
        it->setDesc(descricao);
        return "Descrição do servidor \"" + nome + "\" modificada!";
        
      }
    }
  }

	return "Erro! Servidor não encontrado...";
}

string Sistema::set_server_invite_code(int id, const string nome, const string codigo) {

  if(verif_login(id) != true){
    return "O usuario não está logado...";
    
  } else {
    for(auto it=Servidores.begin();it!=Servidores.end();it++){
      if(it->getNome() == nome){
        it->setCodConvite(codigo);
          
        return "Código de convite do servidor \"" + nome + "\" modificado com sucesso!";
      }
    }
  }

	return "Erro! Servidor não encontrado...";
}

string Sistema::list_servers(int id) {
	if(verif_login(id) == false){
    return "O usuario não está logado...";

  } else {
    std::cout << "Lista de Servers:" << std::endl;
    for(auto it=Servidores.begin(); it!=Servidores.end(); it++){
      std::cout << "-> " << it->getNome() << std::endl;
      
    }
    
  }
    
  return "";
}

string Sistema::remove_server(int id, const string nome) {

  if(verif_login(id) == false){
    return "O usuario não está logado...";
    
  }else{
    for(auto it=Servidores.begin();it!=Servidores.end();it++){
      if(it->getDono() == id){
        if(it->getNome() == nome){
        Servidores.erase(it);

        for(auto &map : usuariosLogados){
          if(map.second.first == it->getId()){
            usuariosLogados[map.first] = std::pair<unsigned int,unsigned int>(0, 0);
          }
        }
        
        return "Servidor \"" + nome + "\" removido com sucesso!";
        }
      } else {
        return "Você não é o dono do servidor" + nome +"...";
      }
    }
  }

	return "Erro! Servidor não encontrado...";
}

string Sistema::enter_server(int id, const string nome, const string codigo) {
  
  if(verif_login(id) != true){

    return "O usuario não está logado...";
  } else {
    for(auto &server : Servidores){
      if(server.getNome() == nome && server.getCodConvite() == codigo){
        usuariosLogados[id] = std::pair<unsigned int,unsigned int>(server.getId(), 0);

        return "Entrou no servidor " + server.getNome() + "!";
      }
      if(server.getNome() == nome && server.getCodConvite() != codigo){

        return "Erro! Codigo convite incorreto...";
      }
    }
  }
  
	return "Erro! Servidor não encontrado...";
}

string Sistema::leave_server(int id, const string nome) {

  if(verif_login(id) != true){

    return "O usuario não está logado...";
  } else {
    for(auto &server : Servidores){
      if(server.getNome() == nome){
        usuariosLogados[id] = std::pair<unsigned int,unsigned int>(0, 0);

        return "Saiu do servidor " + server.getNome() + "!";
      }
    }
  }
  
	return "Erro! Servidor não encontrado...";
}

string Sistema::list_participants(int id) {

  if(verif_login(id) == false){

    return "O usuario não está logado...";
  } else if(usuariosLogados[id].first != 0){
    std::cout << "Lista de Usuarios nesse servidor:" << std::endl;
  	for(auto &it : usuariosLogados){
      if(it.second.first == usuariosLogados[id].first){
        for(auto &user : usuarios){
          if(it.first == user->getId()){
            std::cout << "-> " << user->getNome() << std::endl;
            
          }
        }
      }
    }
  } else {
    return "O usuario não esta conectado a um servidor...";

  }

	return "";
}

string Sistema::list_channels(int id) {

  if(verif_login(id) == false){

    return "O usuario não está logado...";
  } else {
    //checando o nome do usuario a partir do ID
    for(auto &user : usuarios){
      if(id == user->getId()){

        //checando o servidor que o usuario se encontra a partir do nome encontrado pelo ID
        for(auto &server : Servidores){
          if(usuariosLogados[id].first == server.getId()){
            server.listCanais();
            return "";
          }
        }
      }
    }
  }

	return "O usuario não está em nenhum servidor...";

}

string Sistema::create_channel(int id, const string nome) {

  if(verif_login(id) == false){

    return "O usuario não está logado...";
  } else {
    //checando o nome do usuario a partir do ID
    for(auto &user : usuarios){
      if(id == user->getId()){

        //checando o servidor que o usuario se encontra a partir do nome encontrado pelo ID
        for(auto &server : Servidores){
          if(usuariosLogados[id].first == server.getId()){
            CanalTexto canaltexto(nome,user);
            server.insertCanal(canaltexto);

            return "Canal \"" + nome + "\" criado!";
          }
        }
      }
    }
  }

	return "O usuario não está em nenhum servidor...";
}

string Sistema::remove_channel(int id, const string nome) {

  if(verif_login(id) == false){

    return "O usuario não está logado...";
  } else {
    //checando o nome do usuario a partir do ID
    for(auto &user : usuarios){
      if(id == user->getId()){

        //checando o servidor que o usuario se encontra a partir do nome encontrado pelo ID
        for(auto &server : Servidores){
          if(server.getDono() == id || server.getcanalDono(usuariosLogados[id].second) == id){
            if(usuariosLogados[id].first == server.getId()){
            server.deleteCanal(nome);
            for(auto &map : usuariosLogados){
              if(map.second.first == server.getId()){
                usuariosLogados[map.first] = std::pair<unsigned int,unsigned int>(server.getId(), 0);
              }
            }
            
              return "Canal \"" + nome + "\" removido!";
            }
          } else {
            return "Você não é o dono do canal ou do servidor";
          }
        }
      }
    }
  }

	return "O usuario não está em nenhum servidor...";
}

string Sistema::enter_channel(int id, const string nome) {

  if(verif_login(id) == false){

    return "O usuario não está logado...";
  } else {
    //checando o nome do usuario a partir do ID
    for(auto &user : usuarios){
      if(id == user->getId()){

        //checando o servidor que o usuario se encontra a partir do nome encontrado pelo ID
        for(auto &server : Servidores){
          if(usuariosLogados[id].first == server.getId()){
            usuariosLogados[id] = std::pair<unsigned int,unsigned int>(server.getId(), server.getcanalId(nome));

            return "Usuário " + user->getEmail() +" entrou no canal " + nome + "!";
          } else if (server.getcanalId(nome) == 0){
            return "Canal não encontrado...";
          }
        }
      }
    }
  }

	return "O usuario não está em nenhum servidor...";
}

string Sistema::leave_channel(int id) {

  if(verif_login(id) == false){

    return "O usuario não está logado...";
  } else {
    //checando o nome do usuario a partir do ID
    for(auto &user : usuarios){
      if(id == user->getId()){

        //checando o servidor que o usuario se encontra a partir do nome encontrado pelo ID
        for(auto &server : Servidores){
          if(usuariosLogados[id].first == server.getId() && usuariosLogados[id].second != 0){
            std::string nomecanal = server.getcanalNome(usuariosLogados[id].second);

            usuariosLogados[id] = std::pair<unsigned int,unsigned int>(server.getId(), 0);

            return "Usuário " + user->getEmail() +" saiu do canal " + nomecanal + "!";
          } else if (usuariosLogados[id].second == 0){
            return "O Usuário não está em nenhum canal...";
          
          }
        }
      }
    }
  }

	return "O usuario não está em nenhum servidor...";
}

string Sistema::send_message(int id, const string mensagem) {

  if(verif_login(id) == false){

    return "O usuario não está logado...";
  } else {
    //checando o nome do usuario a partir do ID
    for(auto &user : usuarios){
      if(id == user->getId()){

        //checando o servidor que o usuario se encontra a partir do nome encontrado pelo ID
        for(auto &server : Servidores){
          if(usuariosLogados[id].first == server.getId() && usuariosLogados[id].second != 0){
            Mensagem msg(user,mensagem);
            server.serverMensagem(usuariosLogados[id].second, msg);
            return "";
          } else if (usuariosLogados[id].second == 0){
            
            return "O Usuário não está em nenhum canal...";
          }
        }
      }
    }
  }

	return "O usuario não está em nenhum servidor...";
}

string Sistema::list_messages(int id) {
	if(verif_login(id) == false){

    return "O usuario não está logado...";
  } else {
    //checando o nome do usuario a partir do ID
    for(auto &user : usuarios){
      if(id == user->getId()){

        //checando o servidor que o usuario se encontra a partir do nome encontrado pelo ID
        for(auto &server : Servidores){
          if(usuariosLogados[id].first == server.getId() && usuariosLogados[id].second != 0){
            server.listMensagens(usuariosLogados[id].second);
            return "";
          } else if (usuariosLogados[id].second == 0){
            
            return "O Usuário não está em nenhum canal...";
          }
        }
      }
    }
  }

	return "O usuario não está em nenhum servidor...";
}

string Sistema::list_map(int id){
  
  for(auto it : usuariosLogados){
    std::cout << it.first << " | " << it.second.first << " | " << it.second.second << std::endl;
  }

  return "";
}