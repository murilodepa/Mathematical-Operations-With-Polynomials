#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define Cor_Das_Grades 9 //9 ou 1
#define Verde 10
#define Vermelho 12  //12 ou 4
#define Branco 15

struct termo
{
    float coef;
    int exp;
};

typedef struct termo elemento;

#include "ListaLigada.h"

no *novo_no ();
no *criar_vazia ();
int compr (no*);
int vazia (no*);
void Erro (int);
void inserir (no**, elemento, int);
void alterar (no*, elemento, int);
elemento consultar (no*, int);
elemento eliminar (no**, int);

//################## PROTÓTIPO DAS FUNÇÕES UTILIZADAS NA MAIN ###################

// FUNÇÃO PARA MUDAR A COR DOS CARÁCTERES IMPRESSOS
void Muda_Cor (int);

// FUNÇÃO PARA LER OS POLINOMIOS DESEJADOS EM LISTA LIGADA
void Leitura (no ** );

// FUNÇÃO PARA IMPRIMIR A LISTA LIGADA DESEJADA
void imprime (no * );

// FUNÇÃO PARA REALIZAR A SOMA DE POLINOMIOS
void Soma (no *, no *, no **);

// FUNÇÃO PARA REALIZAR A MULTIPPLICAÇÃO DE POLINOMIOS
void Mult (no *, no *, no ** );

// FUNÇÃO PARA ORDENAR OS POLINOMIOS PELO EXPOENTE DO MAIOR ATÉ O MENOR
void Ordenar_Polinomio(no** );
//###############################################################################


//#################################### MAIN #####################################
int main()
{
    int j;
    no *PX, *QX, *RX, *SX;

    Muda_Cor(Cor_Das_Grades);
    printf("\n    \332\304");

    for(j=0; j<5; j++)
        printf("\304\304\304\304\304\304\304\304");

    printf("\277\n    \263");
    Muda_Cor(Vermelho);
    printf("  DIGITE OS DADOS DO PRIMEIRO POLINOMIO");
    Muda_Cor(Cor_Das_Grades);
    printf("  \263\n    \300\304");

    for(j=0; j<5; j++)
        printf("\304\304\304\304\304\304\304\304");

    printf("\331");

    Leitura (&PX);
    Ordenar_Polinomio(&PX);

    Muda_Cor(Cor_Das_Grades);
    printf("\n\n\n    \332");

    for(j=0; j<5; j++)
        printf("\304\304\304\304\304\304\304\304");

    printf("\277\n    \263");
    Muda_Cor(Vermelho);
    printf("  DIGITE OS DADOS DO SEGUNDO POLINOMIO");
    Muda_Cor(Cor_Das_Grades);
    printf("  \263\n    \300");

    for(j=0; j<5; j++)
        printf("\304\304\304\304\304\304\304\304");

    printf("\331");

    Leitura (&QX);
    Ordenar_Polinomio(&QX);

    Soma (PX, QX, &RX);
    Mult (PX, QX, &SX);

    system("cls");

    Muda_Cor(Cor_Das_Grades);
    printf("\n\t \332\304\304");

    for(j=0; j<3; j++)
        printf("\304\304\304\304\304\304");

    printf("\277\n\t \263");
    Muda_Cor(Vermelho);
    printf("  POLINOMIOS LIDOS");
    Muda_Cor(Cor_Das_Grades);
    printf("  \263\n\t \300\304\304");

    for(j=0; j<3; j++)
        printf("\304\304\304\304\304\304");

    printf("\331");

    Muda_Cor(Cor_Das_Grades);
    printf("\n\n P(x) = ");
    Muda_Cor(Vermelho);
    imprime (PX);

    Muda_Cor(Cor_Das_Grades);
    printf("\n\n Q(x) = ");
    Muda_Cor(Vermelho);
    imprime (QX);

    Muda_Cor(Verde);
    printf("\n\n\n SOMA DOS POLINOMIOS: ");
    Muda_Cor(Cor_Das_Grades);
    printf("R(x) = P(x) + Q(x)");
    printf("\n\n R(x) = ");
    Ordenar_Polinomio(&RX);
    Muda_Cor(Vermelho);
    imprime (RX);

    Muda_Cor(Verde);
    printf("\n\n\n PRODUTO DOS POLINOMIOS: ");
    Muda_Cor(Cor_Das_Grades);
    printf("S(x) = P(x) * Q(x)");
    printf("\n\n S(x) = ");
    Muda_Cor(Vermelho);
    Ordenar_Polinomio(&SX);
    imprime (SX);

    printf("\n\n\n\n\n");

    return 0;
}

