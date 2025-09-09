#include <iostream>
#include "sort.h"
#include "search.h"
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
    copiarArray(C,X,n); //copiar la data origen en X, en X se tendra el resultado del ordenamiento
    visualizar(X,n);
    selectionSort(X,n);
    visualizar(X,n);
}
void callBubbleSort(int X[],int C[],int n){
    copiarArray(C,X,n);
    visualizar(X,n);
    bubbleSort(X,n);
    visualizar(X,n);
}

void callInsertionSort(int X[],int C[],int n){
    copiarArray(C,X,n);
    visualizar(X,n);
    insertionSort(X,n);
    visualizar(X,n);
}

void callInsertionBinarySort(int X[],int C[],int n){
    copiarArray(C,X,n);
    visualizar(X,n);
    insertionBinarySort(X,n);
    visualizar(X,n);
}

//quickSort
void callQuickSort(int X[],int C[],int n){
    copiarArray(C,X,n);
    visualizar(X,n);        //ver la data antes del ordenamiento
    quickSort(X,0,n-1);
    visualizar(X,n);        //ver la data despues del ordenamiento
}


void callSearchLineal(int X[],int n){
    int valor;
    cout<<"Ingrese el valor a buscar: ";
    cin>>valor;
    visualizar(X,n);
    int pos=searchLineal(X,n,valor);
    if(pos!=-1)
        cout<<"El valor "<<valor<<" se encuentra en la posicion: "<<pos<<endl;
    else
        cout<<"El valor "<<valor<<" NO se encuentro en el arreglo."<<endl;
}
void callSearchBinaria(int X[],int C[],int n){
    int valor;
    cout<<"Ingrese el valor a buscar: ";
    cin>>valor;
    visualizar(X,n);
    copiarArray(C,X,n);
    //llamar a un metodo de ordenamiento
    bubbleSort(X,n);
    visualizar(X,n);
    int pos=searchBinaria(X,n,valor);
    if(pos!=-1)
        cout<<"El valor "<<valor<<" se encuentra en la posicion: "<<pos<<endl;
    else
        cout<<"El valor "<<valor<<" NO se encuentro en el arreglo."<<endl;
}

void menu(int X[],int C[],int n){
    int opcion=0;
    do{
            cout<<"Algoritmos de Busqueda y Ordenamiento"<<endl;
            cout<<"1.- Cargar datos en el array"<<endl;
            cout<<"2.- Visualizar el array"<<endl;
            cout<<"3.- Ordenamiento Seleccion"<<endl;
            cout<<"4.- Ordenamiento Burbuja"<<endl;
            cout<<"5.- Ordenamiento Insercion"<<endl;
            cout<<"6.- Ordenamiento Insercion Binaria"<<endl;
            cout<<"7.- Ordenamiento QuickSort"<<endl;
            cout<<"8.- Busqueda Lineal"<<endl;
            cout<<"9.- Busqueda Binaria"<<endl;
            cout<<"10.- Salir"<<endl;
            //validar ingreso
            cout<<"Elija una opcion: ";
            while(!(cin>>opcion)){
                    cout<<"Entrada invalida, Ingrese un numero enetero: ";
                    cin.clear();        //limpia el estado del error
                    cin.ignore(10000,'\n');  //descartar la entrada incorrecta
            }
            switch(opcion){
                case 1: cargarDatos(X,C,n); break;
                case 2: visualizar(C,n); break;
                case 3: callSelectionSort(X,C,n); break;
                case 4: callBubbleSort(X,C,n); break;
                case 5: callInsertionSort(X,C,n); break;
                case 6: callInsertionBinarySort(X,C,n); break;
                case 7: callQuickSort(X,C,n); break;
                case 8: callSearchLineal(X,n); break;
                case 9: callSearchBinaria(X,C,n); break;
                case 10: cout<<"Saliendo del programa..."<<endl; break;
                default: cout<<"Opcion invalida..., elija una opcion correcta"<<endl; break;
            }
    }while(opcion!=10);
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
