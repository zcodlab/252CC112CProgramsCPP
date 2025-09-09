#include <iostream>
using namespace std;
const int m=50;     //considerando que son 10 alumnos, con 5 notas cada alumno
const int n=10;     //numero de alumnos
const int nn=5;     //numero de notas por cada alumno
const int maxNota=20;

int notasGeneradas[m];      //notas generadas aleatoriamente
float pAlumnos[n];              //promedios de alumnos
float ranking[n];                   //promedios ordenados
//prototipo de funcion
void quickSort(float X[],int low, int high);
int particionar(float X[],int low, int high);

int main()
{
    int tmp,k;
    float promedio;
    //generando las notas aleatorias
    for(int i=0; i<m;i++)
            notasGeneradas[i]=rand()%(maxNota+1);
    //calcular los promedios de n alumnos
    cout << "Promedios de Alumnos" << endl;
    k=0;
    for(int i=0; i<n;i++){
         promedio=0.0;
         for(int j=0; j<nn;j++)
                promedio=promedio + notasGeneradas[k++];
         promedio=promedio/nn;
         pAlumnos[i]=promedio;
         ranking[i]     =promedio;
         cout<<"pAlumnos["<<i<<"]="<<pAlumnos[i]<<endl;
    }
    //ordenamiento de los promedios para determinar el ranking
    quickSort(ranking,0,n-1);
    cout<<endl<<"Mejores Notas: "<<endl;
    int puesto=0;
    for(int i=n-1;i>=(n-3);i--)
        cout<<"Puesto "<<puesto++<<" : "<<ranking[i]<<endl;
    //Con fines de contrastacion
    cout<<endl<<"Notas Generadas"<<endl;
     for(int i=0; i<m;i++)
            cout<<notasGeneradas[i]<<" ";
    cout<<endl<<"Ranking"<<endl;
    for(int i=0; i<n;i++)
            cout<<ranking[i]<<" ";
    cout<<endl;
    return 0;
}

//Funcion para implementar el algoritmo quickSort
void quickSort(float X[],int low, int high){
    if(low<high){
            int pivotIdx=particionar(X,low,high);
            //recursivamente ordenar las 2 sublistas
            quickSort(X,low,pivotIdx-1);//invoca recursivamente la 1 sublista
            quickSort(X,pivotIdx+1,high);//invoca recursivamente la 2 sublista
    }
}

int particionar(float X[],int low, int high){
    float p=X[low];       //p es el pivote, y se considera el primer elemento de la lista
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