// FUNÇÃO PARA MUDAR A COR DOS CARÁCTERES IMPRESSOS
void Muda_Cor (int cor)
{

    /*
    0 = Preto		8 = Cinza
    1 = Azul		9 = Azul Claro
    2 = Verde		10 = Verde Claro
    3 = Verde-Agua	11= Verde-Agua Claro
    4 = Vermelho	12 = Vermelho Claro
    5 = Roxo		13 = Lilas
    6 = Amarelo		14 = Amarelo Claro
    7 = Branco		15 = Branco Brilhante
    */
    HANDLE Saida;
    Saida = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(Saida,cor);
}
//###############################################################################

// FUNÇÃO PARA LER OS POLINOMIOS DESEJADOS EM LISTA LIGADA
void Leitura (no **P)
{
    int num_termos;
    int i;

    elemento V;

    *P = criar_vazia();

    Muda_Cor(Verde);
    printf("\n\n DIGITE A QUANTIDADE DE TERMOS: ");
    Muda_Cor(Branco);
    scanf("%d", &num_termos);

    for(i = 1; i <= num_termos; i++)
    {
        Muda_Cor(Verde);
        printf("\n DIGITE O COEFICIENTE: ");
        Muda_Cor(Branco);
        scanf("%f", &(V.coef));

        Muda_Cor(Verde);
        printf(" DIGITE O EXPOENTE: ");
        Muda_Cor(Branco);
        scanf("%d", &(V.exp));

        inserir(P, V, i);
    }
}

