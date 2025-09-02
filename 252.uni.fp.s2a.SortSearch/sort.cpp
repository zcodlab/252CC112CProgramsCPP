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

//Funcion que implementa el algoritmo bubbleSort
void bubbleSort(int X[], int n){
    for(int i=0; i<n-1;i++){
            for(int j=0; j<(n-1)-i;j++){
                    if(X[j]>X[j+1]){
                            //intercambio
                            int temp=X[j];
                            X[j]=X[j+1];
                            X[j+1]=temp;
                    }
            }
    }
}

//Funcion que implementa el algoritmo insertionSort
void insertionSort(int X[], int n){
    int aux,k;
    bool sw=false;
    for(int i=1; i<n;i++){
        aux=X[i];
        k=i-1;
        sw=false;
        while(!sw && k>=0){
                if(aux<X[k]){
                        X[k+1]=X[k];
                        k--;
                }else
                    sw=true;
        }
        X[k+1]=aux;
    }//end for
}

//Funcion que implementa el algoritmo insertionBinarySort
void insertionBinarySort(int X[], int n){
        int aux,p,u,c;
        for(int i=1; i<n;i++){
                aux=X[i];
                p=0;    //primero
                u=i-1;  //ultimo
                while(p<=u){
                        //calculando la posicion central
                        c=(p+u)/2;
                        //comparar el elemento con el elemento de la posicion central
                        if(aux<X[c])
                            //actualizacion la posicion ultimo
                            //buscar en el segmento izquierdo de la coleccion
                            u=c-1;
                        else    //buscar en el segmento derecho de la coleccion
                            p=c+1;
                }//end while
                for(int k=i-1; k>=p;k--)
                    X[k+1]=X[k];
                X[p]=aux;
        }//end for externo
}
