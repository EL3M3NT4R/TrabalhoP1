#include "../headers/othello_func.h"

// Tamanho do tabuleiro

#define LINHAS 8
#define COLUNAS 8


// Defines de posições no tabuleiro
#define PRETA 0
#define BRANCA 1
#define VAZIA 2
#define JOGAVEL 3

// VarGlobais

bool PASSOU_VEZ = false;
bool FIM_JOGO = false;
int TURNO;

// Sistema de coordenadas
enum coordenadas {N, NE, E, SE, S, SO, O, NO};

// Estrutura de jogador
struct jogador
{
    int pontos_Total;
    int num_Pecas;
    int cor;

};


int main (int argc, char *argv[]){

    // Variaveis
    int board[LINHAS][COLUNAS];
    struct jogador humano;
    humano.pontos_Total = 2;
    humano.num_Pecas = 2;
    struct jogador computador;
    computador.pontos_Total = 2;
    computador.num_Pecas = 2;
    int lin = 0, col = 0;

    // Inicio

    init_board(board);
    decidir_Jogador(&TURNO);


    inicializar_Jogadores(&TURNO, &humano.cor, &computador.cor);
    print_board(board);

    while (!FIM_JOGO)
    {
        if (TURNO == 0)
        {
            if (computador.cor == 0)
            {
                play(board, lin, col, computador.cor);
            } else {
                play(board, lin, col, humano.cor);
            }
            TURNO = 1;
        } else if (TURNO == 1)
        {
            if (computador.cor == 1)
            {
                play(board, lin, col, computador.cor);
            } else {
                play(board, lin, col, humano.cor);
            }
            TURNO = 0;
        }



        lin = 0;
        col = 0;
        FIM_JOGO = true;
    }







    return 0;
}