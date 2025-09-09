#include <iostream>
#include <ctime>
using namespace std;
const int n=100;        //numero de elementos a generar aleatoriamente
const int r=10;         //tamaño de la matriz
const int ri=5;         //rango de la matriz resultante
const float porc=0.25;
int X[n];           //arreglo que contendra los numeros aleatorios
int XB[r][r];       //matriz resultante
//prototipos de las funciones
int generador(void);
void quickSort(int X[],int low, int high);
int particionar(int X[],int low, int high);
void imprimir_array(int X[],int n);

int main()
{
    srand(time(NULL));
    for(int i=0; i<n; i++)
        X[i]=generador();
    //ordenar el array
    quickSort(X,0,n-1);
    imprimir_array(X,n);
    //rellenar el 4 cuadrante de la matriz
    int k=n - (porc*n);
    for(int i=ri; i<r; i++){
            for(int j=ri;j<r;j++){
                    XB[i][j]=X[k];
                    k++;
            }
    }
    //imprimir matriz
    for(int i=0; i<r; i++){
            for(int j=0; j<r; j++)
                cout<<"\t"<<XB[i][j];
            cout<<endl;
    }
    return 0;
}

void imprimir_array(int X[],int n){
    //imprimir el array
    for(int i=0; i<n; i++)
        cout<<X[i]<<" ";
    cout <<endl;
}
//implementando la funcion generador de aleatorios
int generador(){
    int valor=n + rand()%(n+1);
    return valor;
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
