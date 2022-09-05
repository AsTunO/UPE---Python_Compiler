#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


#define NUM_NFA 103   // Quantidade de estados do NFA
#define NUM_COLUMN 25  // Quantidade de colunas da vari�vel nfa




// Structs

struct conjunto
{
    int *sts; // Lista de inteiros com o conjunto de estados
    int tm; // Quantidade de estados
};

struct grupo
{
    int gp; // a que grupo da parti��o essa lista se refere
    int *sts; // Lista de inteiros com o conjunto de estados
    int tm; // Quantidade de estados na lista
};

//



// Vari�veis globais

int *partition[500]; // Vai conter a parti��o dos estados do DFA
int partition_in = 0; // Armazena o pr�ximo �ndice vazio na lista partition

struct conjunto map[500];
int map_in = 0;  // Armazena o pr�ximo �ndice vazio na lista map


char *nfa[][NUM_COLUMN] = {                               // Armazena a tabela do NFA  // A primeira coluna precisa ser a da string vazia

/*  0  */ {"1,16,21,31,33,35,37,40,43,49,57,69,71,73,75,77,79,81,83,85,98",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},

/*  1  */ {"2,4",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  2  */ {"",   "3",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  3  */ {"6",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  4  */ {"",   "",   "",   "5",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  5  */ {"6",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  6  */ {"7,15",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  7  */ {"8,10,12",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  8  */ {"",   "9",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  9  */ {"14",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  10  */ {"",   "",   "",   "11",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  11  */ {"14",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  12  */ {"",   "",   "13",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  13  */ {"14",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  14  */ {"7,15",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  15  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},

/*  16  */ {"",   "",   "17",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  17  */ {"18,20",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  18  */ {"",   "",   "19",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  19  */ {"18,20",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  20  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},

/*  21  */ {"",   "",   "22",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  22  */ {"23,25",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  23  */ {"",   "",   "24",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  24  */ {"23,25",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  25  */ {"",   "",   "",   "",   "26",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  26  */ {"",   "",   "27",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  27  */ {"28,30",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  28  */ {"",   "",   "29",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  29  */ {"28,30",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  30  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},

/*  31  */ {"",   "",   "",   "",   "",   "32",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  32  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},

/*  33  */ {"",   "",   "",   "",   "",   "",   "34",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  34  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},

/*  35  */ {"",   "",   "",   "",   "",   "",   "",   "36",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  36  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},

/*  37  */ {"",   "",   "",   "",   "",   "",   "",   "",   "38",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  38  */ {"",   "",   "",   "",   "",   "",   "",   "",   "39",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  39  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},

/*  40  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "41",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  41  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "42",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  42  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},

/*  43  */ {"44,46",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  44  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "45",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  45  */ {"48",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  46  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "47",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  47  */ {"48",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  48  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},

/*  49  */ {"50,53",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  50  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "51",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  51  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "52",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  52  */ {"56",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  53  */ {"",   "",   "",   "",   "",   "",   "",   "54",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  54  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "55",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  55  */ {"56",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  56  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},

/*  57  */ {"58,60,62,65",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  58  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "59",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  59  */ {"68",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  60  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "61",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  61  */ {"68",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  62  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "63",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  63  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "64",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  64  */ {"68",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  65  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "66",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  66  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "67",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  67  */ {"68",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  68  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},

/*  69  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "70",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  70  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},

/*  71  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "72",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  72  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},

/*  73  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "74",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  74  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},

/*  75  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "76",   "",   "",   "",   "",   "",   "",   ""},
/*  76  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},

/*  77  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "78",   "",   "",   "",   "",   "",   ""},
/*  78  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},

/*  79  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "80",   "",   "",   "",   "",   ""},
/*  80  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},

/*  81  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "82",   "",   "",   "",   ""},
/*  82  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},

/*  83  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "84",   "",   "",   ""},
/*  84  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},

/*  85  */ {"86,88",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  86  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "87",   "",   ""},
/*  87  */ {"90",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  88  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "89",   ""},
/*  89  */ {"90",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  90  */ {"91,97",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  91  */ {"92,94",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  92  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "93",   "",   ""},
/*  93  */ {"96",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  94  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "95",   ""},
/*  95  */ {"96",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  96  */ {"91,97",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  97  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},

/*  98  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "99"},
/*  99  */ {"100,102",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  100  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "101"},
/*  101  */ {"100,102",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},
/*  102  */ {"",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   "",   ""},

/*  103  */ {"",   "letter",   "digit",   "_",   ".",   "+",   "-",   "!",   "&",   "|",   "/",   "*",   "=",   "<",   ">",   ";",   "(",   ")",   "[",   "]",   "{",   "}",   "blank",   "tab",   "newline"}
}; //         1        2           3       4      5      6      7      8      9      10     11     12     13     14     15     16     17     18     19     20     21     22       23        24         25

//



// Fun��es

int closure(int *states); // Calcula o closure de alguma estado ou de um conjunto de estados
                           // Recebe uma string contendo os estados pra os quais o e-closure deve ser calculado
                           // Retorna um n�mero inteiro que corresponde na vari�vel map a um conjunto de estados do resultado que foram resultado do c�lculo do e-closure

int *move(int *states, char *input);  // Realiza a opera��o move em apenas um estado ou em um conjunto de estados do NFA
                                        // states recebe uma string contendo o estado ou os estados para os quais se quer realizar a opera��o move
                                        // Se houver mais de um estado eles devem estar separados por v�rgula e a string n�o deve conter espa�os em branco
                                        // input recebe algum s�mbolo do alfabeto do NFA
                                        // Retorna uma string contendo o resultado da opera��o (se houver mais de um estado eles estar�o separados por v�rgula e se n�o houver nenhum uma string vazia ser� retornada)


struct conjunto busca_dfa(int *states); // Faz uma busca para saber quais estados do dfa s�o estados de aceita��o
                              // Recebe os estados de aceita��o do NFA

int mapear(int *states, int tamanho); // Armazena todos os conjuntos distintos de estados de NFA

int b_search(int *list, int states_num, int key); // Realiza uma busca bin�ria em uma lista de inteiros

struct conjunto minimizer(int (*dtran)[NUM_COLUMN - 1], int dstates_num); // Ir� realizar a minimiza��o de estados no DFA

//




int main(void)
{

    int dstates_num = 0; // Armazena quantos estados o DFA possui

    int dtran[500][ (NUM_COLUMN) - 1 ]; // Armazena as transi��es do DFA

    int i, v; // Utilizadas em la�os for
    int u; // Armazena o resultado de e-closure(move())
    int t; // Armazena um unmarked state

    int *imp; // Auxilia na impress�o do resultado

    struct conjunto rt; // Para receber o retorno de busca_dfa
    int ind; // Recebe o resultado da busca bin�ria

    int char_num = 0; // Vai auxiliar na impress�o dos resultados

    struct conjunto deleted_states; // Vai armazenar uma lista dos estados que foram eliminados durante a minimiza��o dos estados do DFA


    closure((int []) {0, -5});
    ++dstates_num;


    for (t = 0; t <= (dstates_num-1); ++t) // Realiza a convers�o e coloca os resultados em dtran
    {

        for (i=1; i<NUM_COLUMN; ++i)
        {
            u = closure(move(map[t].sts, nfa[NUM_NFA][i]));

            if (u > (dstates_num-1)) ++dstates_num;

            dtran[t][i-1] = u;
        }

    }





    rt = busca_dfa((int []) {15, 20, 30, 32, 34, 36, 39, 42, 48, 56, 68, 70, 72, 74, 76, 78, 80, 82, 84, 97, 102, -5}); // O -5 sinaliza o fim da lista


// Para printar o resultado

    for (i=0; i<dstates_num; ++i)
    {
        // Printa o conjunto de estados do NFA
        char_num = 0;
        char_num += printf("{ ");
        for (imp=map[i].sts; *imp != -5; ++imp)
        {
            if ( b_search( (int []) {15, 20, 30, 32, 34, 36, 39, 42, 48, 56, 68, 70, 72, 74, 76, 78, 80, 82, 84, 97, 102, -5}, 21, *imp) != -1)
            {
                char_num += printf("*%d* ", *imp);
            }
            else char_num += printf("%d ", *imp);
        }
        char_num += printf("}");
        for (v=0; v<(110 - char_num) ; ++v) printf(" ");
        //


        // Printa o estado do DFA
        ind = b_search(rt.sts, rt.tm, i);
        if (ind != -1) printf("    *%d*    ", i);
        else printf("     %d     ", i);
        //


        // Printa as transi��es
        printf("[");
        printf("%d  ", dtran[i][0]);
        for (v=1; v<(NUM_COLUMN - 1); ++v) printf("%d     ", dtran[i][v]);
        printf("]");
        //

        printf("\n");

    }




    printf("\n\n\n\n\n");
    for (i=0; i<dstates_num; ++i)
    {

        // Printa o estado do DFA
        printf(" %d     ", i);
        //


        // Printa as transi��es
        printf("[");
        for (v=0; v<(NUM_COLUMN - 1); ++v) if (dtran[i][v] != -1) printf("%s: %d         ", nfa[NUM_NFA][v+1] ,dtran[i][v]);
        printf("]");
        //

        printf("\n\n");
    }
    printf("\n\n\n\n\n");

//







    for (i=0; i<map_in; ++i) free(map[i].sts); // Para liberar os espa�os de mem�ria que foram alocados durante a execu��o do programa

    deleted_states = minimizer(dtran, dstates_num);







// Printar o resultado da minimiza��o dos estados do DFA

    for (i=0; i<dstates_num; ++i) // Para printar dtran depois da minimiza��o
    {

        if ( b_search(deleted_states.sts, deleted_states.tm, i) == -1 )
        {
            // Printa o estado do DFA
            ind = b_search(rt.sts, rt.tm, i);
            if (ind != -1) printf("    *%d*    ", i);
            else printf("     %d     ", i);
            //


            // Printa as transi��es
            printf("[");
            printf("%d  ", dtran[i][0]);
            for (v=1; v<(NUM_COLUMN - 1); ++v) printf("%d     ", dtran[i][v]);
            printf("]");
            //

            printf("\n");
        }

    }





    printf("\n\n\n\n\n");
    for (i=0; i<dstates_num; ++i) // Printa as transi��es omitindo aquelas que s�o para o estado morto
    {

        if ( b_search(deleted_states.sts, deleted_states.tm, i) == -1 )
        {

            // Printa o estado do DFA
            printf(" %d     ", i);
            //


            // Printa as transi��es
            printf("[");
            for (v=0; v<(NUM_COLUMN - 1); ++v) if (dtran[i][v] != -1) printf("%s: %d         ", nfa[NUM_NFA][v+1] ,dtran[i][v]);
            printf("]");
            //

            printf("\n\n");

        }

    }
    printf("\n\n\n\n\n");





    printf("Valor de partition_in: %d\n\n", partition_in);

    for (i=0; i<partition_in; ++i) // Printa a parti��o dos estados do DFA
    {
        printf("{ ");

        for (v=0; partition[i][v] != -5; ++v) printf("%d ", partition[i][v]);

        printf("}\n");
    }

//

    free(deleted_states.sts);
    for (i=0; i<partition_in; ++i) free(partition[i]); // D� free() nas listas em partition
    free(rt.sts);


    return 0;
}




int closure(int *states)
{
    int stack[500];  // Vari�vel para implementa��o de uma stack
    int stack_in = 0; // Armazena o pr�ximo �ndice vazio da stack

    int result[500]; // Armazena o resultado da opera��o e-closure
    int result_in = 0; // Armazena o pr�ximo �ndice vazio de result
    int result_num = 0; // Armazena a quantidade de estados em result

    int t; // Recebe um elemento de cada vez da stack
    int i, v, y; // Vari�veis usadas em la�os for

    char num[11]; // Armazena um estado de cada vez do conjunto de estados que foi passado

    char *entry; // Armazena um dos ponteiros da vari�vel nfa

    int column = 0; // Armazena a coluna da vari�vel nfa onde est�o as transi��es com a string vazia

    int *output; // Vari�vel que ser� utilizada para passar o resultado da opera��o para map utilizando aloca��o din�mica

    int sn; // Sinaliza se um estado j� se encontra em clo
    int num_int; // Armazena uma vers�o de num do tipo inteiro


    int number; // Vai auxiliar no preenchimento de output em ordem crescente
    int output_end; // Vai auxiliar no preenchimento de output em ordem crescente



    for (; *states != -5; ++states) // Coloca todos os estados que est�o em states na stack e em clo
    {

        if (result_in == 500) printf("Overflow da vari�vel result na fun��o closure");
        result[result_in] = *states;
        ++result_in;
        ++result_num;


        if (result_in == 500) printf("Overflow da vari�vel stack na fun��o closure");
        stack[stack_in] = *states;
        ++stack_in;

    }



    while (stack_in != 0)  // Calcula a opera��o e-closure para cada um dos estados na stack
    {
        --stack_in;
        t = stack[stack_in]; // t recebe o elemento no topo da stack

        entry = nfa[t][column];  // entry recebe o ponteiro para a string que cont�m o resultado da opera��o e-closure para o estado que est� sendo analisado



        while (*entry) // Passa por cada estado de entry
        {
            for (i=0; *entry != ',' && *entry != '\0' ; ++i, ++entry)  num[i] = (*entry); // Pega o pr�ximo estado de entry
            num[i] = '\0';                  // Finaliza o array num com um caractere nulo
            if (*entry == ',') ++entry;     // Avan�a se necess�rio para pular as v�rgulas


            sn = 0;
            num_int = atoi(num);
            for (v=0; v<result_in; ++v) if (result[v] == num_int) {sn = 1; break;} // Far� uma procura em result para saber se o estado j� est� l� ou n�o


            if (!sn)
            {

                if (result_in == 500) printf("Overflow da vari�vel result na fun��o closure");
                result[result_in] = num_int; // Se o estado j� n�o existir em result ele � colocado na lista
                ++result_in;
                ++result_num;


                if (result_in == 500) printf("Overflow da vari�vel stack na fun��o closure");
                stack[stack_in] = num_int; // O estado tamb�m � colocado na stack
                ++stack_in;
            }

        }


    }



    output = (int *) malloc((result_num*sizeof(int)) + sizeof(int)); // Mais sizeof(int) por causa do valor sentinela -5 que marca o fim da lista

    if (!output)
    {
        printf("Ocorreu um erro durante a alocacao de memoria para output dentro da funcao closure");
        for (i=0; i<map_in; ++i) free(map[i].sts);
        exit(1);
    }


    // Preenchendo output em ordem crescente
    output[0] = -5;
    output_end = 0; // Vai armazenar sempre o �ltimo �ndice preenchido de output
    for (i=0; i<result_in; ++i) // Percorre cada elemento de result
    {
        number = result[i];

        for (v=0; output[v] != -5; ++v) if (output[v] > number) break; // Percorre cada elemento de output

        if (output[v] != -5)
        {
            for (y=output_end; y>=v; --y) output[y+1] = output[y]; // Move todos os elementos maiores que number uma casa para a direita
            output[v] = number;
            ++output_end;
        }
        else
        {
            output[v] = number;
            output[v+1] = -5;
            ++output_end;
        }
    }
    //


    return mapear(output, result_num);

}




int mapear(int *states, int tamanho)
{
    if ( *states != -5 ) // Se states n�o for uma lista vazia
    {
        int i, v; // Utilizadas em la�os for
        int *list; // Armazena alguma das listas de inteiros em map
        int tam_map; // Armazena a quantidade de estados de alguma das listas de inteiros em map
        int sn = 0;


        for (i=0; i < map_in; ++i) // Passa por cada string em map para saber se states j� est� em map
        {

            tam_map = map[i].tm; // Pega a quantidade de estados da lista de inteiros em map que est� sendo analisada


            if (tam_map == tamanho) // Se a quantidade de estados de states e da lista de inteiros em map for a mesma
            {

                list = map[i].sts; // Recebe a lista de inteiros em map

                sn = 0;
                for (v=0; states[v] != -5; ++v) if (states[v] != list[v]) {sn = 1; break;} // Verifica se states cont�m os mesmos estados que a lista em map que est� sendo analisada

                if (!sn) return i;

            }


        }

        if (map_in == 500) printf("Overflow da vari�vel map da fun��o mapear");
        map[map_in].sts = states;
        map[map_in].tm = tamanho;
        ++map_in;

        return map_in - 1;

    }


    else return -1; // Se states for uma lista vazia
}




int *move(int *states, char *symbol) // Calcula a opera��o move sobre um conjunto de estados
{

    static int output[500]; // Ir� armazenar o resultado da opera��o

    if ( (*states != -5 ) && *symbol) // Se states n�o for uma lista vazia e symbol n�o for uma string vazia
    {

        char num[11];

        int i, v;   // Usadas em estruturas for

        int column = 0; // Coluna da vari�vel nfa na qual fazer a busca

        int output_in = 0; // Armazena o pr�ximo �ndice vazio de output

        char *entry; // Armazena um dos ponteiros da vari�vel nfa

        int sn; // Sinaliza se algum estado j� est� em output para n�o colocar duas vezes

        int num_int; // Vers�o do tipo int de num



        for (i = 0; i<NUM_COLUMN; ++i) if (  !strcmp(nfa[NUM_NFA][i], symbol) ) column = i; // Encontra a coluna na vari�vel nfa que corresponde ao input




        for (; *states != -5; ++states) // Passa por todos os estados de states
        {

            entry = nfa[*states][column]; // entry recebe o ponteiro para a sting que corresponde ao resultado da opera��o move para o estado que est� sendo analisado

            while (*entry) // Pega cada estado de entry um por um
            {
                for (i=0;   *entry != ',' && *entry != '\0'; ++i, ++entry) num[i] = (*entry); // Pega o pr�ximo estado de entry
                num[i] = '\0'; // Finaliza com o caractere nulo
                if (*entry == ',') ++entry; // Pula a v�rgula caso necess�rio

                sn = 0;
                num_int = atoi(num);
                for (v=0; v<output_in; ++v) if (output[v] == num_int) {sn = 1; break;} // Far� uma procura em output para saber se o estado j� est� l� ou n�o


                if (!sn)
                {

                    if (output_in == 500) printf("Overflow do array output da fun��o move");
                    output[output_in] = num_int; // Passa o estado em entry para output
                    ++output_in;

                }

            }
            output[output_in] = -5; // Termina output com uma sentinela para marcar o fim da lista

        }

        return output; // Retorna a lista contendo o resultado

    }


    else return NULL; // Retorna um ponteiro nulo caso algum argumento seja uma string vazia

}




struct conjunto busca_dfa(int *states)
{
    int i, v; // Vari�veis utilizadas em la�os for
    int *list; // Armazena uma das listas que est�o armazenadas em map
    int result[200]; // Para armazenar o resultado da busca
    int result_in = 0;
    int *output; // String que vai ser retornada com o resultado
    int ind = 0; // Para receber o resultado da busca bin�ria
    int result_num = 0; // Armazena a quantidade de estados em result
    int tm; // Recebe a quantidade de estados de uma determinada lista de inteiros em map

    for (i=0; i < map_in; ++i)
    {

        list = map[i].sts;
        tm = map[i].tm;

        ind = -1;
        for (v=0; states[v] != -5; ++v)
        {
            ind = b_search(list, tm, states[v]);
            if (ind != -1) break;
        }

        if (ind != -1)
        {
            if (result_in == 200) printf("Overflow da vari�vel result na fun��o busca_dfa");
            result[result_in] = i;
            ++result_in;
            ++result_num;
        }

    }

    output = (int *) malloc((result_num*sizeof(int)) + sizeof(int)); // Mais um por causa do -5 que marca o fim da lista

    if (!output)
    {
        printf("Ocorreu um erro durante a alocacao de memoria para output dentro da funcao busca_dfa");
        for (i=0; i<map_in; ++i) free(map[i].sts);
        exit(1);
    }

    i = 0;
    for (; i<result_in; ++i) output[i] = result[i];
    output[i] = -5;

    return (struct conjunto) {.sts = output, .tm = result_num};
}




int b_search(int *list, int states_num, int key)
{
    int low = 0, high = (states_num - 1), mid;

    while(low <= high)
    {
        mid = (low+high)/2;
        if(key < list[mid]) high = (mid - 1);
        else if(key > list[mid]) low = (mid + 1);
        else return mid;
    }
    return -1;
}





struct conjunto minimizer(int (*dtran)[NUM_COLUMN - 1], int dstates_num)
{

    int *partition_new[500]; // Ir� armazenar a pr�xima parti��o
    int partition_new_in = 0; // Armazena o pr�ximo �ndice vazio de partition_new

    int *stack[500]; // Stack que armazena os grupos nos quais ainda � preciso fazer uma busca em parti��o
    int stack_in = 0; // Armazena o pr�ximo �ndice vazio de stack

    struct grupo busca[500]; // Armazena o resultado da busca na parti��o
    int busca_in = 0; // Armazena o pr�ximo �ndice vazio de busca

    int *inter[500]; // Vari�vel intermedi�ria
    int inter_in = 0; // Armazena o pr�ximo �ndice vazio de stack


    int *lista; // Armazena uma lista de cada vez da stack

    int *deleted_states; // Recebe a lista com todos os estados que foram eliminados na minimiza��o de estados do DFA
    int deleted_end = 0; // Vai auxiliar no preenchimento de deleted_states em ordem crescente
    int number; // Vai auxiliar no preenchimento de deleted_states em ordem crescente
    int deleted_num = 0; // Armazena a quantidade de estados em deleted_states

    int dtr; // Vai receber o resultado da busca na tabela do DFA

    int it; // Ir� ajudar na modifica��o de dtran no final do processo de minimiza��o

    int group_num; // Vai armazenar o valor do grupo do partition para o qual um estado vai

    int sn; // Para saber se determinada coisa foi achada em uma lista

    int *alc; // Segura o endere�o de uma lista para auxiliar na aloca��o din�mica durante o programa

    int parar = 0; // Informa se o processo de minimiza��o dos estados do DFA terminou

    int i, v, y, w; // Usadas em la�os for

    int tm = 0; // Vai ajudar a contar quantos estados uma determinada lista em partition tem
    int tm2 = 0; // Vai ajudar a comparar partition_new com partition

    int same_partition = 0; // Vai auxiliar na compara��o entre partition e partition_new
    int same_group = 0; // Vai auxiliar na compara��o entre partition e partition_new


    // ver em quais partes eu tenho que colocar essa mensagem if (output_in == 500) printf("Overflow do array output da fun��o move");
    // AJEITAR ESSE TIPO DE MENSAGEM if (output_in == 500) printf("Overflow do array output da fun��o move"); PARA QUE QUANDO ACONTECER ISSO SEJA CHAMADO EXIT
    // NOS LUGARES EM QUE EU FA�O MALLOC VERIFICAR SE NAS CONDI��ES QUE EU FA�O CASO MALLOC D� ERRADO T� DANDO OS FREE() NECESS�RIOS ANTES DE DAR EXIT


    // Colocando a parti��o inicial dos estados do DFA em partition

    int *start[23] = {         // Agrupamento inicial dos estados do DFA

                (int []) {0, 7, 8, 28},
                (int []) {1, 3, 24, 25, 26},
                (int []) {2, 27},
                (int []) {4},
                (int []) {5},
                (int []) {6},
                (int []) {9, 10},
                (int []) {11},
                (int []) {12, 13, 33, 34},
                (int []) {38, 39},
                (int []) {14},
                (int []) {15},
                (int []) {16},
                (int []) {17},
                (int []) {18},
                (int []) {19},
                (int []) {20},
                (int []) {21, 22, 35, 36},
                (int []) {23, 37},
                (int []) {29, 32},
                (int []) {30},
                (int []) {31},
                (int []) {-1}

                     };

    int tamanhos[23] = {4, 5, 2, 1, 1, 1, 2, 1, 4, 2, 1, 1, 1, 1, 1, 1, 1, 4, 2, 2, 1, 1, 1}; // Quantidades de estados nas listas de start



    for (i=0; i<23; ++i) // Colocando a parti��o inicial em partition
    {
        partition[partition_in] = (int *) malloc( sizeof(int) * tamanhos[i] + sizeof(int) );

        if ( !(partition[partition_in]) )
        {
            printf("Ocorreu um erro durante a alocacao de memoria para output dentro da funcao closure");
            // VER EM QUEM EU TENHO QUE DAR FREE() ANTES DE DAR EXIT()
            exit(1);
        }

        for (v=0; v<tamanhos[i]; ++v) partition[partition_in][v] = start[i][v];// Passando para partition o que est� em start
        partition[partition_in][v] = -5;

        ++partition_in;
    }

    //




    while (!parar) // Vai repetir o processo enquanto partition_new for diferente de partition
    {


        for (i=0; i<partition_in; ++i) // Percorre cada grupo de partition
        {

            // Passa o grupo de partition para inter

            tm = 0;
            for (y=0; partition[i][y] != -5; ++y) ++tm; // Quantos estados o grupo em partition tem

            inter[inter_in] = (int *) malloc( sizeof(int)*tm + sizeof(int) );

            if ( !(inter[inter_in]) )
            {
                printf("Ocorreu um erro durante a alocacao de memoria para a variavel inter da funcao minimizer");
                // VER DEPOIS EM QUAIS VARI�VEIS EU TENHO QUE DAR MALLOC ANTES DE DAR EXIT
                exit(1);
            }

            for (y=0; y<(tm+1); ++y) inter[inter_in][y] = partition[i][y]; // Passando os estados do grupo de partition para um grupo em inter (incluindo o -5)

            ++inter_in;

            //


            if (tm > 1) // S� tenta fazer o processo de subdivis�o de um grupo com grupos que possuem mais de um estado
            {

                for (v=1; v<NUM_COLUMN; ++v) // Percorre cada s�mbolo do alfabeto do DFA
                {

                    // Coloca tudo o que est� em inter na stack e zera inter_in

                    for (y=0; y<inter_in; ++y)
                    {
                        stack[stack_in] = inter[y];
                        ++stack_in;
                    }
                    inter_in = 0;

                    //


                    // Subdivide o m�ximo que pode para um determinado input symbol todos os grupos na stack

                    while (stack_in > 0) // Faz a parti��o de cada grupo na stack
                    {

                        --stack_in;
                        lista = stack[stack_in]; // Pega o pr�ximo grupo na stack


                        // Processo de tentativa de subdivis�o de um determinado grupo pego da stack

                        for (; *lista != -5; ++lista) // Percorre cada estado do grupo
                        {


                            dtr = dtran[*lista][v-1]; // Para qual outro estado esse estado transita no s�mbolo que est� sendo avaliado


                            // Procura em partition para que grupo o estado est� indo

                            for (y=0; y<partition_in; ++y)
                            {

                                for (w=0; partition[y][w] != -5; ++w)
                                {
                                    if (dtr == partition[y][w]) {group_num = y; y = partition_in; break;}

                                }

                            }

                            //


                            // Percorre a vari�vel busca para saber se a struct para o grupo encontrado j� foi criada ou n�o. Caso j� tenha sido criada, acrescenta o estado na lista da struct

                            sn = 0;
                            for (y=0; y<busca_in; ++y)
                            {
                                if (busca[y].gp == group_num) // Se a struct j� foi criada acrescente o estado que est� sendo avaliado na lista do struct
                                {

                                    alc = busca[y].sts;
                                    busca[y].sts = (int *) malloc(  sizeof(int)*(busca[y].tm)  +   2*sizeof(int) );
                                    if (!busca)
                                    {
                                        printf("Ocorreu um erro durante a alocacao de memoria para output dentro da funcao closure");
                                        // VER EM QUEM EU TENHO QUE DAR FREE() ANTES DE DAR EXIT()
                                        exit(1);
                                    }

                                    for (w=0; alc[w] != -5; ++w) busca[y].sts[w] = alc[w];
                                    busca[y].sts[w] = (*lista);
                                    busca[y].sts[w+1] = -5;

                                    free(alc);

                                    busca[y].tm = (busca[y].tm) + 1;

                                    sn = 1;
                                    break;
                                }

                            }

                            //


                            // Caso a struct para o grupo encontrado ainda n�o tenha sido criada

                            if (sn == 0)
                            {
                                if (busca_in == 500) printf("Overflow do array busca na fun��o minimizer");
                                busca[busca_in].sts = (int *) malloc(2*sizeof(int));
                                if (!busca)
                                {
                                    printf("Ocorreu um erro durante a alocacao de memoria para output dentro da funcao closure");
                                    // VER EM QUEM EU TENHO QUE DAR FREE() ANTES DE DAR EXIT()
                                    exit(1);
                                }
                                busca[busca_in].sts[0] = *lista;
                                busca[busca_in].sts[1] = -5;

                                busca[busca_in].tm = 1;
                                busca[busca_in].gp = group_num;

                                ++busca_in;
                            }

                            //


                        } // Fim da quebra de um grupo pego da stack


                        // Coloca o resultado de volta na stack se ocorrer subdivis�o ou em inter se n�o ocorrer

                        free(stack[stack_in]);

                        if (busca_in > 1) // Se tiver acontecido uma subdivis�o de lista, ou seja, se busca tiver mais de uma lista todas as lista em busca s�o passadas para a stack
                        {
                            for (y=0; y<busca_in; ++y) // Coloca na stack
                            {
                                stack[stack_in] = busca[y].sts;
                                ++stack_in;

                            }
                        }
                        else // Caso contr�rio a lista que est� em busca � passada para inter
                        {

                            inter[inter_in] = busca[0].sts;
                            ++inter_in;

                        }

                        busca_in = 0;

                        //


                    } // Fim do while da stack


                } // For que passa por cada s�mbolo do alfabeto do DFA


            } // Fim do processo de quebra de um grupo de partition



            for (y=0; y<inter_in; ++y) {partition_new[partition_new_in] = inter[y]; ++partition_new_in;} // Coloca o que est� em inter em partition_new

            inter_in = 0; // Zera inter para uma nova rodada com um outro grupo de partition




        } // Fim do for que passa por cada grupo de partition




        // Verificando se partition_new � igual ou n�o a partition

        if (partition_new_in == partition_in) // Ir� comparar partition com partition_new caso os dois tenham a mesma quantidade de grupos para ver se s�o iguais ou n�o
        {

            same_partition = 0;
            for (i=0; i<partition_new_in; ++i) // Passa por cada grupo de partition_new
            {

                tm = 0;
                for (y=0; partition_new[i][y] != -5; ++y) ++tm; // Pega o tamanho desse grupo de partition_new


                for (v=0; v<partition_in; ++v) // Passa por cada grupo de partition
                {

                    tm2 = 0;
                    for (y=0; partition[v][y] != -5; ++y) ++tm2; // Pega o tamanho desse grupo de partition

                    same_group = 0;

                    if (tm == tm2) // Compara os dois grupos para ver se s�o iguais ou n�o caso eles tenham a mesma quantidade de estados (se dois grupos tiverem quantidades de estados diferentes eles automaticamente s�o diferentes e n�o h� necessidade de se fazer a compara��o)
                    {
                        for (y=0; partition_new[i][y] != -5; ++y) for (w=0; partition[v][w] != -5; ++w) // Passa por cada estado do grupo de partition_new e para cada um deles percorre todos os estados do grupo de partition
                        {

                            if (partition_new[i][y] == partition[v][w]) {++same_group; break;} // Toda vez que um dos estados do grupo de partition_new for encontrado no grupo de partition same_group � incrementada

                        };
                    }

                    if (same_group == tm) {++same_partition; break;} // Verifica se todos os estados do grupo de partition_new foram encontrados no grupo de partition. Caso isso aconte�a os dois grupos s�o iguais e um dos grupos de partition_new foi encontrado em partition

                }

            }

            if (same_partition == partition_new_in) parar = 1; // Verifica se cada grupo de partition_new foi encontrado em partition e consequente se partition_new � igual a partition


        } // Fim da verifica��o



        for (i=0; i<partition_in; ++i) free(partition[i]); // D� free() nas listas em partition para colocar no lugar as listas de partition_new
        partition_in = 0;

        for (i=0; i<partition_new_in; ++i) {partition[i] = partition_new[i]; ++partition_in;} // Coloca as listas de partition_new em partition
        partition_new_in = 0;


    } // Fim do while



    deleted_states = (int *) malloc(sizeof(int)*200); // deleted_states ir� conter os estados que foram eliminados durante a minimiza��o
    if (!deleted_states)
    {

        printf("Ocorreu um erro durante a alocacao de memoria para output dentro da funcao closure");
        // VER EM QUEM EU TENHO QUE DAR FREE() ANTES DE DAR EXIT()
        exit(1);

    }


    // Preenchendo deleted_states em ordem crescente

    deleted_states[0] = -5;
    deleted_end = 0; // Vai armazenar sempre o �ltimo �ndice preenchido de deleted_states contando com o -5
    for (i=0; i<partition_in; ++i) for(v=1; partition[i][v] != -5; ++v) // Percorre cada lista de partition com mais de um estado a partir do segundo elemento
    {
        number = partition[i][v];
        ++deleted_num;

        for (y=0; deleted_states[y] != -5; ++y) if (deleted_states[y] > number) break; // Percorre cada elemento de deleted_states

        if (deleted_states[y] != -5)
        {
            for (w=deleted_end; w>=y; --w) deleted_states[w+1] = deleted_states[w]; // Move todos os elementos maiores que number uma casa para a direita
            deleted_states[y] = number;
            ++deleted_end;
        }
        else
        {
            deleted_states[y] = number;
            deleted_states[y+1] = -5;
            ++deleted_end;
        }

    }; // Fim do preenchimento




    // Fazendo as altera��es necess�ria nas transi��es do DFA armazenadas em dtran

    for (i=0; i<partition_in; ++i) // Passa por cada grupo em partition
    {

        if (partition[i][1] != -5) // Se o grupo tiver mais de um estado
        {
            it = partition[i][0]; // Pegue o representante do grupo

            for (v=1; partition[i][v] != -5; ++v) // Passa por cada estado de uma lista de partition a partir do segundo elemento
            {

                for (y=0; y<dstates_num; ++y) for (w=0; w<(NUM_COLUMN - 1); ++w) // Percorre dtran alterando as transi��es que forem necess�rias
                {
                    if (dtran[y][w] == partition[i][v]) dtran[y][w] = it; // Trocando os estados eliminados durante a minimiza��o pelos representantes dos seus grupos
                };

            }
        }

    } // Fim das altera��es em dtran



    return (struct conjunto) {.sts = deleted_states, .tm = deleted_num};
}
