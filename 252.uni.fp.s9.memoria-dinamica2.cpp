#include <iostream>
using namespace std;

//definicion de prototipos
int* crearArray(int n) ;
void leerArray(int* base,int n);
void mostrarArray(const int* base,int n);
void liberarArray(int* base);

int main()
{
    int n;
    cout << "Ingrese el tamaño del array dinamico" << endl;
    cin>>n;
    int* edades=crearArray(n);
    leerArray(edades,n);
    mostrarArray(edades,n);
    liberarArray(edades);
    return 0;
}
//crea un array dinamico y devuelve un puntero base
int* crearArray(int n) {
    int* arr=new int[n];
    return arr;
}
void leerArray(int* base,int n){
    cout<<"Ingrese las edades:"<<endl;
    for(int i=0; i<n; i++){
        cout<<"Ingrese la edad["<<i<<"]=";
        cin>>*(base +i);
    }
}

void mostrarArray(const int* base,int n){
    cout<<"Visualizando las edades:"<<endl;
    for(int i=0; i<n; i++)
        cout<<*(base +i)<<" ";
    cout<<endl;
}

void liberarArray(int* base){
    delete[] base;
    base=nullptr;
    cout<<"Memoria liberada correctamente"<<endl;
}
