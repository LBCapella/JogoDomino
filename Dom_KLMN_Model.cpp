//DOM-KLMN - Projeto Domino - Etapa 3
//20/08/2023
//GRUPO: F.A.M.I.L.I.A. (Fundacao Amigos da Modernidade Impetuosamente Leviana de Inquietos Anafilaticos)
//Kaua Cordeiro, Luan Capella, Manoela Martedi, Nicolas Mariano

#include "Dom_KLMN_Model.h"

typedef struct pecas //estrutura para as pecas
{
	int lado1; int lado2; //valor numerico (1-6) de cada lado
	int pos; //posicao na mesa
	int status; // 1: primeiro jogador,, 2: segundo jogador (ou computador),, 3: para comprar
} valoresPecas;

valoresPecas peca[MAX]; 
valoresPecas aux; //auxiliar para a randomizacao


