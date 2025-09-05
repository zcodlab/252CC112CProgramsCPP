#include <iostream>
#include <cmath>
using namespace std;

double f(double i,int n){
    if(i==n)    //caso base
        return n;

    return i+pow(-1,i)*round(i/2)/f(i+1,n); //llamada recursiva
}

int main()
{
    int n;
    cout << "Ingrese un entero: ";
    cin>>n;
    cout<<"El valor de x es: "<<1+1/f(1,n)<<endl;
    return 0;
}
