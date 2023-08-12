#include <iostream>

using namespace std;

struct simples {
    int info;
    simples * prox;

};

void add(simples ** t, simples ** u) {
    simples * p;
    p = new simples;
    cin >> p -> info;
  
    if ( * t == NULL) {
        p -> prox = p;
        * t = * u = p;
    } else {
        ( * u) -> prox = p;
  
        p -> prox = ( * t);
 
        ( * u) = p;

    }
}

void del(simples ** t, simples ** u) {
    int op;

    cout << "Deseja retirar o primeiro valor inserido(1), do ultimo(2) ou de um Valor específico(3)" << endl;
    cin >> op;
    // if (op == 2) {
    //     if ( * t != NULL) {
    //         simples * p = * u;
           
           
    //         delete(p);
    
    //     } else cout << "\nLista Vazia!";

    // } else 
        if (op == 1) {
        if ( * t != NULL) {
            simples * p = * t;
            simples * j = ( * t) -> prox;
          
            ( * u) -> prox = j;
            delete(p);
            ( * t) = j;
        } else cout << "\nLista Vazia!";
//     } else if (op == 3) {
//         int k;
//         bool encontrei = false;
//         if ( * t == NULL) {
//             cout << "\nLista Vazia!";
//         } else {
//             cout << "Insira o número que deseja retirar:" << endl;
//             cin >> k;
//             simples * p = * t;
//             do {
//                 if (p -> info == k) {
//                     if (p == * t) {
//                         simples * p = * t;
//                         simples * j = ( * t) -> prox;
                    
//                         ( * u) -> prox = j;
//                         delete(p);
//                         ( * t) = j;
//                         encontrei = true;
//                         break;

//                     } else if (p == * u) {
//                         simples * p = * u;
                       
         
                        
//                         delete(p);
                    
//                         encontrei = true;
//                         break;
//                     } else {
//                         simples * k, * l;

//                         k = p -> prox;
//                         l -> prox = k;
                      
//                         delete(p);
//                         encontrei = true;
//                         break;
//                     }
//                 } else p = p -> prox;
//                 encontrei = false;
//             } while (p != * t);
//             if (encontrei == false) {
//                 cout << "\nElemento não encontrado";
//             }
//         }
//     } else cout << "\nNumero Invalido";
}}

void listar(simples * t, simples * u) {
    int op = 0;
    simples * p;
    cout << "\nListar começando do primeiro valor inserido(1), ou do ultimo(2)" << endl;
    cin >> op;
    if (op == 2) {
        if (t != NULL) {
            p = u;
            cout << p -> info << endl;
           
            while (p != u) {
                cout << p -> info << endl;
             
            }
        } else {
            cout << "Lista vazia!\n";
            return;
        }

    } else if (op == 1) {
        if (t != NULL) {
            p = t;
            cout << p -> info << endl;
            p = p -> prox;
            while (p != t) {
                cout << p -> info << endl;
                p = p -> prox;
            }
        } else {
            cout << "Lista Vazia!\n";
            return;
        }
    } else cout << "\nNumero Invalido";
}
void menu(simples * t, simples * u) {
    int op = 5;
    do {
        cout << "\nEscolha uma opção(0=SAIR|1=Add e|2=Deletar|3=Listar)" << endl;
        cin >> op;
        switch (op) {
        case 1:
            add( & t, & u);
            break;
        case 2:
            del( & t, & u);
            break;
        case 3:
            listar(t, u);
        }
    } while (op != 0);
}
int main() {
    simples * topo = NULL;
    simples * ult = NULL;
    menu(topo, ult);
}