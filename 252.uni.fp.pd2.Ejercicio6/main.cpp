#include <iostream>
using namespace std;
const int FIL=9;
const int COL=9;

void mostrar(int** A,int n,int m){
    for(int i=0; i<n;i++){
            for(int j=0;j<m;j++)
                cout<< *(*A+i*m+j)<<" ";
            cout<<endl;
    }
}

void generar(int** A,int n,int m){
    int C[m];
    for(int i=0; i<n;i++){
            for(int j=0;j<m;j++)
                C[j]=1+j;
            for(int j=0;j<m;j++){
                int pos=rand()%(m-j);
                *(*A+i*m+j)=C[pos];
                swap(C[pos], C[m-j-1]);//el ultimo elemento de C reemplaza al elemento de la posicion pos previamente determinada
            }
    }
}
void actualizar(int** A,int n,int m,int f,int c){
    int valor=*(*A+f*m+c);
    int fila_actual[m];
    int* p=fila_actual;
     for(int i=0; i<n;i++){
        int col0;
        for(int j=0;j<m;j++){
               *(p+j)=*(*A+i*m+j);
                if(*(p+j)==valor) col0=j;
        }
        for(int j=0;j<m;j++){
                int col_origen= j - c + col0;
                if(col_origen<0) col_origen+=m;
                if(col_origen>=m)
                    col_origen=col_origen-m;
                *(*A+i*m+j) = *(p+col_origen);
        }
     }
}

int main()
{
    int M[FIL][COL];
    int FIL_ACTUAL,COL_ACTUAL;
    int* F=&M[0][0];
    int** A=&F;
    generar(A,FIL,COL);
    mostrar(A,FIL,COL);
    cout<<"Fila inicial (1-9): "; cin>>FIL_ACTUAL;
    FIL_ACTUAL--;
    cout<<"Columna inicial (1-9): "; cin>>COL_ACTUAL;
    COL_ACTUAL--;
    actualizar(A,FIL,COL,FIL_ACTUAL,COL_ACTUAL);
    mostrar(A,FIL,COL);
    return 0;
}
