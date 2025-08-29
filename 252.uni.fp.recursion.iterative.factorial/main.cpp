#include <iostream>
#include <iomanip>
using namespace std;
//funcion prototipo
unsigned long factorial(unsigned long);

int main()
{
     //calcular los factoriales de 0 a 10
    for(int i=0;i<=10;i++)
        cout<<setw(2)<<i<<"!="<<factorial(i)<<endl;
    return 0;
}
//implementacion de la funcion factorial con el metodo iterativo
unsigned long factorial(unsigned long n){
    unsigned long result=1;
    for(unsigned long i=n;i>=1;i--)
        result*=i;
    return result;
}
