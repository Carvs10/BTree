#include <iostream>

using namespace std;

// Nó da Arvore B
class ArvBNode
{
	int t; // define o número de chaves em cada página
	ArvBNode **C; // lista de ponteiros filhos
	int n; // num de chaves atual
	int *keys; // array de chaves 
	bool leaf; // T se o node é folha

public:
	ArvBNode(int _t, bool leaf); //Construtor 

	ArvBNode *search(int k); // retorna NULL se a chave não esta na tree 

	void transverse(); 

};

class ArvB
{
	ArvBNode *root;
	int t;

public:

	ArvB(int _t)
	{ root = NULL; t = _t; }

	ArvBNode* search(int k)
	{ return (root == NULL) NULL : root->search(k); }


};

ArvBNode::ArvBNode(int _t, bool _leaf)
{
	leaf = _leaf;
	t = _t;


	keys = new int[2*t-1];
	C = new ArvBNode *[2*t];

	n = 0;
}