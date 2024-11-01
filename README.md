# Proj-game-C
Grupo: **Ana Carolina Torchia**
Projeto de gameficação na linguagem C para PIF

2. Nome da disciplina: Programação Imperativa e Funcional - 2024.2.

3. Nome da instituição de ensino: CESAR School.

4. Nome do jogo desenvolvido (Joguete).

5. Instruções detalhadas para compilar e executar o jogo.

6. Breve descrição do jogo, incluindo as regras e como interagir com ele.
7. Aqui está uma descrição em português das mecânicas de jogo:

### Descrição das Mecânicas de Jogo

O jogo é um RPG baseado em texto que incorpora elementos de combate e progressão de personagem. O jogador assume o papel de Dio, buscando derrotar diversos inimigos e chefes para chegar à confrontação final. As mecânicas principais incluem:

1. Estatísticas do personagem: O jogador possui atributos como Vida, Ataque, Defesa, Nível, XP e XP necessário para o próximo nível.

2. Sistema de combate: As batalhas ocorrem em rodadas alternadas entre o jogador e os inimigos, com cálculo de dano baseado nas habilidades de ataque e defesa.

3. Progressão de nível: Quando o jogador ganha XP suficiente, pode aumentar de nível, elevando suas estatísticas.

4. Avanço narrativo: O jogo progride através de uma história envolvendo encontros com vários personagens e locais.

5. Opções de escolha: Em certos pontos, o jogador é solicitado a tomar decisões que influenciam o avanço da história.

### Implementação

O jogo utiliza a linguagem de programação C e implementa as seguintes estruturas e funções:

1. Estrutura `Personagem`: Representa personagens com atributos como nome, Vida, Ataque, Defesa, Nível e XP.

2. Funções para operações de personagem:
   - `exibirEstado`: Exibe o status do personagem
   - `atacar`: Calcula e aplica dano durante o combate
   - `subirNivel`: Gerencia o aumento de nível e o aumento das estatísticas
   - `batalha`: Gestiona o combate em rodadas entre personagens

3. Funções principais do jogo:
   - `continuarHistoria2`: Avança na história após derrotar um chefe
   - `continuarHistoria3`: Apresenta o desafio final e o cenário de encerramento

4. Interação do usuário:
   - O jogo solicita escolhas ao jogador em certos pontos, permitindo que ele influencie o avanço da narrativa.

As mecânicas do jogo permitem o crescimento do personagem e decisões que impactam a história, criando uma experiência imersiva para o jogador.


Link do repositório:https://github.com/caroltorchia/Proj-game-C


