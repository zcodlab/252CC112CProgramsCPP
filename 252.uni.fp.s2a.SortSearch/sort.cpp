#include "sort.h"
using namespace std;
//Funcion que implementa el algoritmo selectionSort
void selectionSort(int X[], int n){
    for(int i=0; i<n-1;i++){
            int minIndex=i;
            for(int j=i+1; j<n;j++){
                    if(X[j]<X[minIndex])
                        minIndex=j;//actualizamos el indice que contiene el valor mas pequeño
            }
            //Realizar el intercambio
            if(minIndex!=i){
                    int temp=X[i];  //reservamos el valor de la posicion minima
                    X[i]=X[minIndex];
                    X[minIndex]=temp;//colocamos el valor reservado
            }

    }
}
