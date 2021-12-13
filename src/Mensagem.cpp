#include "../include/Mensagem.h"

/*TODO implementação da classe*/
unsigned int idmsg=1;

Mensagem::Mensagem(Usuario* dono, std::string texto){

  enviadaPor = dono;
  conteudo = texto;
  setDataHora();
  id = idmsg;
  idmsg++;
}

void Mensagem::setDataHora(){
  time_t timer;
  struct tm *horarioLocal;
  int dia, mes, ano, hora, min;

  time(&timer); // Obtem informações de data e hora
  horarioLocal = localtime(&timer); // Converte a hora atual para a hora local

  dia = horarioLocal->tm_mday;
  mes = horarioLocal->tm_mon + 1;
  ano = horarioLocal->tm_year + 1900;
  hora = horarioLocal->tm_hour;
  min  = horarioLocal->tm_min;

  std::string data = std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(ano) + " - " + std::to_string(hora) + ":" + std::to_string(min);

  dataHora = data;
}

std::string Mensagem::getDataHora(){
  return dataHora;
}

std::string Mensagem::getConteudo(){
  return this->conteudo;
}

std::string Mensagem::getEnviadapor(){
  return enviadaPor->getNome();
}