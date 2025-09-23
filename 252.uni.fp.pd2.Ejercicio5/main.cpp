#include <iostream>
using namespace std;
const int MAX=100;

void imprimir(int* p,int n){
    cout<<"p(x)= "<<*p++;
    for(int i=1;i<n;i++){
            cout<<((*p<0)? "-":"+")<<abs(*p)<<"x^"<<i;
            p++;
    }
    cout<<endl;
}

void derivada(int* p,int n,int k){
    int t;
    for(int i=0;i<n;i++){
            t=i+1;
            if(i<n-k){
                    for(int j=2;j<k+1;j++)
                        t=t*(i+j);
                    *p=*(p+k)*t;
            }else
                *p=0;
            p++;
    }
}


int main()
{
    int A[MAX];
    int k,n;
    cout << "Ingrese el grado del polinomio:";
    cin>>n;
    cout << "Ingrese los coeficientes del polinomio:"<<endl;
    for(int i=0;i<n+1;i++){
        cout<<"A["<<i<<"]= ";
        cin>>A[i];
    }
    imprimir(A,n+1);
    cout<<"ingrese el orden k: ";
    cin>>k;
    derivada(A,n+1,k);
    cout<<"La derivada de orden "<<k<< " es: ";
    imprimir(A,n-k+1);
    return 0;
}
