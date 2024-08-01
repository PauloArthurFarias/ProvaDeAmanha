#include <iostream>
using namespace std;

struct pilha
{
    int tamanho = 5;
    int* vetor = new int[tamanho];
    int* novo_vetor;
    int topo;

    pilha()
    {
        topo = -1;
    }

    void inserir(int item)
    {
        if(topo == -1)
        {
            topo = 0;
            vetor[topo] = item;
            topo++;
        }
        else if(topo > tamanho - 1) {
            novo_vetor = new int[tamanho * 2];
            for(int i = 0; i < tamanho; i++)
            {
                novo_vetor[i] = vetor[i];
            }
            tamanho = tamanho*2;
            int* aux = vetor;
            vetor = novo_vetor;
            delete[] aux;
            vetor[topo] = item;
            topo++;
        }
        else
        {
            vetor[topo] = item;
            topo++;
        }
    }

    void remover()
    {
        vetor[topo - 1] = NULL;
        topo = topo - 1;
    }

    void imprimir()
    {
        for(int i = 0; i < topo; i++)
        {
            cout << vetor[i] << " ";
        }
    }
};

int main(){

    pilha pilha1;
    pilha1.inserir(1);
    pilha1.inserir(1);
    pilha1.inserir(1);
    pilha1.inserir(1);
    pilha1.inserir(1);
    pilha1.inserir(1);
    pilha1.imprimir();
    cout << "\n";
    pilha1.remover();
    pilha1.imprimir();
    cout << "\n";
    pilha1.inserir(1);
    pilha1.imprimir();
}
