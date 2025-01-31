#include <iostream>
using namespace std;

struct PilhaDinamica
{
    struct noh
    {
        noh* proximo;
        int valor;
    };

    noh* topo;

    PilhaDinamica()
    {
        topo = nullptr;
    }

    bool estacheio()
    {
        try
        {
           noh* novo = new noh;
           delete novo; 
           return false;
        }
        catch(bad_alloc exception)
        {
            cout << "Nao tem mais memoria !";
            return true;
        }
    }

    bool estavazio()
    {
        return(topo == nullptr);
    }

    void empilhar(int n)
    {
        if(estacheio()){
            cout << "Impossivel empilhar";
        } else {
            noh* novo = new noh;
            novo->proximo = topo;
            topo = novo;
            topo->valor = n;
        }
    }

    void desempilhar()
    {
        if(estavazio()){
            cout << "Ja esta vazio!";
        } else {
            noh* temp;
            temp = topo;
            topo = topo->proximo;
            delete temp;
        }
    }

    void imprimir()
    {
        noh* temporario;
        temporario = topo;
         cout << "=\n";
        while(temporario != nullptr){
            cout << temporario->valor;
            temporario = temporario->proximo;
            cout << "\n";
        }
        cout << "=\n";
    }

    void destrutor()
    {
        while(topo !=nullptr){
            noh* temporario = topo;
            topo = topo->proximo;
            delete temporario;
        }
    }
    
};


int main() {
    PilhaDinamica pilha1;
    int item;
    int option;
    cout << "Programa Gerador de pilha: \n";
    
    do {
        cout << "Digite 0 para parar o programa !\n";
        cout << "Digite 1 para inserir um elemento !\n";
        cout << "Digite 2 para remover um elemento !\n";
        cout << "Digite 3 para printar a pilha !\n";
        cin >> option;

        if(option == 1){
            cout << "Digite o elemento a ser inserido: \n";
            cin >> item;
            pilha1.empilhar(item);
            cout << "Elemento inserido com sucesso !\n";
        }

        if(option == 2){
            pilha1.desempilhar();
        }

        if(option == 3){
            pilha1.imprimir();
        }

    } while(option != 0);

    cout << "Programa Finalizado !";

}