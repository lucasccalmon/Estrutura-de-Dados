#include <iostream>
using namespace std;
void insertionSort(int V[], int tot){
    int i, aux, j, z;
    aux=0;

    for(i=1; i<tot;i++)
        for(j=i; j>0; j--) {
            if(V[j-1] > V[j]){
                aux = V[j-1];
                V[j-1] = V[j];
                V[j] = aux;
            }
            //usei para ajudar no entendimento da estrutura
            // for(z=0;z<6;z++) {
            //     printf("aux: %d ", aux);
            //     printf("i: %d ", i);
            //     printf("j: %d ", j);
            //     for(z=0;z<6;z++)
            //         printf("%d ", V[z]);
            // }

        }
    for(z=0;z<tot;z++)
        cout << V[z] <<endl;
}

int main(){
    int total = 8;
    int V[8]={90, 76, 15, 23, 56, 38, 12, 3};
    insertionSort(V, total);
}