#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>


typedef struct {
    char nome[50];
    int ataque;
    int defesa;
    int hp;
    int nivel;
    int xp;
    int xpnl;
} Personagem;

void exibirEstado(Personagem *p) {
    printf("%s - HP: %d - ATK: %d - DEF: %d \n", p->nome, p->hp, p->ataque, p->defesa);
}

void atacar(Personagem *atacante, Personagem *defensor) {
    int dano = atacante->ataque - defensor->defesa;
    if (dano < 0) {
        dano = 0;
    }
    defensor->hp -= dano;
    printf("%s ataca %s causando %d de dano!\n", atacante->nome, defensor->nome, dano);
}

void subirNivel(Personagem*p) {
	
p ->nivel++;
p->xp = 0;
p->xpnl *= 2;
p->hp += 40;
p->defesa += 15;
p->ataque += 20;

		
	
}

void batalha(Personagem *jogador, Personagem *inimigo) {
    while (jogador->hp > 0 && inimigo->hp > 0) {
    
        printf("Turno do jogador:\n");
        atacar(jogador, inimigo);
        exibirEstado(inimigo);
        if (inimigo->hp <= 0) {
            printf("O inimigo foi derrotado! Você venceu!\n");
            jogador->xp += 50 ;
            printf("você ganhou 50 de experiência\n");
            if (jogador->xp >= jogador->xpnl) {
				subirNivel(jogador);
			}
            
            break;
        }

        
        printf("Turno do inimigo:\n");
        atacar(inimigo, jogador);
        exibirEstado(jogador);
        if (jogador->hp <= 0) {
            printf("Você foi derrotado! Game over!\n");
            break;
        }
    }
}


void continuarHistoria3 (Personagem *jogador, char *mc) {
	
	int escolha;
	
	printf("Com o coração de Adam e Eve na suas mãos, você sente um poder latente em seus braços, despertando um novo poder...\n");
	printf("As ultimas palavras dos dois generais ecoam na sua mente..\n");
	printf("'você irá se arrepender do caminho que escolheu, %s'\n",mc);
	printf("Arsené, volta depois da longa jornada para te dizer uma mensagem..\n");
	printf("Olá denovo, %s, você matou os 3 generais de Dio, e te darei uma nova opção...\n",mc);
	printf("Deseja continuar para o Desafio final?\n");
	printf("1 = Sim e 2 = Não");
	scanf(escolha);
	
		if (escolha = 1) {
			
			printf("Ao entrar no castelo, você morre\n");
			printf("Uma voz ecoa dizendo:- você nunca sairá desse ciclo, %s, hehehehe\n",mc);
			
			
			
		}
		
	else
	{
		printf("você não aceitou a oferta para acabar com o malefício do mundo, logo perdendo sua alma devido ao contrato feito com Arsené\n");
		printf("Ele fala: Você desonrou nosso contrato...%s, agora eu tirarei seu direito de viver...\n ");
		printf("Graças ao coração de Adam e Eve, e a benção de Alice, no momento em que Arsené ia tirar seu direito, você brilha como nunca..\n");
		printf("-O que está acontecendo? você, uma mera alma penada que eu invoquei consegue se opor a mim?!\n");
		printf("Acabou, Arsené, você não continuará controlando a alma dos tolos...A nossa luta finalmente acabou, e Dio, nosso rei, poderá reinar novamente...\n");
		printf("-Não pode ser, eu não po-sso aceitar...\n");
		printf("Arsené é absorvido pela suas mãos..\n");
		printf("você descobre após tudo isso, que você era Dio, El Genes, o verdadeiro Rei dessa Terra\n");
		printf("Com lágrimas no rosto, você agradece aos seus amigos que se sacrificaram por você, e descobre que o verdadeiro mal do mundo era Arsené, que havia te prendido nesse inferno a mais de 100 anos\n");
		printf("Você atingiu o Final Verdadeiro\n");
	}	
	
	
	
	
	
	
}

