#include <iostream>
using namespace std;

void liberarMatriz(string** matriz,int filas){
    for(int i=0;i<filas;i++)
        delete[] matriz[i];     //liberar la memoria de cada fila de la matriz
    delete[] matriz;    //libera la memoria que estuvo utilizando el arreglo de punteros
    matriz=nullptr;
}


int main()
{
    string** base=nullptr;
    string codigo;
    int n=0,nota,maxNota=-1;
    cout<<"Ingreso de Notas UNI; "<<endl;
    while(true){
            cout<<"Ingrese codigo: ";
            cin>>codigo;
            if(codigo=="fin") break;    //conclusion del ingreso de notas
            cout<<"Ingrese nota: ";
            cin>>nota;
            //Actualizar la maxima nota
            if(nota>maxNota) maxNota=nota;
            //crear lista de punteros con tamaño incrementado
            string** nuevaBase=new string*[n+1];
            //copiar los punteros existentes
            for(int i=0;i<n;i++)
                nuevaBase[i]=base[i];   //matriz antigua en matriz nueva
            //crear nueva fila para el nuevo alumno
            nuevaBase[n]=new string[2];
            nuevaBase[n][0]=codigo;
            nuevaBase[n][1]=to_string(nota);
            //actualizar el puntero y el contador
            base=nuevaBase;
            n++;
    }
    //Mostrar los alumnos con la maxima nota
    cout<<"Alumnos con la maxima nota: "<<maxNota<<endl;
    for(int i=0;i<n;i++)
        if(stoi(base[i][1])==maxNota)
            cout<<"Codigo: "<<base[i][0]<<"Nota: "<<base[i][1]<<endl;

    //liberar memoria
    liberarMatriz(base,n);
    return 0;
}
