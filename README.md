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
Deixamos alguns comandos basicos prefeitos em [script_comandos.txt](/data/script_comandos.txt)

para executa-los basta iniciar o programa desta forma:
```console
cd build
./concordo < ../data/script_comandos.txt
```
## Limitações ou funcionalidades não implementadas no programa.

### 1. Limitação: Ao desenvolver o código cada vez mais, notamos que ele estava ficando um pouco grande e talvez desorganizado, se fazendo necessário alguns comentarios durante a criação do código para um melhor direcionamento.

### 2. Funcionalidade não implementada: Um dos poucos problemas foi em relação a não saber quando utilizar copias e quando utilizar referencias, mas ao desenvolver o projeto tivemos um grande aprendizado quanto a isso.

# Avaliação
## Funcionalidades
- A1.2 ok
- A1.3 60%
Faltou tratar os casos em que o usuário é dono de algum servidor/canal/mensagem
- A1.4 ok
- A2.1 ok
- A2.2 ok
- A2.3 60%
Aqui você precisava checar quem era o dono
- A2.4 60%
Aqui você precisava checar quem era o dono
- A2.5 ok
- A2.6 ok
- A2.7 40%
Aqui faltou vocês adicionarem o usuário na lista de participantes
- A2.8 ok
- A2.9 30%
Aqui vocês precisavam listar os usuários adicionados ao servidor, veja que um usuário pode estar na lista de participantes sem estar visualizando o servidor em questão, ou mesmo sem estar logados. Assim, vocês não deveriam usar a lista "usuariosLogados" mas sim usar a lista de participantes dentro do servidor.
- B1.1 ok
- B1.2 ok
Aqui vocês poderiam delegar a tarefa de criar o canal para o servidor, não precisando expor o tipo Canal para Sistema.
- B1.3 ok
Aqui tem um erro conceitual, o usuário só entre am um canal do servidor que ele está vendo assim vocês não precisavam atualizar o servidor do usuário, apenas o canal que ele entrou.
- B1.4 ok
- B1.5 ok
- B2.1 ok
- B2.2 ok

## Classes
- Servidor ok
- Canal ok
- Mensagem ok

## Boas Práticas
- Documentação 80%
Faltou documentar os atributos
- Testes nok
A ideia aqui era que vocês enviassem alguns scripts de teste para mostrar as funcionalidades implementadas.
- Organização 75%
Subtrai 25% pela forma como os includes foram usados

## Observações
Fora as interpretações erradas em algumas funções a implementação ficou muito boa, bom trabalho.