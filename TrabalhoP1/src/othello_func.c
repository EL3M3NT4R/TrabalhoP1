#include "../headers/othello_func.h"

// Tamanho do tabuleiro

#define LINHAS 8
#define COLUNAS 8


// Defines de posições no tabuleiro
#define PRETA 0
#define BRANCA 1
#define VAZIA 2
#define JOGAVEL 3


//Variaveis de check
int x, y;

enum coordenadas {N, NE, E, SE, S, SO, O, NO};


void init_board (int board[LINHAS][COLUNAS])
{   

    // Preencher o Board
    for(int l=0; l<LINHAS; l++ )
    {
        for(int c = 0; c < COLUNAS; c++)
        {
            board[l][c] = VAZIA;
        }
    }

    // Pretas Iniciais
    board[(LINHAS / 2) - 1][(COLUNAS / 2)-1] = PRETA;
    board[(LINHAS / 2)][(COLUNAS / 2)] = PRETA;

    // Brancas Iniciais
    board[(LINHAS / 2) - 1][(COLUNAS / 2)] = BRANCA;
    board[LINHAS / 2][(COLUNAS / 2) - 1] = BRANCA;



    //Print Inicio de Jogo
    printf("\nOTHELLO GAME\n\n");


    
}


void print_board (int board[LINHAS][COLUNAS])

{
    printf("  A B C D E F G H\n");
    for (int l = 0; l < LINHAS; l++)
    {
        for(int c = 0; c < COLUNAS; c++)
        {
            if(c == 0)
            {
                printf("%i ", l + 1);
            }
            if (board[l][c] == PRETA)
            {
                printf("X ");
            } else if (board[l][c] == BRANCA)
            {
                printf("O ");
            } else 
            {
                printf(". ");
            }                  
        }
        printf("\n");
    }
    printf("\n");
}


int play(int board[LINHAS][COLUNAS], int line, int col, int color)
{
    int verificacao_Jog = 1;
    while (verificacao_Jog)
    {
        ler_Jogada(&x, &y);
        verificacao_Jog = jogada_Valida(board[LINHAS][COLUNAS], &x, &y);
    
        if ( verificacao_Jog == 1)
        {
            puts("Jogada Invalida");
        }

    }

    
    if (verificar_Flips(board, x, y, color) > 0)
    {
        printf("Virei algumas peças : \n");
    }


    return 0;
}


int flanked(int board[LINHAS][COLUNAS], int line, int col, int color)
{


    return 0;
}


int count_flips_dir(int board[LINHAS][COLUNAS],int line, int col,int delta_line,int delta_col, int color)
{
    int cor_Contraria;
    int numero_Pecas_Viradas = 0;
    int linha_Verificar = line + delta_line;
    int coluna_Verificar = col + delta_col;
    
    
    if (color == 0)
    {
        cor_Contraria = 1;
    } else {
        cor_Contraria = 0;
    }
    
    
    
    
    for (int contador = 0; contador < 8; contador ++)
    {
        if (dentro_Board( linha_Verificar , coluna_Verificar) == 1)
        {
            if (board[linha_Verificar][coluna_Verificar] == cor_Contraria){
                linha_Verificar += delta_line;
                coluna_Verificar += delta_col;
                numero_Pecas_Viradas += 1;
            } else if (board[linha_Verificar][coluna_Verificar] == 2){
                return 0;
            } else {
                return numero_Pecas_Viradas;
            }
        } else {
            return 0;
        }
    }

}


void decidir_Jogador(int *var_Turno)
{
    srand(time(0));
    int aleatorio = rand() % 100;
    if (aleatorio >= 50)
    {
        *var_Turno = 1;
    } else 
    {
       *var_Turno = 0;
    }
}


void inicializar_Jogadores(int *TURNO, int *humano_Cor, int *computador_Cor)
{
    if ( *TURNO == 0)
    {
        *humano_Cor = PRETA;
        *computador_Cor = BRANCA;
        printf("As suas peças são as PRETAS!!\n\n");

    } else if ( *TURNO == 1)
    {
        *humano_Cor = BRANCA;
        *computador_Cor = PRETA;
        printf("As suas peças são as BRANCAS!!\n\n");
    }
    else 
    {
        printf("Houve um erro a inciar o TURNO!!\n\n");
    }
}



//LE INPUT E TROCA POR POSIÇAO REAL** DO TABULEIRO
void ler_Jogada(int *user_Input_Linha, int *user_Input_Coluna)
{
    char *userInput;
    userInput = (char *) malloc(sizeof(char) * 20);
    puts("Escolha o seu movimento. Por exemplo: 5F");
    scanf("%s", userInput);
    char s[2];
    strncpy(s, userInput, 1);
    strcat(s, "\0");
    *user_Input_Linha = atoi(s);
    *user_Input_Coluna = ((int)userInput[1]) - 64;
    free(userInput);
}


int verificar_Flips(board, x, y, color)
{
    int virei_Naovirei = 0;
    for (int pos = 1; pos < 9; pos++)
    {
        if (pos == 1)
        {

        }
    }
}


int jogada_Valida(int board[8][8], int *line, int *col)
{
    int placeholder = 0;
    placeholder = dentro_Board(line, col);
    if (placeholder == 1){
        placeholder = espaco_Vazio(board, *line, *col);

        if (placeholder == 0){
            return 0;
        }
    }

    return 1;

}

int espaco_Vazio(int board[8][8], int line, int col)
{
    if (board[*line][*col] == 2){
        return 0;
    } else {
        return 1;
    }
}


/*
Recebo board e a posiçao x e y a verificar mais a cor do jogador.
*/
int dentro_Board(int *line, int *col)
{
    //declaro variavel para armazenar a cor da peça contraria


    /*
    Faço 2 Checks:
        1- Linha superior a 0 e inf a 9
        2- Col sup a 0 e inf a 9
    E um check sub..:
        Vejo se esta vazio.

    */
    if ((*line > 0 && *line < 9) && (*col > 0 && *col < 9))
    {
        *line = *line - 1;
        *col = *col - 1;
        return 1;
    } else {
        return 0;
    }
}