void continuarHistoria2 (Personagem *jogador, char *mc) {
	printf("Após derrotar a Garota, você pega um bilhete escrito NoteBlock no cadáver de Alice..\n");
	printf("é um cartaz escrito diretamente por...DIO..\n");
	printf("NoteBlock, eu sei que você está tentando matar Arsené sozinha, eu quero que volte imediatamente para a localização que está escrita nesta carta," );
	printf("terá uma reunião com 'Adam' e 'Eve'\n");
	printf("tem um mapa aqui...\n");
	printf("Ouço uma voz do além..");
	printf("%s, você finalmente derrotou o primeiro general de Dio, faltam mais 4, você deve seguir para esta reunião para derrotar Adam e Eve, os generais Gêmeos\n", mc);
	printf("Sem muita escolha, escuto o aviso de Arsené e sigo para o local descrito no mapa\n");
	printf("-\n-\n-\n-\n");
	printf("você encontrou um inimigo!\n");
	
		Personagem inimigo;
        strcpy(inimigo.nome, "Estrupício de Fezes");
        inimigo.ataque = 60;
        inimigo.defesa = 50;
        inimigo.hp = 150;
        exibirEstado(jogador);
        exibirEstado(&inimigo);

        batalha(jogador, &inimigo);
        if (jogador->hp > 0) {
			printf("-\n-\n-\n-\n");
			printf("você encontrou outro inimigo");
			Personagem inimigo;
        strcpy(inimigo.nome, "Estrupício de Fezes");
        inimigo.ataque = 70;
        inimigo.defesa = 60;
        inimigo.hp = 170;
        exibirEstado(jogador);
        exibirEstado(&inimigo);

        batalha(jogador, &inimigo);
        if (jogador->hp > 0) {
			printf("-\n-\n-\n-\n");
			printf("você encontrou umm subordinado de Adam e Eve, parece que já estmaos perto do local de encontro...\n");
			Personagem inimigo;
        strcpy(inimigo.nome, "Pecado Original");
        inimigo.ataque = 62;
        inimigo.defesa = 70;
        inimigo.hp = 200;
        exibirEstado(jogador);
        exibirEstado(&inimigo);

        batalha(jogador, &inimigo);
        if (jogador->hp > 0) {
			printf("-\n-\n-\n-\n");
			printf("Após matar o pecado original, você encontra um Homem de pé no local de encontro...\n");
			printf("-Quem é você? Diz o homem, com uma aura ameaçadora...\n");
			printf("meu nome é %s...e você deve ser Adam ou Eve, certo?\n", mc);
			printf("De fato, meu nome é Adam, o Arauto di El genes\n");
			printf("Sem hesitar, o homem após apresentar-se, pula automaticamente em cima de você\n");
			Personagem inimigo;
        strcpy(inimigo.nome, "Adam");
        inimigo.ataque = 68;
        inimigo.defesa = 75;
        inimigo.hp = 222;
        exibirEstado(jogador);
        exibirEstado(&inimigo);
		batalha(jogador, &inimigo);	
		if (jogador->hp > 0) {
			
			printf("-\n-\n-\n-\n-\n");
			printf("Após matar Adam, ele fala:\n");
			printf("você irá se arrepender de trilhar este caminho, jovem %s....", mc);
			printf("Com suas mãos sujas de sangue, você sente uma pulsasão que te leva para o peito de Adam, onde você arranca o coração\n");
			printf("Com o coração de Adam nas mãos, você recebe uma revelação divina com o caminho para o castelo de Dio, El Genes\n");
			printf("Você continua seguindo o caminho para o castelo, como se uma voz te chamasse para lá...\n");
			printf("após uma longa caminhada, você sente que está próximo do fim de sua jornada....\n");
			printf("O castelo está na sua direção, e há outro homem esperando lá na frente, com lágrimas nos olhos numa face vazia e sem expressão...\n");
			printf("ao chegar perto o homem diz: - Você foi o responsável por matar minha carne, meu sangue...Concedido pelo meu Rei Dio, El genes...., não me resta escolha senão acabar com sua jornada miserável...\n");
			printf("A Batalha está prestes a começar....\n");
			printf("-\n-\n-\n");
				Personagem inimigo;
        	strcpy(inimigo.nome, "Eve");
       	 	 inimigo.ataque = 72;
        	inimigo.defesa = 64;
        	inimigo.hp = 254;
        	exibirEstado(jogador);
        	exibirEstado(&inimigo);
			batalha(jogador, &inimigo);	
		if (jogador->hp > 0) {
			
			continuarHistoria3(jogador, mc);
				
		}
			
			
			
			
		}
		}
		}
		}
		
}