// FUNÇÃO PARA IMPRIMIR A LISTA LIGADA DESEJADA
void imprime (no* P)
{
    int Inicial;
    Inicial=0;

    while(P!=NULL)
    {

        if(Inicial==0)
        {

            if(P->info.coef == 1 || P->info.coef == -1)
            {
                if(P->info.exp != 0 && P->info.exp != 1)
                {
                    if(P->info.coef > 0)
                    {
                        printf(" x^%d", P->info.exp);
                        P = P->link;
                    }
                    else
                    {
                        printf(" -x^%d", P->info.exp);
                        P = P->link;
                    }
                }
                else
                {
                    if(P->info.exp == 0)
                    {
                        if(P->info.coef > 0)
                        {
                            printf(" %1.f", P->info.coef);
                            P = P->link;
                        }
                        else
                        {
                            P->info.coef = (P->info.coef*(-1));
                            printf(" -%1.f", P->info.coef);
                            P->info.coef = (P->info.coef*(-1));
                            P = P->link;
                        }
                    }
                    else
                    {
                        if(P->info.exp == 1)
                        {
                            if(P->info.coef > 0)
                            {
                                printf(" x");
                                P = P->link;
                            }
                            else
                            {
                                printf(" -x");
                                P = P->link;
                            }
                        }
                    }
                }
            }
            else
            {
                if(P->info.coef != 1 && P->info.coef != -1 && P->info.exp == 1)
                {
                    if(P->info.coef > 0)
                    {
                        printf(" %1.fx", P->info.coef);
                        P = P->link;
                    }
                    else
                    {
                        P->info.coef = (P->info.coef*(-1));
                        printf(" -%1.fx", P->info.coef);
                        P->info.coef = (P->info.coef*(-1));
                        P = P->link;
                    }
                }
                else
                {
                    if(P->info.exp == 0)
                    {
                        if(P->info.coef > 0)
                        {
                            printf(" %1.f", P->info.coef);
                            P = P->link;
                        }
                        else
                        {
                            P->info.coef = (P->info.coef*(-1));
                            printf(" -%1.f", P->info.coef);
                            P->info.coef = (P->info.coef*(-1));
                            P = P->link;
                        }
                    }

                    else
                    {
                        if(P->info.coef != 1 && P->info.coef != -1 && P->info.exp != 0 && P->info.exp != 1)
                        {
                            if(P->info.coef > 0)
                            {
                                printf(" %1.fx^%d", P->info.coef, P->info.exp);
                                P = P->link;
                            }
                            else
                            {
                                P->info.coef = (P->info.coef*(-1));
                                printf(" -%1.fx^%d", P->info.coef, P->info.exp);
                                P->info.coef = (P->info.coef*(-1));
                                P = P->link;
                            }
                        }
                    }
                }
            }
            Inicial = 10;
        }
        else
        {
            if(P->info.coef == 1 || P->info.coef == -1)
            {
                if(P->info.exp != 0 && P->info.exp != 1)
                {
                    if(P->info.coef > 0)
                    {
                        printf(" + x^%d", P->info.exp);
                        P = P->link;
                    }
                    else
                    {
                        printf(" - x^%d", P->info.exp);
                        P = P->link;
                    }
                }
                else
                {
                    if(P->info.exp == 0)
                    {
                        if(P->info.coef > 0)
                        {
                            printf(" + %1.f", P->info.coef);
                            P = P->link;
                        }
                        else
                        {
                            P->info.coef = (P->info.coef*(-1));
                            printf(" - %1.f", P->info.coef);
                            P->info.coef = (P->info.coef*(-1));
                            P = P->link;
                        }
                    }
                    else
                    {
                        if(P->info.exp == 1)
                        {
                            if(P->info.coef > 0)
                            {
                                printf(" + x");
                                P = P->link;
                            }
                            else
                            {
                                printf(" - x");
                                P = P->link;
                            }
                        }
                    }
                }
            }
            else
            {
                if(P->info.coef != 1 && P->info.coef != -1 && P->info.exp == 1)
                {
                    if(P->info.coef > 0)
                    {
                        printf(" + %1.fx", P->info.coef);
                        P = P->link;
                    }
                    else
                    {
                        P->info.coef = (P->info.coef*(-1));
                        printf(" - %1.fx", P->info.coef);
                        P->info.coef = (P->info.coef*(-1));
                        P = P->link;
                    }
                }
                else
                {
                    if(P->info.coef != 1 && P->info.coef != -1 && P->info.exp == 0)
                    {
                        if(P->info.coef > 0)
                        {
                            printf(" + %1.f", P->info.coef);
                            P = P->link;
                        }
                        else
                        {
                            P->info.coef = (P->info.coef*(-1));
                            printf(" - %1.f", P->info.coef);
                            P->info.coef = (P->info.coef*(-1));
                            P = P->link;
                        }
                    }
                    else
                    {
                        if(P->info.exp != 0 && P->info.exp != 1)
                        {
                            if(P->info.coef > 0)
                            {
                                printf(" + %1.fx^%d", P->info.coef, P->info.exp);
                                P = P->link;
                            }
                            else
                            {
                                P->info.coef = (P->info.coef*(-1));
                                printf(" - %1.fx^%d", P->info.coef, P->info.exp);
                                P->info.coef = (P->info.coef*(-1));
                                P = P->link;
                            }
                        }
                    }
                }
            }
        }
    }
}

// FUNÇÃO PARA REALIZAR A SOMA DE POLINOMIOS
void Soma (no *X, no *Y, no **Z)
{
    int i;
    elemento V;

    *Z = criar_vazia();

    i=1;

    while(X!=NULL && Y!=NULL)
    {
        if(X->info.exp < Y->info.exp)
        {
            inserir(Z, Y->info, i);
            i=(i+1);
            Y = Y->link;
        }

        else
        {
            if(X->info.exp == Y->info.exp)
            {
                V.coef = (X->info.coef + Y->info.coef);
                V.exp = X->info.exp;

                if(V.coef!=0)
                {
                    inserir(Z, V, i);
                    i=(i+1);
                }
                X = X->link;
                Y = Y->link;
            }

            else
            {
                if(X->info.exp > Y->info.exp)
                {
                    inserir(Z, X->info, i);
                    i=(i+1);
                    X = X->link;
                }
            }
        }
    }

    if(X==NULL && Y!=NULL)
    {
        while(Y!=NULL)
        {
            inserir(Z, Y->info, i);
            i=(i+1);
            Y = Y->link;
        }
    }

    if(Y==NULL && X!=NULL)
    {
        while(X!=NULL)
        {
            inserir(Z, X->info, i);
            i=(i+1);
            X = X->link;
        }
    }
}

