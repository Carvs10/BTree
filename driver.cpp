#include "btree.hpp"

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

    cout << "Percorrimento da árvore construída é ";
    arvore.percorrer();

    int k = 6;
    (arvore.buscar(k) != nullptr) ? cout << "\nPresente" : cout << "\nNão presente";
    
    k = 15;
    (arvore.buscar(k) != nullptr) ? cout << "\nPresente" : cout << "\nNão presente";

    cout << endl;

    arvore.remover(6); 
    cout << "Traversal of tree after removing 6\n"; 
    arvore.percorrer(); 
    cout << endl; 
  
    arvore.remover(13); 
    cout << "Traversal of tree after removing 13\n"; 
    arvore.percorrer(); 
    cout << endl; 
  
    arvore.remover(7); 
    cout << "Traversal of tree after removing 7\n"; 
    arvore.percorrer(); 
    cout << endl; 
  
    arvore.remover(4); 
    cout << "Traversal of tree after removing 4\n"; 
    arvore.percorrer(); 
    cout << endl; 
  
    arvore.remover(2); 
    cout << "Traversal of tree after removing 2\n"; 
    arvore.percorrer(); 
    cout << endl; 
  
    arvore.remover(16); 
    cout << "Traversal of tree after removing 16\n"; 
    arvore.percorrer(); 
    cout << endl; 

    return 0;
}