void continuarHistoria(Personagem *jogador, char *mc) {
    int escolha;
    printf("Após derrotar o Estripador de Almas, você continua sua jornada.\n");
    printf("parece que esse era o ultimo inimigo presente na linha de frente do Noteblock...\n");
    printf("No chão há uma pequena criança aos trapos e suja, deseja ajuda-la?\n");
    printf("1 = Sim e 2 = Não\n");
    scanf("%d",&escolha);
   
    if (escolha == 1) {
        printf("você, com sua espada em suas costas, chega perto da pequena garota e percebe que ela não expressa nenhuma emoção ao te ver\n");
        printf("A pequena garota aponta para a direção Norte, onde se encontra a Fortaleza de NoteBlock, ao que parece ela deseja que você vá...\n");
        printf("por ser o único caminho, você decide sem pensar muito em continuar em frente.\n");
        printf("após andar por alguns minutos, você percebeu que a garota continua a te seguir, mesmo depois de salva-la do monstro\n");
        printf("-Qual o Seu nome? Diz a garota\n");
        printf("Meu nome é %s, e o seu?", mc);
        printf("a menina permanece em silêncio...\n");
        printf("Andaste por mais algumas horas, até chegar na entrada no castelo de NoteBlock..\n");
        printf("há um guarda exalando uma aura aterrorizante em sua frente, não há escolha senão enfrenta-lo..!\n");
        
        
        Personagem inimigo;
        strcpy(inimigo.nome, "Cavaleiro Notes");
        inimigo.ataque = 60;
        inimigo.defesa = 30;
        inimigo.hp = 100;

        exibirEstado(jogador);
        exibirEstado(&inimigo);

        batalha(jogador, &inimigo);
        if (jogador->hp > 0) {
        	printf("você sente uma presença assassina o esfaqueando por trás\n");
        	printf("mas antes de ser totalmente esfaqueado, você pula para frente\n");
        	printf("e ao olhar, você observa a pequena garota de antes com um olhar penoso sob você\n");
        	printf("me desculpa, %s, mas eu terei que mata-lo aqui\n");
        	printf("------------BOSS BATTLE------------\n");
        	 Personagem inimigo;
        	strcpy(inimigo.nome, "Alice - A NoteBlock");
        	inimigo.ataque = 90;
       	    inimigo.defesa = 45;
        	inimigo.hp = 170;

        	exibirEstado(jogador);
        	exibirEstado(&inimigo);

       	    batalha(jogador, &inimigo);
        	 if (jogador->hp > 0) {
        	 	continuarHistoria2(jogador, mc);
				
			 }
        	
            
        }
       
    } else if (escolha == 2) {
        printf("Você não ajudou a pequena garota e continou a seguir sua jornada em Direção ao NoteBlock...\n");
        printf("você anda pelo vale dos demônios durante horas e horas, mas não consegue encontrar a localização exata do castelo...\n");
        printf("sem rumo, %s continua a vagar por muito tempo, sem sequer saber onde ir\n", mc);
        printf("de tanto andar em círculos, você acaba voltando ao início de sua jornada, na vila\n");
        printf("ao entrar na vila, você repara que está tudo mais quieto do que o normal");
        printf("você se encaminha para a casa do Governador...\n");
        printf("ao decorrer da caminhada até a casa do Governador, você percebe manchas de sangue por todo o chão...\n");
        printf("lentamente ao abrir a porta, você enxergar um verdadeiro genocídio, com todos os membros restantes da vila totalmente massacrados e mortos...\n");
        printf("Ao olhar ao redor, você vê a cabeça do Governador em uma mesa distante, com uma pequena pessoa ao seu lado\n");
        printf("ao se aproximar, você vê a pequena garota que havia visto mais cedo, com seu vestido totalmente sujo de sangue, e um olhar frio e vazio no rosto...\n");
        printf("você pergunta o nome dela, com um tom de raiva...\n");
        printf("-Meu nome é Alice, mas também sou conhecida como NoteBlock...\n");
        printf("-Você deve ser o infeliz invocado pela Sala de Veludo, que lástima\n" );
        printf("Te aviso logo, se continuar a sua jornada, terei que te matar, tem certeza que deseja prolongar essa miserável vida que sequer pertence a você?\n");
        printf("1 = Sim e 2 = Não\n");
        scanf("%d",&escolha);
          
        if (escolha == 1) {
            printf("você decide lutar!");
            printf("Isso não vai acabar assim disse %s\n",mc);
             Personagem inimigo;
        	strcpy(inimigo.nome, "??????");
        	inimigo.ataque = 80;
       	 inimigo.defesa = 35;
        	inimigo.hp = 140;

        exibirEstado(jogador);
        exibirEstado(&inimigo);

        batalha(jogador, &inimigo);
        if (jogador->hp > 0) {
			continuarHistoria2(jogador, mc);
		}
            
        } else {
            printf("você aceita a oferta de Alice e decide entregar sua própria vida, assim se libertando de Arsené e da Sala de Veludo, tornando-se uma alma livre\n");
            printf("final 1");
        }
    } 
}


