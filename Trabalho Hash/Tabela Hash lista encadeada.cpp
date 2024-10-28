#include <stdio.h>
#include <stdlib.h>

#define TAM 13 //13 escolhido por ser um número primo

typedef struct node{
    int chave;
    struct node *proximo;
}Node;

typedef struct{
    Node *inicio;
    int tamanho;
}Lista;

void inicializar_a_lista(Lista *lista){
    lista->inicio = NULL;
    lista->tamanho = 0;
}

void inserir_na_lista(Lista *lista, int valor){//A nova lista será inserida no início, pra ser mais eficiente.
    Node *novo = (struct node*)malloc(sizeof(Node));//É preciso fazer uma conversão explícita.

    if(novo){//Se novo for alocado corretamente, entrará no escopo do if.
        novo->chave = valor;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->tamanho++;
    } else {
        printf("\nNão foi possível alocar memória.\n");
    }
}

int buscar_na_lista(Lista *lista, int valor){
    Node *aux = lista->inicio;
    
    while(aux && aux->chave != valor){//Enquanto aux for diferente de NULL e a chave for diferente do valor, continuará no while.
        aux = aux->proximo;
    }
    
    if(aux){//Se a chave for encontrada, irá retornar o valor dela.
        return aux->chave;
    }
    
    return 0;
}

void imprimir_lista(Lista *lista){
    Node *aux = lista->inicio;
    printf(" Tamanho: %d: ", lista->tamanho);
    
    while(aux){
        printf("%d ", aux->chave);
        aux = aux->proximo;
    }
}

void inicializar_a_tabela(Lista t[]){
    for(int i = 0; i < TAM; i++){
        inicializar_a_lista(&t[i]);//Já que cada posição do vetor tem uma lista, eu preciso mandar o endereço da posição do vetor.
    }
}

int funcaoHash(int chave){
    return chave % TAM;
}

void inserir_valor(Lista t[], int valor){
    int indice = funcaoHash(valor);
    inserir_na_lista(&t[indice], valor);
}

int buscar_valor(Lista t[], int chave){
    int indice = funcaoHash(chave);
    return buscar_na_lista(&t[indice], chave);
}

void imprimir(Lista t[]){
    for(int i = 0; i < TAM; i++){
        printf("%2d = ", i);
        imprimir_lista(&t[i]);
        printf("\n");
    }
}

int main(){
    int opcao = 1, valor = 0, retorno = 0;
    Lista tabela[TAM];

    inicializar_a_tabela(tabela);

	do{
        printf("\n0 - Encerrar\n1 - Inserir\n2 - Buscar\n3 -Imprimir\n");
        scanf("%d", &opcao);

        if(opcao){
        	if(opcao == 1){
            	printf("Digite o valor que deseja inserir: ");
            	scanf("%d", &valor);
            	inserir_valor(tabela, valor);
            } else if(opcao == 2){
            	printf("Digite o valor que deseja buscar: ");
            	scanf("%d", &valor);
            	retorno = buscar_valor(tabela, valor);
            	if(retorno != 0){
                	printf("O valor %d foi encontrado.\n", retorno);
                } else {
                	printf("O valor procurado nao foi encontrado.\n");
                }
            } else if(opcao == 3){
            	imprimir(tabela);
        	} else {
            	printf("E preciso digitar uma opcao valida.\n");
            }
        }
    } while(opcao != 0);
    
    return 0;
}
