#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void menu(){
    int a[MAX];
    int n = 0, op, dado;
    
    while (op != 4)
    {
       printf("selecione uma opção:\n");
       printf("1 - Inserir\n");
       printf("2 - Remover\n");
       printf("3 - Imprimir\n");
       printf("4 - Sair\n");
       scanf("%d", &op);

       switch (op){
        case 1:
            printf("Insira o valor a ser inserido: ");
            scanf("%d", &dado);
            inserir(a, dado, &n);
            break;
        case 2:
            printf("Removendo o elemeto da raiz...");
            remover(a, &n);
            break;
        case 3:
            printf("\nImprimindo...\n");
            imprimir(a, n);
            break;
        case 4:
            system("cls");
            printf("encerrando...");
            break;
       }
    }
    
    
}

int main(){
    menu();
    return 0;
}
