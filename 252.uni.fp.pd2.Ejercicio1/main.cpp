#include <iostream>
using namespace std;
const int MAX=20; //cantidad maxima por conjunto

bool esta(int valor,int* U,int k){
     for(int i=0;i<k;i++){
            if(valor==*(U+i))
                    return true;
     }
     return false;
}

void agregar_elementos(int* A,int n,int* U,int &k){
    for(int i=0;i<n;i++){
            cout<<"Elemento "<<i<<": ";
            cin>>*(A+i);    //equiv-> A[i]
            if(!esta(*(A+i),U,k)){//si no esta en U entonces los agregamos
                *(U+k)=*(A+i);
                k++;
            }
    }
}
void imprimir(int* A,int n){
    for(int i=0;i<n;i++)
         cout<<*(A+i)<<" ";
    cout<<endl;
}

int main()
{
    int A[MAX];
    int B[MAX];
    int U[2*MAX];
    int i,k=0,n,m;
    cout<<"Cuantos elementos desea ingresar al conjunto A:";
    cin>>n;
    agregar_elementos(A,n,U,k);
    imprimir(A,n);
    cout<<"Cuantos elementos desea ingresar al conjunto B:";
    cin>>m;
    agregar_elementos(B,m,U,k);
    imprimir(B,m);
    cout<<"Visualizando el resultado de la Union, conjunto U:"<<endl;
    imprimir(U,k);
    return 0;
}
