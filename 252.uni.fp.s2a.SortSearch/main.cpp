#include <iostream>
#include "sort.h"
using namespace std;
const int MAX=100; //tamaño maximo permitido para el arreglo

void copiarArray(int X[],int C[],int n){
    for(int i=0; i<n;i++)
        C[i]=X[i];
}

void cargarDatos(int X[],int C[],int n){
    cout<<"Carga personalizada de Datos en el array"<<endl;
    cout<<"Introduce "<<n<<" numeros para el array"<<endl;
     for(int i=0; i<n;i++)
        cin>>X[i];
     copiarArray(X,C,n);    //para mantener una copia de los valores originales
}

void visualizar(int X[],int n){
     cout<<"Visualizando el array"<<endl;
     for(int i=0; i<n;i++)
         cout<<X[i]<<" ";
     cout<<endl;
}

void callSelectionSort(int X[],int C[],int n){
    copiarArray(X,C,n);
    visualizar(X,n);
    selectionSort(X,n);
    visualizar(X,n);
}

void menu(int X[],int C[],int n){
    int opcion=0;
    do{
            cout<<"Algoritmos de Busqueda y Ordenamiento"<<endl;
            cout<<"1.- Cargar datos en el array"<<endl;
            cout<<"2.- Visualizar el array"<<endl;
            cout<<"3.- Ordenamiento Seleccion"<<endl;
            cout<<"4.- Salir"<<endl;
            //validar ingreso
            cout<<"Elija una opcion: ";
            while(!(cin>>opcion)){
                    cout<<"Entrada invalida, Ingrese un numero enetero: ";
                    cin.clear();        //limpia el estado del error
                    cin.ignore(10000,'\n')  //descartar la entrada incorrecta
            }
            switch(opcion){
                case 1: cargarDatos(X,C,n); break;
                case 2: visualizar(C,n); break;
                case 3: callSelectionSort(X,C,n); break;
                case 4: cout<<"Saliendo del programa..."<<endl; break;
                default: cout<<"Opcion invakida..., elija una opcion correcta"<<endl; break;
            }
    }while(opcion!=4);
}

int main()
{
    int X[MAX], C[MAX];     //arrays estaticos, C se utilizara como copia de X con la finalidad de matener los datos originales y poder someter a prueba los diferentes algoritmos de ordenamiento
    int n=0;
    cout << "Ingrese el tamaño del array (max: "<<MAX<<" ): ";
    cin>>n;
    //validar el valor ingresado
    if(n>MAX || n<=0){
            cout<<"Tamaño ingresado es invalido."<<endl;
            return 0;
    }
    //Invocar al menu de operaciones
    menu(X,C,n);
    return 0;
}
