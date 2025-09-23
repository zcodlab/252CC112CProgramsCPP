// Fig. 8.4: fig08_04.cpp
// Pointer operators & and *.
#include <iostream>
using namespace std;
int main() {
  int a{7}; // a=7 inicializa a con 7
  int* aPtr = &a; // inicializa aPtr con la direccion de la variable entera a
  int A[5]={10,20,30,40,50};
 cout << "La direccion de a es " <<&a
    <<endl<< "El valor de aPtr es " <<aPtr ;
 cout<<endl<<"El valor de a es " << a;
 cout<<endl<<"El valor de *aPtr es " <<*aPtr<< endl;
 cout<<endl<<"El valor de *aPtr +1 es " <<*aPtr + 1<< endl;
 cout<<endl<<"El valor de *(aPtr +1) es " <<*(aPtr + 1)<< endl;
 cout<<endl<<"El valor de &aPtr es " <<&aPtr<< endl;
 cout<<endl<<"El valor de &aPtr + 1 es " <<&aPtr+1<< endl;
 cout <<endl<<endl<<"El valor de &*aPtr es " << &*aPtr
    <<endl<<"El valor de *&aPtr es " <<*&aPtr<< endl;

    cout<<"Los elementos del array son:"<<endl;
    for(int i=0; i<5;i++)
        cout<<"A["<<i<<"]="<<A[i]<<" ";
    cout<<endl;
    cout<<"La direccion del arreglo *A es:"<<*A<<endl;
    cout<<"La direccion del arreglo &A es:"<<&A<<endl;
    cout<<"La direccion del arreglo *A+1 es:"<<*A+1<<endl;
    cout<<"La direccion del arreglo *(A+1) es:"<<*(A+1)<<endl;
}