int main() {
    setlocale(LC_ALL, "portuguese");

    int n1, n2, n3;
    char mc[50];

    printf("Seja bem vindo ao 'DemonLord Castle'\n");
    printf("Você foi escolhido para trilhar uma jornada de dor e sofrimento em busca de redenção, e para isso deve encarar o Rei Demônio\n");
    printf("Você não possui escolha além de embarcar na trágica estória e cumprir o seu Dever\n");
    printf("Deseja iniciar o Jogo? 1 = Sim e 2 = Não\n");
    scanf("%d", &n1);

    if (n1 == 1) {
        printf("Você escolheu participar do jogo, digite o nome do seu personagem:\n");
        scanf("%s", mc);
        printf("Então seu nome é %s? Meu nome é Arsené, sou o Arauto que tudo vê, aquele que te guiará nessa breve jornada\n", mc);
        printf("Você deve seguir para o castelo de Dio, o Rei demônio que há tempos devasta nosso mundo\n");
        printf("Está pronto para partir, %s? 1 = Sim e 2 = Não\n", mc);
        scanf("%d", &n2);

        if (n2 == 1) {
            printf("Você partiu em sua jornada miserável, com uma espada de aço e uma armadura enferrujada.\n");
            printf("Você anda por um tempo, por uma sombria e melancólica floresta com cadáveres pendurados em todas as árvores.\n");
            printf("Dio, El Genes adora violência, um verdadeiro brutamontes destruidor que faz carnificina onde quer que ele e seus 5 generais passem\n");
            printf("Após andar por um longo tempo, você encontra uma pequena vila com pouco mais de 20 habitantes, deseja adentrar na vila? 1 = Sim e 2 = Não\n");
            scanf("%d", &n3);

            if (n3 == 1) {
                printf("Você entra na vila e se apresenta ao governador local: Meu nome é %s\n", mc);
                printf("Cético, ao ver uma alma viva por aquelas redondezas, o governador pergunta se você é das tropas do NoteBlock\n");
                printf("Perguntando-se quem seria NoteBlock, você pergunta ao governador, com um tom de dúvida\n");
                printf("Não brinque comigo, garoto! NoteBlock é aquele responsável por destruir toda essa região e enforcar todos os habitantes na floresta!\n");
                printf("Você não parece má gente, se deseja ajudar de alguma forma, siga para o vale dos demônios a partir da saída dos fundos da vila, não haverá muitos inimigos\n");
                printf("Após o aviso do governador, você decide seguir o caminho recomendado, vendo que ainda havia brilho de esperança nos olhos do velho homem\n");
                printf("Após andar um tempo, você encontra o seu primeiro inimigo...\n");

                Personagem jogador;
                strcpy(jogador.nome, mc);
                jogador.ataque = 50;
                jogador.defesa = 20;
                jogador.hp = 100;

                Personagem inimigo;
                strcpy(inimigo.nome, "Estripador de Almas");
                inimigo.ataque = 20;
                inimigo.defesa = 10;
                inimigo.hp = 80;

                exibirEstado(&jogador);
                exibirEstado(&inimigo);

                batalha(&jogador, &inimigo);
                if (jogador.hp > 0) {
                    continuarHistoria(&jogador, mc);
                }
            } else {
                printf("Você entrou no caminho maldito, e está cercado de difíceis oponentes\n");
                printf("que pena! ao desviar da vila você foi perseguido por um ser com uma foice e ao adentrar em uma caverna no momento  da fulga e acabou pisando em um circulo mágico antigo que acabou teleportando-o aos aposentos do rei demônio\n");
				printf("mas você estava muito fraco para enfretá-lo e acabou sendo destroçado por ele.\n");
            }
        } else {
            printf("Se não está pronto, então tudo que te espera em sua miserável vida é a morte, como o administrador da Sala de Veludo, não posso permitir que viva após conhecer o segredo...\n");
            printf("Você morreu\n");
            printf("Fim de Jogo\n");
        }
    } else {
        printf("Você é um total Perdedor\n");
    }

    return 0;
}