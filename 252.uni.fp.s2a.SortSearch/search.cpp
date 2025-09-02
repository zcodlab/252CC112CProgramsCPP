#include "search.h"
using namespace std;

const int NO_ENCONTRADO=-1;
//Implemencion de la funcion de busqueda lineal
int searchLineal(int X[], int n, int valor){
    int loc=0;
    while(loc<n && X[loc]!=valor){
            loc++;
    }
    if(loc==n)
        loc=NO_ENCONTRADO;

    return loc; //retorna la ubicacion del valor encontrado o retorna -1 si no lo encontro

}
//Implemencion de la funcion de busqueda binaria
int searchBinaria(int X[], int n, int valor){
    int izq=0;      //limite inferior
    int der=n-1;  //limite superior
    while(izq<=der){
            int medio=(izq+der)/2;
            if(X[medio]==valor)
                return medio;
            if(X[medio]<valor)
                izq=medio+1;
            else
                der=medio-1;
    }
    return NO_ENCONTRADO;
}

