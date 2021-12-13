# Projeto II - Linguaguem de Programação
Repositório contendo as especificações do Trabalho 2 da disciplina de LP1, funcionalidades e executaveis.
especificações dos autores do codigo em [author.md](author.md)

***

# Documento de Especificação
Leia o documento de especificação contido em [Especificação do Trabalho 2](https://docs.google.com/document/d/1Oyu3tvh4NcNcQ907w8Gf9ilSaQMOR-0L8ZSQph2EY8o/edit#).

***

## Como compilar o projeto;
Cmake (Criando, entrando e buildando os arquivos da pasta build):
```console
mkdir build
cd build
cmake ..
cmake --build .
```

***

## Como executar o projeto;
Comandos para dar inicio ao programa:
```console
cd build
./concordo
```

Ou pode criar um arquivo de texto com uma lista de comandos (um por linha) e executar o sistema redirecionando esse arquivo como entrada padrão:
```console
cd build
./concordo < ../data/script_comandos.txt
```

***
  
## Como executar o conjunto dos testes planejados por você (ou grupo).
Deixamos alguns comandos basicos prefeitos em [script_comandos.txt](script_comandos.txt)

para executa-los basta iniciar o programa desta forma:
```console
cd build
./concordo < ../data/script_comandos.txt
```
## Limitações ou funcionalidades não implementadas no programa.

### 1. Limitação: Ao desenvolver o código cada vez mais, notamos que ele estava ficando um pouco grande e talvez desorganizado, se fazendo necessário alguns comentarios durante a criação do código para um melhor direcionamento.

### 2. Funcionalidade não implementada: Um dos poucos problemas foi em relação a não saber quando utilizar copias e quando utilizar referencias, mas ao desenvolver o projeto tivemos um grande aprendizado quanto a isso.
