#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const int N=100;

//Abre un archivo y verifica si se abrio correctamente
bool abrirArchivo(ifstream &file,const char* nombre ){
    file.open(nombre, ios:: in);    //abrir el archivo para lectura
    return file.good(); //retorna True si el el flujo del archivo es correcto, caso contrario retorna False
}

//Encuentra la primera columna diferente entre dos lineas
int encontrarColumnaDiferente(const char* fila1,const char* fila2){
    int sz1=strlen(fila1);
    int sz2=strlen(fila2);
    int column=-1;
    //comparar caracter por caracter
    for(int i=0; i<sz1 && i< sz2 && column==-1;i++){
            if(fila1[i]!=fila2[i])
                column=i;
    }
    //si no se encontro diferencia en las posiciones comparadas
    if(column==-1)
        //la diferencia estaria iniciando donde termina la linea mas corta
        column=(sz1 < sz2)  ? sz1 :  sz2;

    return column;
}


void compararArchivos(ifstream &a1, ifstream &a2){
    char linea1[N],linea2[N];
    int linea=0;
    while(a1.getline(linea1,N)){
            bool linea2Existe=false;
            if(a2.getline(linea2,N)){
                linea2Existe=true;
                if(strcmp(linea1,linea2)!=0){
                        int column=encontrarColumnaDiferente(linea1,linea2);
                        cout<<"Diferencia en la linea  y columna: ("<<linea<<","<<column<<")"<<endl;
                }
            }else //Se termino de leer el archivo 2 antes que el archivo 1
                cout<<"Diferencia en la linea  y columna: ("<<linea<<","<<0<<")"<<endl;
            linea++;
    }
}

int main()
{
    ifstream i1,i2;
    if(!abrirArchivo(i1,"input1.txt") || !abrirArchivo(i2,"input2.txt") ){
            cout<<"Error al abrir los archivos"<<endl;
            return 1;
    }
    compararArchivos(i1,i2);
    i1.close();
    i2.close();
    return 0;
}
