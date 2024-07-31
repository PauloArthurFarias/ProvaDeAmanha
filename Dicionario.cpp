#include <iostream>
using namespace std;

struct dicionario
{

    struct noh
    {
        noh* proximo;
        int chave;
        string valor;
    };

    noh* primeiro;

    dicionario()
    {
        primeiro = nullptr;
    }

    bool consultar_pertence(int c)
    {
        noh* aux = primeiro;
        while(aux != nullptr)
        {
            if(aux->chave == c)
            {
                return true;
            }
            aux = aux->proximo;
        }
        return false;
    }

    void inserir(int c, string v)
    {
        if(primeiro == nullptr)
        {
            noh* novo = new noh;
            novo->chave = c;
            novo->valor = v;
            primeiro = novo;
            primeiro->proximo = nullptr;
        }
        else if(consultar_pertence(c) == false)
        {
            noh* novo = new noh;
            novo->chave = c;
            novo->valor = v;
            noh* aux = primeiro;
            while (aux != nullptr)
            {
                if(aux->proximo == nullptr)
                {
                    aux->proximo = novo;
                    novo->proximo = nullptr;
                    aux = nullptr;
                    delete aux;
                    break;
                }
                aux = aux->proximo;
            }
        }
        else{
            cout << "Chave ja pertence ao dicionario\n";
        }
    }

    void remover(int c)
    {
        if(consultar_pertence(c) == false)
        {
            cout << "O Elemento nao pertence ao dicionario\n";
        }
        else if(primeiro->chave == c)
        {
            noh* aux = primeiro;
            primeiro = primeiro->proximo;
            delete aux;
        }
        else
        {
            noh* aux1 = new noh;
            noh* aux2 = new noh;
            aux1 = primeiro;
            while(aux1 != nullptr)
            {   
                aux2 = aux1->proximo;
                if(aux2->chave == c)
                {
                    aux1->proximo = aux2->proximo;
                    delete aux2;
                    break;
                }
                aux1 = aux1->proximo;
            }
        }
    }

    void imprimir()
    {
        noh* temp1 = primeiro;
        if(primeiro == nullptr)
        {
            cout << "Dicionario vazio\n";
        }
        while(temp1 != nullptr)
        {
            cout << "[";
            cout << temp1->chave << ":" << temp1->valor;
            cout << "]";
            temp1 = temp1->proximo;
        }
    }

};

int main(){
    dicionario dicionario1;
    int chave;
    string valor;
    int option;
    cout << "Programa Gerador de dicionario: \n";
    
    do {
        cout << "\nDigite 0 para parar o programa !\n";
        cout << "Digite 1 para inserir um elemento !\n";
        cout << "Digite 2 para remover um elemento !\n";
        cout << "Digite 3 para printar o dicionario !\n";
        cin >> option;

        if(option == 1){
            cout << "Digite a chave e o valor: \n";
            cin >> chave >> valor;
            dicionario1.inserir(chave, valor);
        }

        if(option == 2){
            cout << "Digite a chave do elemento a ser removido\n";
            cin >> chave;
            dicionario1.remover(chave);
        }

        if(option == 3){
            dicionario1.imprimir();
        }

    } while(option != 0);

    cout << "Programa Finalizado !";
}
