#include <iostream>
using namespace std;

void inverter(double* p, int n)
{
    double* auxiliar = new double[n];
    int j = n - 1;
    for(int i = 0; i < n; i++)
    {
        auxiliar[j] = p[i];
        j--;
    }

    for(int i = 0; i < n; i++)
    {
        cout << auxiliar[i];
    }
}

int main(){

double* teste = new double[5];
for(int i = 0; i < 5; i++)
{
    cin >> teste[i];
}

inverter(teste, 5);




}