#include <iostream>
#include <iomanip>
using namespace std;
const int n=7;  //tamaño de la matriz

int calcula_elemento(int A[n][n],int fil,int col){
    //verificamos que los indices sean validos
    if(col<0 || fil<0)
        return 0;
    //caso base
    if(fil==0 && col==0)
        return 1;
    if(A[fil][col]!=0)  //si ya ha sido calculado, devolver el valor
        return A[fil][col];
    //si el valor no ha sido calculado, calcularlo recursivamente
    A[fil][col]=calcula_elemento(A,fil-1,col-1) + calcula_elemento(A,fil-1,col);
    return A[fil][col];
}

void forma_matriz(int A[n][n],int fil,int col){
    if(fil<0) return;//caso base
    if(col>=0){//llenar la fila actual
            A[fil][col]=calcula_elemento(A,fil,col);
            forma_matriz(A,fil,col-1);  //llamada recursiva para la columna anterior
    } else
            forma_matriz(A,fil-1,col-1); //llamada recursiva para la fila y columna anterior
}

void imprimir_matriz(int A[n][n],int fil,int col){
     //imprimir la matriz
    for(int fil=0;fil<n;fil++){
        for(int col=0;col<n;col++)
            cout<<setw(4)<<A[fil][col];
        cout<<endl;
    }
}

int main()
{
    int A[n][n]={0};    //Inicializar la matriz con ceros
    forma_matriz(A,n-1,n-1);//llamamos a la funcion para generar la matriz
    imprimir_matriz(A,n,n);
    return 0;
}
