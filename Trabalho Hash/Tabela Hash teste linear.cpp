#include <stdio.h>
#include <stdlib.h>

#define TAM 13

void inicializar_a_tabela(int t[]){
    for(int i = 0; i < TAM; i++)
        t[i] = 0;
}

int funcaoHash(int chave){
    return chave % TAM;
}

void inserir_valor(int t[], int valor){
    int id = funcaoHash(valor);
    while(t[id] != 0){
        id = funcaoHash(id + 1);
    }
    t[id] = valor;
}

int buscar_valor(int t[], int chave){
    int id = funcaoHash(chave);
    printf("\nIndice gerado: %d\n", id);
    while(t[id] != 0){
        if(t[id] == chave)
            return t[id];
        else
            id = funcaoHash(id + 1);
    }
    return 0;
}

void imprimir(int t[]){
    for(int i = 0; i < TAM; i++){
        printf("%d = %d\n", i, t[i]);
    }
}

int main(){

    int opcao = 1, valor = 0, retorno = 0, tabela[TAM];

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
