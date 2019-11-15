#include "btree.hpp"

Pagina::Pagina(int _d, bool _folha) {
	d = _d;
	folha = _folha;

	chaves = new int[2*d + 1];
	F = new Pagina *[2*d];

	n = 0;
}

void Pagina::percorrer() {
	int i;
	for(i = 0; i < n; i++) {
		if(!folha)
			F[i]->percorrer();
		
        cout << " " << chaves[i]; 
	}

	if (!folha)
		F[i]->percorrer();
}

Pagina * Pagina::buscar(int chave) {
	int i = 0;

	while(i < n && chave > chaves[i])
		i++;

    if(chaves[i] == chave)
        return this;

	if (folha)
		return nullptr;

	return F[i]->buscar(chave);
}

void ArvoreB::inserir(int chave) {
    if (raiz == nullptr) {
        raiz = new Pagina(d, true);
        raiz->chaves[0] = chave;
        raiz->n = 1;
    } else {
        if (raiz->n == 2*d + 1) {
            Pagina *s = new Pagina(d, false);
            s->F[0] = raiz;
            s->cisar(0, raiz);

            int i = 0;

            if (s->chaves[0] < chave)
                i++;

            s->F[i]->inserirNaoCheio(chave);

            raiz = s;            
        } else {
            raiz->inserirNaoCheio(chave);
        }
    }
}

void Pagina::inserirNaoCheio(int chave) {
    int i = n - 1;

    if (folha) {
        while (i >= 0 && chaves[i] > chave) {
            chaves[i + 1] = chaves[i];
            i--;
        }

        chaves[i + 1] = chave;
        n = n + 1;
    } else {
        while (i >= 0 && chaves[i] > chave)
            i--;

        if (F[i + 1]->n == 2 * d + 1) {
            cisar(i + 1, F[i + 1]);

            if (chaves[i + 1] < chave)
                i++;
        }

        F[i + 1]->inserirNaoCheio(chave);
    }
}

void Pagina::cisar(int i, Pagina *y) {
    Pagina *z = new Pagina(y->d, y->folha);
    z->n = d + 1;

    for (int j = 0; j < d + 1; j++)
        z->chaves[j] = y->chaves[j + d];

    if (!y->folha) {
        for (int j = 0; j < d; j++)
            z->F[j] = y->F[j + d];
    }

    y->n = d - 1;

    for (int j = n; j >= i+1; j--)
        F[j + 1] = F[j];

    F[i + 1] = z;

    for (int j = n - 1; j >= i; j--)
        chaves[j + 1] = chaves[j];

    chaves[i] = y->chaves[d - 1];

    n++;
}