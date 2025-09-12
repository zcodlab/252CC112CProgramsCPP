#include <iostream>
using namespace std;
const int MAX=100;

//devuelve el indice de insercion
int busquedaBinariaInsercion(int X[], int n, int objetivo){
    int izq=0, der=n;
    while(izq<der){
            int mid=(izq+der)/2;
            if(X[mid]<objetivo)
                izq=mid+1;
            else
                der=mid;

    }
    return izq;
}

int encuentraKElementosCercanos(int X[],int n,int objetivo,int k,int resultado[]){
    int i=busquedaBinariaInsercion(X,n,objetivo);
    int izq=i-1;
    int der=i;
    while(k-- > 0){
        if(izq <0 || (der<n && abs(X[izq]-objetivo) > abs(X[der]-objetivo)))
            der++;
        else
            izq--;
    }
    //copiar al array resultando en el orden origen
    int tamResultado=0;
    for(int j=izq+1;j<der;j++)
        resultado[tamResultado++] = X[j];

    return tamResultado;
}


void imprimir(int X[],int n){
    for(int i=0;i<n;i++)
        cout<<X[i]<<" ";
    cout<<endl;
}

int main()
{
    /*int entrada[]={10,12,15,17,18,20,25};
    int k=4,objetivo=16;*/

    /*int entrada[]={2,3,4,5,6,7};
    int k=2,objetivo=8;*/

    int entrada[]={2,3,4,5,6,7};
    int k=3,objetivo=1;

    int n=sizeof(entrada)/sizeof(entrada[0]);
    imprimir(entrada,n);
    cout <<"k: "<<k<<" objetivo: " <<objetivo<< endl;

    int resultado[MAX];
    int tamResultado=encuentraKElementosCercanos(entrada,n,objetivo,k,resultado);

    cout << "Resultado: " << endl;
    imprimir(resultado,tamResultado);


    return 0;
}
