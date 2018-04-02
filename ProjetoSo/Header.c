#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int PedirInt(char pedido[141]);

void PedirString(char *resposta, char pedido[141]);


void expandir();
void ordenar();
void excluir(char *valor);
int buscarPorValor(char *valor);
int buscarPorIndice();
int quantidadeElementos();



struct processo
{
    char nome[41];
    int tempo_dur;
    int nasc;
    int n_bilhete;
    int * id_bilhete;
};

void adicionar(struct processo valor);

void menuList();

struct processo *lista;
struct processo pacote;
int indice;
int fim = 0;
int l = 0;
int opcao = 0;
int tamanho = 5;
int posicao = 0;

