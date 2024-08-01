#include <iostream>
using namespace std;

int remover_ocorrencia(double v[], int n, double x) {

//removendo ocorrências
int ultimo = n;
for(int i = 0; i < n; i++) {
    if(v[i] == x){
        for(int j = i; j < n - 1; j++) {
            v[j] = v[j+1];
            ultimo --;
        }
    }
}

//contando novo tamanho

return ultimo - 1;

}


int main(){

    double v[5] = {1,1,2,2,1};
    for(int i = 0; i < 5; i++) {
        cout << v[i];
    }
    cout << endl;
    remover_ocorrencia(v, 5, 1);
    for(int i = 0; i < 5; i++) {
        cout << v[i];
    }
    cout << endl;
    cout << remover_ocorrencia(v, 5, 1);





}