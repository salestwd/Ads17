
#include "Header.c"




void Listar()
{
    opcao = 7;
    lista = malloc( tamanho * sizeof(struct processo));
    if(!lista)
    {
        printf("Erro de alocacao! \n");
        exit(-1);
    }

    while(opcao)
    {
        void menu();
        switch(opcao)
        {
        case 1:
            PedirString(pacote.nome,"O nome do Processo \n");
            pacote.nasc = PedirInt("O tempo em que o processo foi criado");
            pacote.tempo_dur = PedirInt("O tempo de duracao do processo");
            pacote.n_bilhete = PedirInt("O numero de bilhetes do processo");
            adicionar(pacote);
            break;
        case 2:
            printf("A lista possui %d elementos.\n", quantidadeElementos());
            break;
        case 3:

            printf("Digite o indice: ");
            scanf("%d", &indice);

            pacote.nasc = buscarPorIndice(indice);
            if(pacote.nasc == -1)
                printf("Indice invalido!\n");
            else
                printf("Processo encontrado no indice %d = %d\n", indice, pacote.nome);
            break;
        case 4:
            PedirString(pacote.nome,"O nome do processo a buscar");
            indice = buscarPorValor(pacote.nome);
            if(indice == -1)
                printf("Nao encontrei %d na lista!\n", indice);
            else
                printf("Encontrei o processo %s no indice %d\n", lista[indice].nome, indice);
            break;
        case 5:
            PedirString(pacote.nome, "O processo a ser excluído \n");
            excluir(pacote.nome);
            break;
        case 6:
            printf("Ordenando...\n");
            ordenar();
            break;
        case 7:
            for(l=0; l < quantidadeElementos(); l++)
            {
                pacote = lista[l];
                printf("\t Lista[%d]\n",l);
                printf("\t Nome: %s  \n",pacote.nome);
                printf("\t Tempo de duracao: %d \n", pacote.tempo_dur);
                printf("\t Tempo de criacao: %d \n", pacote.nasc);
                printf("\t Numedro de bilhetes: %d \n\n",pacote.n_bilhete);

            }
            break;
        case 8:
            expandir();
            printf("Expansao realizada com sucesso! \n");
            break;
        case 9:
            printf("Foda se vc\n");
            break;
        default : printf("Opcao invalida \n");
        }
    }
    free(lista);
}




void adicionar(struct processo valor)
{
    if(posicao == tamanho)
    {
       expandir(lista);

    }

    lista[posicao] = valor;
    posicao++;
}


int quantidadeElementos()
{
    return posicao;

}

int buscarPorIndice(int indice)
{
    int i = indice;
    if (i >= posicao)
    {
         struct processo errado;
         strcpy(errado.nome,"deu ruim");
         errado.nasc = -1;
         errado.tempo_dur = -1;
    }
    else
    {
        return -1;
    }


}

int buscarPorValor(char *valor)
{
    for(l=0;l<=posicao;l++)
    {
     if (lista[l].nome == valor)
     {

     }

    }
    return -1;
}

void excluir(char *valor)
{

    if(l > 0) {
    l = buscarPorValor(valor);
    if(l!=-1)
    {
    for(;l < posicao - 1 ;l++)
    {
        lista[l]= lista[l + 1];
    }

  posicao--;
}
    else
{
    printf("Lista Vazia \n");
}
}
}


void ordenar()
{
    int i,j;
    struct processo bolha;
    for(i = 0;i < posicao - 1;i++)
      {
        for(j = i + 1;j < posicao;j++)
        {
           if ((strcmp(lista[i].nome,lista[j].nome)) > 0)
           {
               bolha = lista[i];
               lista[i] = lista[j];
               lista[j] = bolha;
           }
        }
     }
}

void expandir ()
{
    int i;
    struct processo *auxiliar;
    int novo_tamanho;
    novo_tamanho = tamanho + (tamanho / 2);

    auxiliar = malloc(novo_tamanho * sizeof(int));

    for(i = 0; i <tamanho;i++)
    {
        auxiliar[i] = lista[i];
    }
    free(lista);
    lista = auxiliar;
    tamanho = novo_tamanho;
}


int PedirInt(char pedido[141])

{
    int resposta;
    printf("Por Favor, digite um numero inteiro para %s : ", pedido);
    scanf("%d",resposta);
    fflush(stdin);
    return resposta;
}


void PedirString(char *resposta, char pedido[141])

{
    printf("Por favor digite %s : ", pedido);
    gets(resposta);
    fflush(stdin);

}
