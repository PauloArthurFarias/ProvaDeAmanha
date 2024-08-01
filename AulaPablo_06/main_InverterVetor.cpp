#include <iostream>
using namespace std;

void inverter(double* p, int n) {
    int j = 0;
    double vetor_aux[n];
    for(int i = n - 1; i >= 0; i--){
        vetor_aux[j] = p[i]; 
        j++;
    }

    for(int i = 0; i < n; i++){
         if(i == 0){
            cout << "[";
        }
        cout << vetor_aux[i];
        if(i == n - 1) {
            cout << "]";
        }
    }
}


int main() {

    int n;
    cout << "Insira o tamanho N do vetor\n";
    cin >> n;
    double v[n];
    cout << "Insira os " << n << " elementos do vetor\n";
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    double *p = &v[0];

    cout << "--- PROGRAMA INVERSOR DE VETORES ---" << endl;
    cout << "Vetor inicial\n";
    for( int i = 0; i < n; i++) {
        if(i == 0){
            cout << "[";
        }
        cout << v[i];
        if(i == n - 1) {
            cout << "]";
        }
    }
    cout << "\nVetor invertido\n";
    inverter(p, 5);
    
}

