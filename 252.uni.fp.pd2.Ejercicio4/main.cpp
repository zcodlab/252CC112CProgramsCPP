#include <iostream>
using namespace std;

void ordBurbuja(int*A,int n){
    for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                    if(*(A+j)>*(A+j+1)){        //A[j]>A[j+1]
                        //intercambio
                        int temp=*(A+j);    //temp=A[j]
                        *(A+j)=*(A+j+1);    //A[j]=A[j+1]
                        *(A+j+1)=temp;     //A[j+1]=temp
                    }
            }
    }
}
void imprimir(int*A,int n){
    for(int i=0;i<n;i++)
        cout<<*(A+i)<<" ";      //A[i]
    cout<<endl;
}

int main()
{
    int A[]={5,2,9,4,1,8,5,6,3,0,7};
    int n=sizeof(A)/sizeof(int);
    cout<<"Array despues del registro"<<endl;
    imprimir(A,n);
    ordBurbuja(A,n);
    cout<<"Array Ordenado"<<endl;
    imprimir(A,n);
    return 0;
}
