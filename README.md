# Compiler

> Esse compilador está sendo desenvolvido durante a matéria de Compiladores do curso de Bacharelado em Sistemas de Informação, da Universidade de Pernambuco, durante o período de 2022.1.

## Sobre

Compilador básico escrito em Python, utilizando-se do paradigma imperativo, dedicando-se a compilar uma suposta linguagem parecida com a linguagem C. 

Esse compilador foca nas partes do Frontend de um compilador, visando no final até a parte de Geração de Código Intermediário.

Esse compilador ainda está em desenvolvimento, por enquanto apenas o Analisador Léxico está implementado, as outras partes do compilador estarão sendo desenvolvidas ao longo da matéria.

## Índice

<p align="center">
 <a href="#sobre">Sobre</a> •
 <a href="#índice">Índice</a> • 
 <a href="#features">Features</a> • 
 <a href="#instalação">Instalação</a> •  
 <a href="#autores">Autores</a> 
</p>

## Features

O compilador ainda está em desenvolvimento e por enquanto apenas o analisador léxico e a tabela de símbolos estão desenvolvidos. Conforme a matéria de Compiladores for sendo desenvolvida, as outras partes do compilador vão sendo desenvolvidas.

-   [x] Analisador Léxico.
-   [x] Tabela de Símbolos.
-   [ ] Analisador Sintático.
-   [ ] Gerador de Código Intermediário.

## Instalação

### Pré-requisitos

Antes de começar, você vai precisar ter instalado em sua máquina o [Python 3](https://www.python.org).


### Executando o Compilador

Clone este repositório:

```bash
$ git clone https://github.com/AsTunO/UPE---Python_Compiler
```

Acesse a pasta do projeto no terminal:

```bash
$ cd Compiler-Project
```

A partir de agora você pode executar o compilador tanto passando o código fonte como parâmetro:

```bash
$ python3 frontend/Main.py tools/INOUT/source_code.txt
```

Você também pode executar o código simplesmente iniciando o arquivo Main.py e após isso, quando requerido, digitar o caminho do código fonte no seu sistema:
```bash
$ python3 frontend/main.py
```


## Autores

<table>
  <tr>
    <td align="center"><a href="https://github.com/AsTunO"><img src="https://github.com/AsTunO.png" width="100px;" alt=""/><br /><sub><b>Júlio César</b></sub></td>
    <td align="center"><a href="https://github.com/AkiraTorres"><img src="https://github.com/AkiraTorres.png" width="100px;" alt=""/><br /><sub><b>Thiago Torres</b></sub></a></td>
    <td align="center"><a href="https://github.com/Gustavoo151"><img src="https://github.com/Gustavoo151.png" width="100px;" alt=""/><br /><sub><b>Gustavo Oliveira</b></sub></td>
    <td align="center"><a href="https://github.com/JonhPK"><img src="https://github.com/JonhPK.png" width="100px;" alt=""/><br /><sub><b>João Mendes</b></sub></td>
    <td align="center"><a href="https://github.com/Cesar0000"><img src="https://github.com/Cesar0000.png" width="100px;" alt=""/><br /><sub><b>Roberto Cesar</b></sub</td>
  </tr>
</table>
