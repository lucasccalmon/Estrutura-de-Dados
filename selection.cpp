#include <iostream>
using namespace std;
void selectionSort(int V[], int tot){

    int i, aux, j, menor;
    aux=0;
    menor = 0;
    
    for (i = 0; i < tot - 1; i++) {
        menor = i;
        for (j = i + 1; j < tot; j++){
            if (V[menor] > V[j])
                menor = j;
        }
        aux = V[i];
        V[i] = V[menor];
        V[menor] = aux;
    }
    for(i=0;i<tot;i++)
        cout << V[i] <<endl;
}

int main(){
    int total = 8;
    int V[8]={90, 76, 15, 23, 56, 38, 12, 3};
    selectionSort(V, total);
}