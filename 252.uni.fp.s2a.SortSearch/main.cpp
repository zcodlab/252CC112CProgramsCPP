#include <iostream>
#include "sort.h"
using namespace std;

const int MAX=100; //tamaño maximo permitido para el arreglo

int main()
{
    int X[MAX], C[MAX];     //arrays estaticos, C se utilizara como copia de X con la finalidad de matener los datos originales y poder someter a prueba los diferentes algoritmos de ordenamiento
    int n=0;
    cout << "Ingrese el tamaño del array (max: "<<MAX<<" ): ";
    cin>>n;
    //validar el valor ingresado
    if(n>MAX || n<=0){
            cout<<"Tamaño ingresado es invalido."<<endl;
            return 0;
    }
    //Invocar al menu de operaciones
    menu(X,C,n);
    return 0;
}
