//DOM-KLMN - Projeto Domino - Etapa 3
//20/08/2023
//GRUPO: F.A.M.I.L.I.A. (Fundacao Amigos da Modernidade Impetuosamente Leviana de Inquietos Anafilaticos)
//Kaua Cordeiro, Luan Capella, Manoela Martedi, Nicolas Mariano

#include "Dom_KLMN_View.cpp" 
#include "Dom_KLMN_Controller.h"

void fIniciarJogo () 
{
	fflush(stdin);
	
	int opcMenu;
	
	putchar('\n');
    
    do
	{
		putchar('\n');
		opcMenu = fMenuInicio(); //guarda a opcao escolhida pelo usuario
		
		switch(opcMenu) //opcao para cada saida do menu
		{
			case 1: //inicio com 2 jogadores
				system("cls");
				fGerarDomino();
				fDoisJogadores ();
				break;
			case 2: //inicio com 1 jogador
				{
				system("cls");
				fGerarDomino();
				char msgPrint1[] = "\nFuncao nao implementada.";
				fMensagem (msgPrint1);
				break;
				}
			case 0: //sair do jogo
				{
				system("cls");
				char msgPrint2[] = "\nSaindo...\n";
				fMensagem (msgPrint2);
				break;
				}
			default:
				{
				system("cls");
				char msgPrint0[] = "\nOpcao invalida.";
				fMensagem (msgPrint0);
				break;
				}
		}
	} while (opcMenu != 0); //condicao de parada
}

void fGerarDomino ()
{
	int i, j;
	int n = 0;
	
	for (i = 0; i <= 6; i++) 
	{
        for (j = i; j <= 6; j++) 
		{
            peca[n].lado1 = i;
            peca[n].lado2 = j;
            n++;
        }
    }
}

void fShuffle () 
{
	srand(time(NULL));
	for (int i = 0; i < MAX; i ++)
	{
		int pecaAleatoria = rand() % MAX; 
		aux = peca[i];
		peca[i] = peca[pecaAleatoria];
		peca[pecaAleatoria] = aux;
	}
}

void fSepararPecas () //define status inicial para cada peca
{
	fShuffle ();
	int i;
	for (i = 0; i < MAX; i++)
	{
		if (i < 7)
			peca[i].status = 1; //pecas do primeiro jogador
		else if (i < 14)
			peca[i].status = 2; //pecas do segundo jogador (ou computador)
		else
			peca[i].status = 3; //pecas para comprar
	}
}

void fDoisJogadores ()
{
	fSepararPecas ();
	int J = 1; int numeroJogadas = 0;
	int retorno;
	
	do
	{
		fMesa();
		retorno = fMenuJogador (J);
		
		if (retorno == 0)
		{
			numeroJogadas += 1;
			J = (J == 1) ? 2 : 1;
		}
		else if (retorno == 2)
		{
			J = (J == 1) ? 2 : 1;
		}
		
	} while (retorno != 1);
}

int fMenuJogador (int jogador)
{
	do
	{
		fPrintPecas(jogador);
		char opc[2];

		char msgPrint3[] = "J - Jogar\nC - Comprar\nP - Passar\nS - Sair (fim de jogo)\n";
		fMensagem (msgPrint3);

		do
		{
			char msgPrint4[] = "Opcao: ";
			fMensagem (msgPrint4);
			fflush(stdin);
			scanf("%c", &opc[0]);
			if (opc[0] == '\0')
			{
				char msgPrint0[] = "\nOpcao invalida.";
				fMensagem (msgPrint0);
			}
		}
		while (opc[0] == '\0');

		opc[0] = toupper(opc[0]);

		switch(opc[0])
		{
			case 'J': //jogar uma peca
				if (fJogada(jogador) == 0)
				{
					return 0;
				}
				continue;
			case 'C': //comprar uma peca
				if (fCompra(jogador) == 0)
				{
					return 0;
				}
				continue;
			case 'P': //passar a jogada
			{
				char msgPrint5[] = "\nPassando jogada...";
				fMensagem (msgPrint5);
				return 2; //passar jogada
			}
			case 'S': //finalizar o jogo e voltar ao menu
			{
				char msgPrint6[] = "\nFinalizando jogo...";
				fMensagem (msgPrint6);
				return 1; //sair do jogo
			}
			default:
			{
				char msgPrint0[] = "\nOpcao invalida.";
				fMensagem (msgPrint0);
				continue;
			}
		}

	} while (1);
	
}

int fJogada(int jogador)
{
	char opc[2];
	do
	{
		char msgPrint7[] = "Escolha a Peca para jogar (0 para desistir): ";
		fMensagem (msgPrint7);
		fflush(stdin);
		scanf("%c", &opc[0]);
		if (opc[0] == '\0')
		{
			char msgPrint0[] = "\nOpcao invalida.";
			fMensagem (msgPrint0);
		}
	}
	while (opc[0] == '\0');
	
	if (opc[0] == '0')
	{
		return 1;
	}
	
	return 0;
}

int fCompra(int jogador)
{
	return 0;
}


