#include <iostream>
using namespace std;
void bubbleSort(int V[], int tot){
    int i, aux, j;
    //n=6;
    aux=0;

    for(i=0; i<tot-1; i++)
        for(j=i+1; j<tot; j++)                
            if(V[i]>V[j])
            {
                aux = V[i];
                V[i] = V[j];
                V[j] = aux;
            }
    
    for(i=0;i<tot;i++)
        cout << V[i] <<endl;
}
int main(){
    int total = 8;
    int V[8]={90, 76, 15, 23, 56, 38, 12, 3};
    bubbleSort(V, total);

   
return 0;
}