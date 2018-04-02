
#include "Header.c"

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
