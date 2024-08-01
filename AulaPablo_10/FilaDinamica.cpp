#include <iostream>
using namespace std;

struct filadinamica
{

struct noh
{
    int valor;
    noh* proximo;
};

noh* primeiro;
noh* ultimo;

filadinamica()
{
    primeiro = nullptr;
    ultimo = nullptr;
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
        cout << "Nao possui mais espaco na memoria.";
    }
}

bool estavazio()
{
    return(primeiro == nullptr);
}

void inserir(int item)
{   
    if(estacheio()){
        cout << "Impossivel inserir";
    } else {
        if(estavazio())
        {
            noh* novo = new noh;
            novo->valor = item;
            novo->proximo = nullptr;
            primeiro = novo;
            ultimo = novo;
        }
        else
        {
            noh* novo = new noh;
            ultimo->proximo = novo;
            ultimo = ultimo->proximo;
            novo->valor = item;
            novo->proximo = nullptr;
        }
    }
}

void remover()
{
    if(estavazio())
    {
        cout << "impossivel remover";
    } 
    else
    {
        if(primeiro == ultimo)
        {
            delete ultimo;
            primeiro = nullptr;
            ultimo = nullptr;
        }
        else
        {
            noh* temp;
            temp = primeiro;
            primeiro = primeiro->proximo;
            delete temp;
        }
    }
}

void imprimir()
{
    noh* temp = primeiro;
    cout << "[";
    while(temp != nullptr)
    {
        cout << temp->valor;
        temp = temp->proximo;
    }
    cout << "]";
}
};

int main() {
    filadinamica fila1;
    int item;
    int option;
    cout << "Programa Gerador de fila: \n";
    
    do {
        cout << "Digite 0 para parar o programa !\n";
        cout << "Digite 1 para inserir um elemento !\n";
        cout << "Digite 2 para remover um elemento !\n";
        cout << "Digite 3 para printar a fila !\n";
        cin >> option;

        if(option == 1){
            cout << "Digite o elemento a ser inserido: \n";
            cin >> item;
            fila1.inserir(item);
            cout << "Elemento inserido com sucesso !\n";
        }

        if(option == 2){
            fila1.remover();
        }

        if(option == 3){
            fila1.imprimir();
        }

    } while(option != 0);

    cout << "Programa Finalizado !";

}
