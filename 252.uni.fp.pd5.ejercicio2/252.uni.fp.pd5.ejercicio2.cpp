#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool abrirArchivo(ifstream& ar,const string& nombreArchivo){
    ar.open(nombreArchivo);
    return ar.good();
}
int contarFilas(ifstream& ar){
    string linea;
    int n=0;
    while(getline(ar,linea))//sale del bucle cuando detecta un EOF (End Of File= Fin del archivo)
        n++;
    ar.clear();
    ar.seekg(0); //Mueve el puntero del archivo a la posicion inicial (posicion 0)
    return n;
}
void leerRegistro(ifstream& ar,int& num,string& apellidos,
                  string& nombre,float& nota1,float& nota2){
    string cadena;
    getline(ar,cadena,'.');//numero
    num=stoi(cadena);

    getline(ar,cadena,',');//apellidos
    apellidos=cadena;

    getline(ar,cadena,'-');//nombre
    nombre=cadena;

    getline(ar,cadena,'-');//nota1
    nota1=stof(cadena);

    getline(ar,cadena); //nota2
    nota2=stof(cadena);
}

void imprimirRegistro(int num,string& apellidos,
                  string& nombre,float nota1,float nota2,float promedio){
        cout<<num<<"\t"
        <<apellidos<<"\t"
        <<nombre<<"\t"
        <<nota1<<"\t"
        <<nota2<<"\t"
        <<promedio<<endl;
}

int main()
{
    string nombreArchivo="baseUNI.txt";
    ifstream ar;
    //1.-Validar el archivo
    if(!abrirArchivo(ar,nombreArchivo)){
        cout<<"Error al abrir el archivo"<<endl;
        return 1;
    }
    //2.-Contar filas del archivo
    int n=contarFilas(ar);
    if(n==0){
            cout<<"El archivo esta vacio"<<endl;
            return 1;
    }
    //consignando el encabezado de la salida
    cout<<"Num\tApellidos\tNombre\tNota1\tNota2\tPromedio"<<endl;
    //declarando variables
    int num,indMax;
    string apellidos,nombre, apeMax="",nomMax="";
    float nota1,nota2,promedio,promMax=0;
    //Leer contenido del archivo
    for(int i=0;i<n;i++){
            leerRegistro(ar,num,apellidos,nombre,nota1,nota2);
            promedio=(nota1+nota2)/2.0f;

            if(promedio>promMax){
                promMax=promedio;
                indMax=num-1;
                apeMax=apellidos;
                nomMax=nombre;
            }
            imprimirRegistro(num,apellidos,nombre,nota1,nota2,promedio);
    }
    ar.close();//cierre del archivo
    cout<<endl;
    cout<<"El promedio maximo: "<<promMax<<endl;
    cout<<"Alumno: "<<nomMax<<" "<<apeMax<<endl;
    return 0;
}
