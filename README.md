# Proj-game-C
Grupo: **Ana Carolina Torchia**
Projeto de gameficação na linguagem C para PIF

## Sumário

2. Nome da disciplina: Programação Imperativa e Funcional - 2024.2.

3. Nome da instituição de ensino: CESAR School.

4. Nome do jogo desenvolvido (Enforcados - Jogo da forca).

5. Instruções detalhadas para compilar e executar o jogo.

6. Breve descrição do jogo, incluindo as regras e como interagir com ele.

## Enforcados - A forca Suprema

Enforcados - A forca Suprema é um jogo da forca (Hangman) que incorpora elementos de adivinhação e progressão de dificuldade. O jogador deve adivinhar letras de uma palavra secreta antes de esgotar suas tentativas.
7. Aqui está uma descrição em português das mecânicas de jogo:

### Descrição das Mecânicas de Jogo

As mecânicas principais incluem:

1. Palavras a serem adivinhadas: O jogador tenta descobrir uma palavra secreta letra por letra.

2. Tentativas limitadas: O jogador tem um número limitado de tentativas para adivinhar a palavra.

3. Feedback visual: A cada tentativa, o jogador recebe feedback sobre as letras adivinhadas corretamente e as que não estão na palavra.

4. Avanço de dificuldade: O jogo pode incluir diferentes níveis de dificuldade com palavras de diferentes comprimentos.

5. Opções de escolha: O jogador pode escolher categorias de palavras que influenciam a experiência de jogo.

### Implementação

O jogo utiliza a linguagem de programação C e implementa as seguintes estruturas e funções:

1. Estrutura `Game`: Representa o estado do jogo com atributos como palavra a ser adivinhada, exibição da palavra, tentativas permitidas, pontuação do jogador, limite de tempo e nível de dificuldade.

### Build do projeto

Para compilar o projeto, utilize o seguinte comando no terminal:
```bash
$ make
```
Este comando irá compilar todos os arquivos necessários e gerar os executáveis no diretório apropriado.

### Executar o jogo

Após a compilação bem-sucedida, você pode iniciar o jogo com o seguinte comando:
```bash
$ ./bin/enforcados
```
Certifique-se de que o diretório `bin` contém o executável `enforcados`. Se houver algum erro durante a execução, verifique se a compilação foi realizada corretamente.

Link do repositório:https://github.com/caroltorchia/Proj-game-C
