//DOM-KLMN - Projeto Domino - Etapa 3
//20/08/2023
//GRUPO: F.A.M.I.L.I.A. (Fundacao Amigos da Modernidade Impetuosamente Leviana de Inquietos Anafilaticos)
//Kaua Cordeiro, Luan Capella, Manoela Martedi, Nicolas Mariano

#include "Dom_KLMN_View.h"
int fMenuInicio () //visualizacao do menu
{
	int opc;

    printf("\n+-------------------------------------------------------+\n");
    printf("|                  Jogo de Domino (PUC-SP)              |\n");
    printf("|                                                       |\n");
    printf("| 1. Iniciar jogo (2 jogadores)                         |\n");
    printf("| 2. Iniciar jogo (1 jogador)                           |\n");
    printf("| 0. Sair do jogo                                       |\n");
    printf("+-------------------------------------------------------+\n\n");

	printf("Digite uma opcao: ");
	scanf("%d", &opc);

	return(opc);
}

void fPrint () //Exibir pecas
{
	for (int i = 0; i < MAX; i++)
    {
        printf("[%d|%d] ", peca[i].lado1, peca[i].lado2);
    }
}

void fMensagem (char *msg)
{
	printf("%s", msg);
}

void fMesa ()
{
	printf("\n\n===============\nM E S A:");

	int i, j;
	for (i = 0; i < numeroJogadas; i++)
	{
		for (j = 0; j < MAX; j++)
		{
			if (peca[j].status == 0 && peca[j].pos == i) //se a peca ja tiver sido jogada e for da posicao correta
			{
				printf(" [%d|%d]", peca[i].lado1, peca[i].lado2);
			}
		}
	}
	printf("\n===============\n\n");
}

void fPrintPecas (int jogador)
{
	int indicePeca = 97; int i;
	
	printf("Jogador %d\t Pecas: ", jogador);
	for (i = 0; i < MAX; i++)
	{
		if (peca[i].status == jogador) //se a peca pertencer ao jogador
		{
			printf(" %c.[%d|%d]", indicePeca, peca[i].lado1, peca[i].lado2);
			indicePeca++;
		}
	}
	printf("\n---------------\n\n");
}
