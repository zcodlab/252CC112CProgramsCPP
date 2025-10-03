#include <iostream>
using namespace std;
const int MAX=100;

void invertirArray(int* X,int ini,int fin){
    while(ini<fin){
            //similar a un intercambio(swap)
            int temp=*(X+ini);
            *(X+ini)=*(X+fin);
            *(X+fin)=temp;
            ini++;
            fin--;
    }
}

void rotacionDerecha(int* X,int n,int k){
    k=k%n;
    invertirArray(X,0,n-1);
    invertirArray(X,0,k-1);
    invertirArray(X,k,n-1);
}

void rotacionIzquierda(int* X,int n,int k){
    k=k%n;
    invertirArray(X,0,n-1);
    invertirArray(X,0,n-k-1);
    invertirArray(X,n-k,n-1);
}

void imprimir(int* X,int n){
    for(int i=0; i<n;i++)
        cout<< *(X+i)<<" ";
    cout<<endl;
}

int main()
{
    int X[MAX], n,k;
    string direccion;
    cout<<"Ingrese el tamaño del arreglo (max 100): ";
    cin>>n;
    cout<<"Ingrese los datos del arreglo: "<<endl;
    for(int i=0;i<n;i++)
        cin>>*(X+i);
    cout<<"Ingrese el valor de k(posiciones a rotar): "<<endl;
    cin>>k;
    cout<<"Desea rotar a la derecha o izquierda?: "<<endl;
    cin>>direccion;
    if(direccion=="derecha"){
            rotacionDerecha(X,n,k);
            cout<<"Arreglo rotado a la derecha"<<endl;
            imprimir(X,n);
    }else if(direccion=="izquierda"){
            rotacionIzquierda(X,n,k);
            cout<<"Arreglo rotado a la izquierda"<<endl;
            imprimir(X,n);
    }else
            cout<<"Direccion invalida"<<endl;

    return 0;
}
