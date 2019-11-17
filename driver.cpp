#include "arvoreB.hpp"
#include <iostream>

using namespace std;

int main () {
    ArvoreB arvore = ArvoreB(3);

    arvore.inserir(1); 
    arvore.inserir(3); 
    arvore.inserir(7); 
    arvore.inserir(10); 
    arvore.inserir(11); 
    arvore.inserir(13); 
    arvore.inserir(14); 
    arvore.inserir(15); 
    arvore.inserir(18); 
    arvore.inserir(16); 
    arvore.inserir(19); 
    arvore.inserir(24); 
    arvore.inserir(25); 
    arvore.inserir(26); 
    arvore.inserir(21); 
    arvore.inserir(4); 
    arvore.inserir(5); 
    arvore.inserir(20); 
    arvore.inserir(22); 
    arvore.inserir(2); 
    arvore.inserir(17); 
    arvore.inserir(12); 
    arvore.inserir(6);

    cout << "A árvore construída é ";
    arvore.percorrer();

    int k = 6;
    (arvore.buscar(k) != nullptr) ? cout << "\nPresente" : cout << "\nNão presente";
    
    k = 15;
    (arvore.buscar(k) != nullptr) ? cout << "\nPresente" : cout << "\nNão presente";

    cout << endl;

    arvore.remover(6); 
    cout << "Árvore depois de remover 6\n"; 
    arvore.percorrer(); 
    cout << endl; 
  
    arvore.remover(13); 
    cout << "Árvore depois de remover 13\n"; 
    arvore.percorrer(); 
    cout << endl; 
  
    arvore.remover(7); 
    cout << "Árvore depois de remover 7\n"; 
    arvore.percorrer(); 
    cout << endl; 
  
    arvore.remover(4); 
    cout << "Árvore depois de remover 4\n"; 
    arvore.percorrer(); 
    cout << endl; 
  
    arvore.remover(2); 
    cout << "Árvore depois de remover 2\n"; 
    arvore.percorrer(); 
    cout << endl; 
  
    arvore.remover(16); 
    cout << "Árvore depois de remover 16\n"; 
    arvore.percorrer(); 
    cout << endl; 

    return 0;
}