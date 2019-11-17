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

int Pagina::acharChave(int chave)
{
    int indice = 0;

    while( indice < n && chaves[indice] < chave)
    {
        ++indice;
    }

    return indice;
}

void Pagina::remover(int chave)
{
    int indice = acharChave(chave);

    if (indice < n && chaves[indice] == chave) {
        if(folha)
            removerDeFolha(indice);
        else
            removerDeNaoFolha(indice);
    } else {
        if(folha) {
            cout << "A chave " << chave << " nao esta na arvore\n";
            return;
        }

        bool flag = ( (indice == n) ? true : false); 

        if(F[indice]->n < d)
            preencher(indice);

        if(flag && indice > n)
            F[indice-1]-> remover(chave);
        else
            F[indice]-> remover(chave);
    }

    return;
}

void Pagina::removerDeFolha(int indice) {
    for(int i = indice+1; i < n; ++i) {
        chaves[i - 1] = chaves[i];
    }

    n--;

    return;
}

void Pagina::removerDeNaoFolha(int indice) {
    int chave = chaves[indice];

    if(F[indice] ->n >= d )
    {
        int antecessor = getAntecessor(indice);
        chaves[indice] = antecessor;
        F[indice]-> remover(antecessor); 
    } else if ( F[indice+1] -> n >= d ) {
        int sucessor = getSucessor(indice);
        chaves[indice] = sucessor;
        F[indice+1] -> remover(chave);
    } else {
        concatenar(indice);
        F[indice]->remover(chave);
    }

    return;
}

int Pagina::getAntecessor(int indice) {
    Pagina *atual = F[indice];
    while(!atual ->folha)
        atual = atual->F[atual->n];

    return atual->chaves[atual->n-1];
}

int Pagina::getSucessor(int indice) {
    Pagina *atual = F[indice+1];

    while(!atual -> folha)
        atual = atual->F[0];

    return atual->chaves[0];
}


void Pagina::preencher(int indice) {
    if(indice != 0 && F[indice-1] ->n >= d) {
        pegarDoAnt(indice);
    } else if(indice != n && F[indice+1] -> n >= d) {
        pegardoProx(indice);
    } else {
        if(indice != n)
            concatenar(indice);
        else
            concatenar(indice-1);
    }

    return;
}

void Pagina::pegarDoAnt(int indice) {
    Pagina *filho = F[indice];
    Pagina *irmao = F[indice-1];

    for( int i = filho->n-1; i >=0; --i)
        filho->chaves[i+1] = filho->chaves[i];

    if(!filho -> folha) {
        for(int i =filho->n; i>=0; --i )
        {
            filho->F[i+1] = filho->F[i];
        }
    }

    filho->chaves[0] = chaves[indice-1];

    if(!filho->folha)
    {
        filho->F[0] = irmao->F[irmao->n];
    }

    chaves[indice-1] = irmao->chaves[irmao->n-1];

    filho->n += 1;
    irmao-> n -= 1;

    return;
}

void Pagina::pegardoProx(int indice) {
    Pagina *filho = F[indice];
    Pagina *irmao = F[indice+1];

    filho->chaves[(filho->n)] = chaves[indice];

    if(!(filho->folha) )
    {
        filho->F[ (filho->n)+1] = irmao->F[0];
    }

    chaves[indice] = irmao->chaves[0];

    for(int i = 1; i < irmao->n; ++i)
        irmao->chaves[i-1] = irmao->chaves[i];

    if(!irmao->folha)
    {
        for(int i =1; i <= irmao->n; ++i)
            irmao->F[i-1] = irmao->F[i];
    }

    filho->n += 1;
    irmao -= 1;

    return;
}

void Pagina::concatenar(int indice) {
    Pagina *filho = F[indice];
    Pagina *irmao = F[indice+1];

    filho->chaves[d-1] = chaves[indice];

    for (int i = 0; i < irmao->n; ++i)
    {
        filho->F[i+d] = irmao->F[i];
    }    

    for (int i = indice + 1; i < n; i++)
        chaves[i-1] = chaves[i];

    for(int i = indice + 2; i <= n; i++)
        F[i-1] = F[i];

    filho->n += irmao->n + 1;
    n--;

    delete(irmao);
    return;
}

void ArvoreB::remover (int chave) {
    if (!raiz) {
        cout << "A árvore está vazia\n";
        return;
    }

    raiz->remover(chave);

    if (raiz->n == 0) {
        Pagina *temp = raiz;

        if (raiz->folha)
            raiz = nullptr;
        else
            raiz = raiz->F[0];

        delete temp;
    }

    return;
}