#ifndef LISTALIGADA_H_INCLUDED
#define LISTALIGADA_H_INCLUDED


struct no
{
    elemento info;
    struct no* link;
};

typedef struct no no;

no* criar_vazia()
{
    return NULL;
}

no * novo_no()
{
    no * novo;
    novo = (no*) malloc(sizeof(no));

    if(novo == NULL)
    {
        printf("\nErro de Alocacao Novo no");
        exit(1);
    }
    return novo;
}

int compr (no *pri)
{
    no *p;
    int cont=0;
    p=pri;

    while(p!=NULL)
    {
        cont = (cont+1);
        p=p->link;
    }

    return cont;
}

int vazia (no *pri)
{
    if(pri==NULL)
        return 0;
    return 1;
}

void Erro(int i){
switch(i){
 case 0: printf("erro de alocacao");
         exit(1);
         break;
 case 1: printf("posicao invalida");
         exit(1);
         break;
}
}

void inserir (no** pri, elemento V, int i)
{
    no *novo, *p, *ant;
    int cont;

    if((i<=0) || (i>compr(*pri)+1))
    Erro(1);

    cont=1;
    novo = novo_no();
    novo->info=V;
    p=*pri;

    while(p!= NULL && cont < i)
    {
        ant = p;
        p=p->link;
        cont = (cont+1);
    }

    novo->link=p;

    if(p==*pri)
        *pri=novo;
    else
        ant->link=novo;
}

void inserir_final(no **pri, elemento x)
{
     no *p, *novo;
    novo = novo_no();

    novo->info = x;
    novo->link=NULL;

    p = *pri;

    while(p!=NULL && p->link!=NULL)
    {
        p = p->link;
    }

        if(p==*pri)
            *pri = novo;
        else
        {
            p->link=novo;
        }
}

void alterar (no * PRI, elemento V, int I)
{
no * x;
      if (( I <= 0 ) || ( I > compr(PRI) ))
      Erro (1);
      int  cont = 1;
       x = PRI;
      while((cont < I ) && ( x!=NULL)){
		x =x->link ;
		cont ++;
        }
	x->info= V;
}

elemento consultar (no* PRI, int I)
{
no * x;
      if (( I <= 0 ) || ( I > compr(PRI)))
      Erro (1);
      int  cont = 1;
      x = PRI;
      while((cont < I ) && ( x!=NULL))	{
	x =x->link ;
	cont ++;
      }
      return x->info;
}

elemento eliminar (no **PRI, int I)
{
elemento V;
no * x, *s;
      if (( I <= 0 ) || ( I > compr(*PRI) ))
     Erro (1);
      int  cont = 1;
      x = *PRI;
       while((cont < I ) && ( x!=NULL)) {
	s = x;
x =x->link ;
	cont ++;
      }
      V =  x->info;
if( x == *PRI)
 *PRI = x->link;
else  s->link = x->link;
      free ( x );
return V;
}



#endif // LISTALIGADA_H_INCLUDED