// FUNÇÃO PARA REALIZAR A MULTIPPLICAÇÃO DE POLINOMIOS
void Mult (no* X, no* Y, no** Z)
{
    int cont_1, cont_2, i, j, k, l, m;
    int vet[100];
    no *W, *Pri_W, *Pri_W2, *Pri_Y;
    elemento V;

    W = criar_vazia();
    *Z = criar_vazia();

    Pri_Y = Y;
    Pri_W = W;
    Pri_W2 = W;

    cont_1=1;
    cont_2=1;
    k=1;
    l=10;

    while(X!=NULL)
    {
        Y = Pri_Y;

        while(Y!=NULL)
        {
            V.coef = (X->info.coef * Y->info.coef);
            V.exp = (X->info.exp + Y->info.exp);

            if(V.coef!=0)
            {
                inserir(&W, V, cont_1);
                cont_1=(cont_1+1);
            }

            Y = Y->link;
        }
        X = X->link;
    }

    j=0;
    m=1;

    Pri_W2 = W;

    while(cont_2 < cont_1 && (j+1) < cont_1)
    {
        Pri_W = W;
        i=1;
        V.coef=0;
        l=0;

        while(Pri_W != NULL)
        {
            if(Pri_W2->info.exp == Pri_W->info.exp)
            {
                //printf("\n\ni = %d", i);
                l=0;

                for(k=0; k<j; k++)
                {
                    if(i == vet[k])
                        l=10;
                }


                if(l==0)
                {
                    V.coef = (V.coef+Pri_W->info.coef);
                    V.exp = (Pri_W->info.exp);
                    vet[j] = i;
                    j++;
                }
            }

            Pri_W = Pri_W->link;
            i=(i+1);
        }

        if(l==0)
        {
            inserir(Z, V, m);
            m=(m+1);
            /*
                    printf("\n");
                    imprime(*Z);
                    printf("\n\n");
            */
        }

        cont_2 =(cont_2+1);
        Pri_W2 = Pri_W2->link;
    }
}

// FUNÇÃO PARA ORDENAR OS POLINOMIOS PELO EXPOENTE DO MAIOR ATÉ O MENOR
void Ordenar_Polinomio(no** P)
{
    int i, j, Tamanho, Pos;
    elemento Maior;

    i=1;
    j=0;
    Pos=0;

    Tamanho = compr(*P);

    no *Pri, *Pri_2;

    Pri = *P;
    Pri_2 = *P;

    if(Tamanho==2)
    {
        Pri = *P;
        Pri_2 = *P;
        Pri_2 = Pri_2->link;

        if(Pri_2->info.exp > Pri->info.exp)
        {
            Maior.coef = Pri_2->info.coef;
            Maior.exp = Pri_2->info.exp;

            inserir(P, Maior, 1);
            eliminar(P, 3);
        }
    }
    else
    {
        while(i<=Tamanho)
        {
            Pri = *P;
            Pri_2 = *P;
            j=1;

            while(j<=Tamanho)
            {
                if(Pri->info.exp > Pri_2->info.exp)
                {
                    Maior.coef = Pri->info.coef;
                    Maior.exp = Pri->info.exp;
                    Pos=i;
                }
                else
                {
                    Maior.coef = Pri_2->info.coef;
                    Maior.exp = Pri_2->info.exp;
                    Pos=j;
                }
                Pri_2=Pri_2->link;
                j=(j+1);
            }

            eliminar(P, Pos);
            inserir_final(P, Maior);
            Tamanho=(Tamanho-1);
        }
    }
}








