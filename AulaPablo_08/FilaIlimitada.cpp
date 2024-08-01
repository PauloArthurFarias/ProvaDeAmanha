#include <iostream>
using namespace std;

struct fila
{
    int primeiro, ultimo, tamanho = 5;
    int* vetor = new int[5];
    int* vetor_novo;
    
    fila()
    {
        primeiro = NULL;
        ultimo = NULL;
    }

    void inserir(int item)
    {
        if(ultimo == NULL)
        {
            primeiro = 0;
            ultimo = 0;
            vetor[ultimo] = item;
            ultimo++;
        }
        else if(ultimo > tamanho - 1)
        {
            vetor_novo = new int[tamanho * 2];
            for(int i = 0; i < tamanho; i++)
            {
                vetor_novo[i] = vetor[i];
            }
            tamanho = tamanho * 2;
            int* auxiliar = vetor;
            vetor = vetor_novo;
            vetor[ultimo] = item;
            ultimo++;
            delete[] auxiliar;
        }
        else{
            vetor[ultimo] = item;
            ultimo++;
        }
    }

    void remover()
    {
        if(primeiro == ultimo)
        {
            vetor[primeiro] = NULL;
            primeiro = NULL;
            ultimo = NULL;
        }
        else
        {
            vetor[primeiro] = NULL;
            primeiro++;
        }
    }

    void imprimir()
    {
        for(int i = 0; i < ultimo; i++)
        {
            if(vetor[i] == NULL)
            {
                continue;
            }
            cout << vetor[i];
        }
    }
};

int main(){
    fila fila1;
    fila1.inserir(1);
    fila1.inserir(2);
    fila1.inserir(3);
    fila1.inserir(4);
    fila1.inserir(5);
    fila1.inserir(6);
    fila1.imprimir();
    cout << "\n";
    fila1.remover();
    fila1.remover();
    fila1.imprimir();
    cout << "\n";
    fila1.inserir(5);
    fila1.inserir(6);
    fila1.imprimir();
}
