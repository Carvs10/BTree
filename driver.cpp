#include "btree.hpp"

int main () {
    ArvoreB arvore = ArvoreB(3);

    arvore.inserir(10);
    arvore.inserir(20);
    arvore.inserir(5);
    arvore.inserir(6);
    arvore.inserir(12);
    arvore.inserir(30);
    arvore.inserir(7);
    arvore.inserir(17);

    cout << "Percorrimento da árvore construída é ";
    arvore.percorrer();

    int k = 6;
    (arvore.buscar(k) != nullptr) ? cout << "\nPresente" : cout << "\nNão presente";
    
    k = 15;
    (arvore.buscar(k) != nullptr) ? cout << "\nPresente" : cout << "\nNão presente";

    cout << endl;

    return 0;
}