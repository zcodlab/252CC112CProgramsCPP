#include <iostream>
#include "sort.h"
using namespace std;
const int MAX=100;

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
//Funcion para implementar el algoritmo quickSort
void quickSort(int X[],int low, int high){
    if(low<high){
            int pivotIdx=particionar(X,low,high);
            //recursivamente ordenar las 2 sublistas
            quickSort(X,low,pivotIdx-1);//invoca recursivamente la 1 sublista
            quickSort(X,pivotIdx+1,high);//invoca recursivamente la 2 sublista
    }
}

int particionar(int X[],int low, int high){
    int p=X[low];       //p es el pivote, y se considera el primer elemento de la lista
    int m=low;          //el indice limite entre las sublistas a generar, el indice donde se divide la lista principal para generar las 2 sublistas
    for(int k=low+1;k<=high;k++){
            if(X[k]<p){
                    m++;
                    if(X[k]!=X[m])
                        swap(X[k],X[m]);    //se intercambian los elementos de las posiciones k y m
            }
    }
    swap(X[low], X[m]);     //colocamos el pivote en el indice que divide las 2 sublistas
    return m;
}
//Funcion principal MergeSort
void mergeSort(int X[],int left, int right){
    if(left<right){
            int mid=(left + right)/2;   //calculando el indice medio
            //ordenar la primera lista generada
            mergeSort(X,left,mid);
            //ordenar la segunda lista generada
            mergeSort(X,mid+1,right);
            //Etapa de fusion de las listas
            merge(X,left,mid,right);
    }
}
void merge(int X[],int left, int mid,int right){
    int n1=mid-left+1;      //n1 es el tamaño de la primera lista
    int n2=right-mid;       //n2 es el tamaño de la segunda lista
    //Arreglos temporales
    int L[MAX],R[MAX];
    //copiar la data a los arreglos temporales
    for(int i=0;i<n1;i++)
        L[i]=X[left + i];
    for(int j=0;j<n2;j++)
        R[j]=X[mid+1+j];
    //combinar las sublistas
    int i=0,j=0,k=left;
    while(i<n1 && j<n2){
        if(L[i]<R[j])
            X[k++]=L[i++];    //actualizamos la lista origen con el valor mas pequeño
        else
            X[k++]=R[j++];
    }
    //copiar elementos restantes de L(si hubiera)
    while(i<n1)
        X[k++]=L[i++];
    //copiar elementos restantes de R(si hubiera)
    while(j<n2)
        X[k++]=R[j++];
}

