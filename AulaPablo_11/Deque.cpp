#include <iostream>
using namespace std;

struct deque
{
    struct noh
    {
        noh* anterior;
        noh* proximo;
        int valor;
    };

    noh* esquerda;
    noh* direita;

    deque()
    {
        esquerda = nullptr;
        direita = nullptr;
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
            cout << "Memoria insuficiente\n";
            return true;
        }
    }

    bool estavazio()
    {
        return(esquerda == nullptr);
    }

    void inserir_direita(int item)
    {
        if(estacheio())
        {
            cout << "Impossivel inserir";
        }
        else
        {
            if(estavazio())
            {
                noh* novo = new noh;
                novo->anterior = nullptr;
                novo->proximo = nullptr;
                novo->valor = item;
                direita = novo;
                esquerda = novo;
            }
            else
            {
                noh* novo = new noh;
                novo->valor = item;
                direita->proximo = novo;
                novo->anterior = direita;
                direita = direita->proximo;
                direita->proximo = nullptr;
            }
        }
    }

    void inserir_esquerda(int item)
    {
         if(estacheio())
        {
            cout << "Impossivel inserir";
        }
        else
        {
            if(estavazio())
            {
                noh* novo = new noh;
                novo->anterior = nullptr;
                novo->proximo = nullptr;
                novo->valor = item;
                direita = novo;
                esquerda = novo;
            }
            else
            {
                noh* novo = new noh;
                novo->valor = item;
                esquerda->anterior = novo;
                novo->proximo = esquerda;
                esquerda = esquerda->anterior;
                novo->anterior = nullptr;
            }
        }
    }

    void remover_esquerda()
    {
        if(estavazio())
        {
            cout << "Impossivel remover, ja esta vazio !\n";
        }
        else
        {
            if(esquerda == direita)
            {
                noh* aux = new noh;
                aux = esquerda;
                esquerda = nullptr;
                direita = nullptr;
                delete aux;
            }
            else
            {
                noh* aux = new noh;
                aux = esquerda;
                esquerda = esquerda->proximo;
                delete aux;
                esquerda->anterior = nullptr;
            }
        }
    }

    void remover_direita()
    {
        if(estavazio())
        {
            cout << "Impossivel remover, ja esta vazio !\n";
        }
        else
        {
            if(esquerda == direita)
            {
                noh* aux = new noh;
                aux = esquerda;
                esquerda = nullptr;
                direita = nullptr;
                delete aux;
            }
            else
            {
                noh* aux = new noh;
                aux = direita;
                direita = direita->anterior;
                delete aux;
                direita->proximo = nullptr;
            }
        }
    }

    void imprimir()
    {
        noh* temp = new noh;
        temp = esquerda;
        cout << "[";
        while(temp != nullptr)
        {
            cout << " " << temp->valor << " ";
            temp = temp->proximo;
        }
        cout << "]\n";
    }

};



int main(){

    deque deque1;
    int item;
    int option;
    cout << "Programa Gerador de fila dupla: \n";
    
    do {
        cout << "Digite 0 para parar o programa !\n";
        cout << "Digite 1 para inserir um elemento na esquerda !\n";
        cout << "Digite 2 para inserir um elemento na direita !\n";
        cout << "Digite 3 para remover um elemento na esquerda !\n";
        cout << "Digite 4 para remover um elemento na direita !\n";
        cout << "Digite 5 para printar a fila !\n";
        cin >> option;

        if(option == 1){
            cout << "Digite o elemento a ser inserido: \n";
            cin >> item;
            deque1.inserir_esquerda(item);
            cout << "Elemento inserido com sucesso !\n";
        }

        if(option == 2){
            cout << "Digite o elemento a ser inserido: \n";
            cin >> item;
            deque1.inserir_direita(item);
            cout << "Elemento inserido com sucesso !\n";
        }

        if(option == 3){
            deque1.remover_esquerda();
        }

        if(option == 4){
            deque1.remover_direita();
        }

        if(option == 5){
            deque1.imprimir();
        }

    } while(option != 0);

    cout << "Programa Finalizado !";

}