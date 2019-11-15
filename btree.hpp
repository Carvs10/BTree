#ifndef BTREE
#define BTREE

#include <iostream>

using namespace std;

// Nó da Árvore B
class Pagina
{
	int *chaves;    // array de chaves 
	int d;          // define o número de chaves em cada página
	Pagina **F;     // lista de ponteiros filhos
	int n;          // num de chaves atual
	bool folha;     // true se o node é folha

    public:
	Pagina(int _d, bool _folha); //Construtor 

    void inserirNaoCheio(int chave);
    void cisar(int i, Pagina *t);
	void percorrer(); 
	Pagina *buscar(int chave);  // retorna nullptr se a chave não esta na árvore 

    friend class ArvoreB;   
};

class ArvoreB
{
	Pagina *raiz;
	int d;

    public:
	ArvoreB(int _d) { raiz = nullptr; d = _d; }

    void percorrer() { if (raiz != nullptr) raiz->percorrer(); }
	Pagina* buscar (int chave) { return (raiz == nullptr) ? nullptr : raiz->buscar(chave); }

    void inserir (int chave);
};

#endif