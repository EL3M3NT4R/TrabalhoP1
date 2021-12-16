#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>


// Funções do trabalho

void init_board (int board[8][8]);


void print_board (int board[8][8]);


int play(int board[8][8], int line, int col, int color);


int flanked(int board[8][8], int line, int col, int color);


int count_flips_dir(int board[8][8],int line, int col,int delta_line,int delta_col, int color);



// Funções extra

void decidir_Jogador(int *var_Turno );

void inicializar_Jogadores(int *TURNO, int *humano_Cor, int *computador_Cor);

int dentro_Board(int *line, int *col);

int espaco_Vazio(int board[8][8], int line, int col);

int jogada_Valida(int board[8][8], int *line, int *col);

void ler_Jogada(int *user_Input_Linha, int *user_Input_Coluna);


