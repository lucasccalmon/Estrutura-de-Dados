#include <iostream>

using namespace std;

struct dupla {
    int info;
    dupla * prox;
    dupla * ant;
};

void inserir(dupla ** t, dupla ** u) {
    dupla * p;
    p = new dupla;
    cin >> p -> info;
    p -> ant = p;
    if ( * t == NULL) {
        p -> prox = p;
        * t = * u = p;
    } else {
        ( * u) -> prox = p;
        ( * t) -> ant = p;
        p -> prox = ( * t);
        p -> ant = ( * u);
        ( * u) = p;

    }
}

void remover(dupla ** t, dupla ** u) {
    int op;

    cout << "Deseja retirar o primeiro valor inserido(1), do ultimo(2) ou de um Valor específico(3)" << endl;
    cin >> op;
    if (op == 2) {
        if ( * t != NULL) {
            dupla * p = * u;
            dupla * j = ( * u) -> ant;
            j -> prox = * t;
            ( * t) -> ant = j;
            delete(p);
            ( * u) = j;
        } else cout << "\nLista Vazia!";

    } else if (op == 1) {
        if ( * t != NULL) {
            dupla * p = * t;
            dupla * j = ( * t) -> prox;
            j -> ant = ( * u);
            ( * u) -> prox = j;
            delete(p);
            ( * t) = j;
        } else cout << "\nLista Vazia!";
    } else if (op == 3) {
        int k;
        bool encontrei = false;
        if ( * t == NULL) {
            cout << "\nLista Vazia!";
        } else {
            cout << "Insira o número que deseja retirar:" << endl;
            cin >> k;
            dupla * p = * t;
            do {
                if (p -> info == k) {
                    if (p == * t) {
                        dupla * p = * t;
                        dupla * j = ( * t) -> prox;
                        j -> ant = ( * u);
                        ( * u) -> prox = j;
                        delete(p);
                        ( * t) = j;
                        encontrei = true;
                        break;

                    } else if (p == * u) {
                        dupla * p = * u;
                        dupla * j = ( * u) -> ant;
                        j -> prox = * t;
                        ( * t) -> ant = j;
                        delete(p);
                        ( * u) = j;
                        encontrei = true;
                        break;
                    } else {
                        dupla * k, * l;
                        l = p -> ant;
                        k = p -> prox;
                        l -> prox = k;
                        k -> ant = l;
                        delete(p);
                        encontrei = true;
                        break;
                    }
                } else p = p -> prox;
                encontrei = false;
            } while (p != * t);
            if (encontrei == false) {
                cout << "\nElemento não encontrado";
            }
        }
    } else cout << "\nNumero Invalido";
}

void listar(dupla * t, dupla * u) {
    int op = 0;
    dupla * p;
    cout << "\nListar começando do primeiro valor inserido(1), ou do ultimo(2)" << endl;
    cin >> op;
    if (op == 2) {
        if (t != NULL) {
            p = u;
            cout << p -> info << endl;
            p = p -> ant;
            while (p != u) {
                cout << p -> info << endl;
                p = p -> ant;
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
void menu(dupla * t, dupla * u) {
    int op = 5;
    do {
        cout << "\nEscolha uma opção(0=SAIR|1=Add e|2=Deletar|3=Listar)" << endl;
        cin >> op;
        switch (op) {
        case 1:
            inserir( & t, & u);
            break;
        case 2:
            remover( & t, & u);
            break;
        case 3:
            listar(t, u);
        }
    } while (op != 0);
}
int main() {
    dupla * topo = NULL;
    dupla * ult = NULL;
    menu(topo, ult);
}