# 🎮 Tetris em C++

Um projeto de um jogo inspirado no clássico **Tetris**, desenvolvido em C++ e executado diretamente no terminal do Windows. O objetivo é controlar as peças que caem, encaixá-las corretamente e completar linhas para limpar o tabuleiro.

## 📋 Sobre o projeto

Este projeto foi desenvolvido utilizando conceitos fundamentais da programação em C++, como funções, vetores, matrizes, estruturas de repetição, condicionais e manipulação de entradas do teclado.

O jogo possui um tabuleiro de 10 colunas por 20 linhas, no qual as peças caem automaticamente e podem ser movimentadas e rotacionadas pelo jogador.

## ✨ Funcionalidades

- 🎲 Geração aleatória de peças.
- ↔️ Movimentação das peças para a esquerda e para a direita.
- 🔄 Rotação das peças.
- ⬇️ Descida manual e queda instantânea.
- 🧱 Detecção de colisões com as paredes, o chão e outras peças.
- 🧹 Remoção automática de linhas completas.
- ⏱️ Queda automática das peças em intervalos de tempo.
- 💀 Detecção de fim de jogo (*Game Over*).

## 🕹️ Controles

| Tecla | Ação |
|---|---|
| `A` | Move a peça para a esquerda |
| `D` | Move a peça para a direita |
| `W` | Gira a peça |
| `S` | Desce a peça manualmente |
| `ESPAÇO` | Faz a peça cair instantaneamente |
| `Q` | Encerra o jogo |

## 🛠️ Tecnologias utilizadas

- **Linguagem:** C++
- **Bibliotecas:** `iostream`, `vector`, `conio.h`, `chrono` e `windows.h`
- **Ambiente de execução:** Terminal do Windows
- **Compilador recomendado:** GCC (MinGW-w64) ou outro compilador compatível com C++ no Windows.

## 💻 Como executar o projeto

### 1. Pré-requisitos

Instale um compilador C++ compatível com Windows, como o GCC por meio do MinGW-w64.

### 2. Salve o código

Salve o código-fonte em um arquivo chamado `main.cpp`.

### 3. Compile o programa

Abra o terminal na pasta do projeto e execute:

```bash
g++ main.cpp -o tetris.exe
```

### 4. Execute o jogo

No terminal do Windows, execute:

```bash
.\tetris.exe
```

O jogo será iniciado no próprio terminal.

> **Observação:** o projeto utiliza as bibliotecas `conio.h` e `windows.h`, além de comandos específicos do Windows. Por isso, a execução requer um ambiente compatível com essas funcionalidades.

## 🧠 Conceitos de programação aplicados

Durante o desenvolvimento, são utilizados conceitos importantes para a construção de jogos e aplicações em C++:

- **Matrizes:** representação do tabuleiro e das peças.
- **Vetores:** armazenamento das diferentes formas das peças.
- **Funções:** organização da lógica de movimentação, rotação, colisão e remoção de linhas.
- **Estruturas condicionais:** validação dos movimentos e identificação de colisões.
- **Laços de repetição:** atualização contínua do jogo e verificação do tabuleiro.
- **Manipulação de tempo:** controle da queda automática das peças.
- **Entrada pelo teclado:** interação do jogador com o jogo.

## 🎯 Objetivo

O objetivo deste projeto é praticar a lógica de programação e os fundamentos da linguagem C++, desenvolvendo um jogo funcional com movimentação, colisões e atualização dinâmica do tabuleiro.

---

**Desenvolvido como projeto de estudo em C++.**
