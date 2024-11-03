#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int pai (int i){
    return ((i-1)/2);
}


//filho a esquerda
int fiesq(int i){
    return ((2*i)+1);
}

// filho a direita
int fidir(int i){
    return ((2*i)+2);
}


int trocar(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void inserir(int a[], int dado, int *n){
    if ( *n >= MAX){
        printf ("ERRO !!!, OVERFLOW\n");
        return;
    }
    // inserindo no ultimo elemento
    a[*n] = dado;
    *n = *n + 1;
    //fazendo a troca se possivel (maxheap)
    int i = *n - 1; // ultimo elemento inserido
    while (i != 0 && a[i] > a[pai(i)]){
        trocar(&a[i], &a[pai(i)]);
        i = pai(i);
    }
}

void heapify(int a[], int i, int n){
    int fesq = fiesq(i);
    int fdir = fidir(i);
    int minimo = i;

    if (fesq <= n && a[fesq] > a[minimo]){
        minimo = fesq;
    }
    if (fdir <= n && a[fdir] > a[minimo]){
        minimo = fdir;
    }

    if (minimo != i)
    {
        trocar(&a[i], &a[minimo]);
        heapify(a, minimo, n);
    }
    
}

int remover(int a[], int *n){
    if (*n <= 0)
        return MAX;
    if (*n == 1){
       (*n)--;
       return a[0];
    }
    
    
    int max = a[0];
    a[0] = a[*n - 1];
    (*n)--;
    heapify(a, 0, *n);
    return max;
}

int imprimir(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}