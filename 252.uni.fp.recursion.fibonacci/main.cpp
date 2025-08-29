#include <iostream>
using namespace std;
//funcion prototipo
unsigned long fibonacci(unsigned long);
int main()
{
     //calcular fibonacci de 0 a 10
    for(int i=0;i<=10;i++)
        cout<<"fibonacci("<<i<<")="<<fibonacci(i)<<endl;
    return 0;
}
//implementacion de la funcion factorial
unsigned long fibonacci(unsigned long n){
    if((n==0)||(n==1))
        return n;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}
