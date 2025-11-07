#include <iostream>
#include <ctime>
using namespace std;
const int NB=2;           //tamanio de la matriz B
const int NRAND=5;  //limite superior de los valores aleatorios a generar 1:5

struct MatrizEstructura{
    int B[NB][NB];
    int suma;
};
void imprimirMatriz(MatrizEstructura** matrizA,int fil,int col){
     for(int i=0; i<fil;i++){
            for(int j=0; j<col;j++){
                    cout<<"MatrizA["<<i<<"]["<<j<<"] (suma= "<<matrizA[i][j].suma<<").";
                    cout<<"Direccion de Memoria de B: "<<&matrizA[i][j].B<<endl;
                    for(int filB=0; filB<NB;filB++){
                            for(int colB=0; colB<NB;colB++)
                                cout<<"B["<<filB<<"]["<<colB<<"]= "<<matrizA[i][j].B[filB][colB]<<" ";
                            cout<<endl;
                    }
                    cout<<endl;
            }
     }
}
void encontrarMayorSuma(MatrizEstructura** matrizA,int fil,int col){
    //buscando la mayor suma
    int mayorSuma=matrizA[0][0].suma;
    for(int i=0; i<fil;i++){
            for(int j=0; j<col;j++){
                    if(matrizA[i][j].suma>mayorSuma)
                            mayorSuma=matrizA[i][j].suma;
            }
    }
    cout<<"La mayor suma de elementos de B es: "<<mayorSuma<<" y se encuentra en: "<<endl;
    for(int i=0; i<fil;i++){
            for(int j=0; j<col;j++){
                if(matrizA[i][j].suma==mayorSuma){
                        cout<<"matrizA["<<i<<"]["<<j<<"]."<<endl;
                        cout<<"Valor de suma: "<<matrizA[i][j].suma<<endl;
                        cout<<"Direccion de memoria de B: "<<&matrizA[i][j].B<<endl;
                }
            }
     }
}

int main()
{
    srand(time(NULL));
    int fil,col;
    cout<<"Ingrese el numero de filas de la matriz A: "; cin>>fil;
    cout<<"Ingrese el numero de columnas de la matriz A: "; cin>>col;
    MatrizEstructura** matrizA=new MatrizEstructura*[fil];
    for(int i=0; i<fil;i++){
            matrizA[i]=new MatrizEstructura[col];
            for(int j=0; j<col;j++){
                //consignar datos en la matriz B mediante valores aleatorios
                for(int filB=0; filB<NB;filB++){
                    for(int colB=0; colB<NB;colB++)
                        matrizA[i][j].B[filB][colB]=1 + rand()%NRAND;
                }
                matrizA[i][j].suma=
                                                matrizA[i][j].B[0][0]+
                                                matrizA[i][j].B[0][1]+
                                                matrizA[i][j].B[1][0]+
                                                matrizA[i][j].B[1][1];
            }
    }
    cout<<"Matriz A: "<<endl;
    imprimirMatriz(matrizA,fil,col);
    encontrarMayorSuma(matrizA,fil,col);
    //liberar memoria
    for(int i=0; i<fil;i++)
        delete[] matrizA[i]; //liberar memoria por cada fila que se instancio con el operador new
    delete[] matrizA;       //liberar memoria de matrizA
    return 0;
}
