#include <iostream>
using namespace std;
const int FIL=3;
const int COL=4;
int FilaEnSucesion(int** A,int f,int c){
    int total=0;
    bool enSucesion=true;
    for(int i=0;i<f;i++){   //para recorrer las filas
        enSucesion=true;
        for(int j=1;j<c-1;j++){   //para recorrer las columnas
                int dif1=*(*A + c*i + j) - *(*A + c*i + j-1);   //A[i][j]-A[i][j-1]
                int dif2=*(*A + c*i + j+1) - *(*A + c*i + j);
                if(dif1!=dif2){
                    enSucesion=false;
                    break;
                }
        }
        if(enSucesion) total++;
    }
    return total;
}

int main()
{
    int A[FIL][COL]={{5,7,9,11},
                                {4,2,0,-1},
                                {7,6,5,4} };
    int* p=&A[0][0];
    cout <<"# filas en sucesion: "
    <<FilaEnSucesion(&p,FIL,COL)<< endl;
    return 0;
}
