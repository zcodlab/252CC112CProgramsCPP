#include <iostream>
#include <cmath>
using namespace std;
const int N=3;

//declarando prototipos de funcion
bool esPrimo(int);
int contarPrimos(int*,int);
int contarParesDiag(int*,int);
int sumaBajoDiagSec(int*,int);
void mostrarMatriz(int*,int);

int main()
{
    int A[N][N]={{5,8,13},{7,4,2},{6,9,11}};
    int opcion, n=N;
    int *p=*A; //declaracion de puntero a entero e inicializacion con la matriz A
    int (*operacion)(int *,int)=nullptr;

    mostrarMatriz(p,n);

    cout<<"Seleccion Operacion"<<endl;
    cout<<"1. Contar primos"<<endl;
    cout<<"2. Contar pares en la diagonal principal"<<endl;
    cout<<"3. Sumar debajo de la diagonal secundaria"<<endl;
    cout<<"Opcion:"<<endl;
    cin>>opcion;
    switch(opcion){
        case 1: operacion=contarPrimos; break;
        case 2: operacion=contarParesDiag; break;
        case 3: operacion=sumaBajoDiagSec; break;
        default:
            cout<<"Opcion invalida"<<endl;
            return 0;
    }

    int resultado=operacion(p,n);
    cout<<endl<<"Resultado: "<<resultado<<endl;

    return 0;
}
bool esPrimo(int x){
    if(x<2) return false;
    for(int i=2;i<=sqrt(x);i++)     //  i*i<=x
        if(x%i==0) return false;
    return true;
}

int contarPrimos(int* p,int n){
    int cont=0;
    for(int i=0;i<n*n;i++)
        if(esPrimo(*(p+i))) cont++;
    return cont;
}

int contarParesDiag(int* p,int n){
    int cont=0;
    for(int i=0;i<n;i++){
        int valor=*(p+i*n+i);
        if(valor%2==0) cont++;
    }
    return cont;
}

int sumaBajoDiagSec(int* p,int n){
    int suma=0;
     for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i+j>n-1)
                    suma+=*(p+ i*n + j);
            }
     }
    return suma;
}

void mostrarMatriz(int* p,int n){
    cout<<"Matriz ingresada y sus direcciones"<<endl;
     for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                    cout<<*(p+i*n+j)<<"("<<(p+i*n+j)<<")\t";
            cout<<endl;
     }
     cout<<endl;
}
