#include <iostream>
#include <ctime>  // Incluir esta cabecera para usar time(NULL) y srand()
using namespace std;
const int rango=5;
const int vmax=99;
int main()
{
    int matrix[rango][rango];
    int i,j,val,min=vmax,max=0;
    int mini,minj,maxi,maxj;
    srand(time(NULL));
    for(i=0;i<rango;i++){
            for(j=0;j<rango;j++){
                    //garantiza que el valor sea un entero entre 0 y vmax-1
                    val=rand()%vmax;
                    if(val<min){
                            min=val;
                            mini=i;
                            minj=j;
                    }
                    if(val>max){
                            max=val;
                            maxi=i;
                            maxj=j;
                    }
                    matrix[i][j]=val;
                    cout<<"\t"<<val<<"  ";
            }
            cout<<endl;
    }
    cout << "El Maximo valor de la Matriz es: Matrix[" <<maxi<<"]["<<maxj<<"]="<<max<< endl;
    cout << "El Minimo valor de la Matriz es: Matrix[" <<mini<<"]["<<minj<<"]="<<min<< endl;

    return 0;
}
