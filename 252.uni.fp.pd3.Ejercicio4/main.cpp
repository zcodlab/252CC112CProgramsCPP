#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

const int FIL=3;
const int COL_NOM=50;
const int COL_DIR=40;
const int COL_CEL=10;
const int COL_RES=200;
const int N_TERMINOS=5;
const int N_BYTES_LIMPIEZA=20;


int longitudEntrada(char entrada[]){
    char* token;
    token = strtok(entrada,",");
    int i=0;
    while(token){//token no sea puntero nulo (nullptr)
        i++;
        //cout<<i<<", "<<"token: "<<token<<endl;
        token = strtok(NULL,",");
    }
    return i;
}
void guardarData(char entrada[],char nombre[],char direccion[],char celular[],
                                int &edad,float &talla ){
    char* token;
    //guardar nombre
    token=strtok(entrada,",");
    strcpy(nombre,token);
    //guardar direccion
    token=strtok(NULL,",");//recuperar desde el siguiente caracter desde donde te quedaste hasta ubicar la siguiente coma
    strcpy(direccion,token);
    //guardar celular
    token=strtok(NULL,",");
    strcpy(celular,token);
    //guardar edad
    token=strtok(NULL,",");
    edad=stoi(token);    //transformando el string token a int
    //guardar talla
    token=strtok(NULL,",");
    talla=stof(token);  //transformando el string token a float
}

int main()
{
    char nombre[FIL][COL_NOM],direccion[FIL][COL_DIR],celular[FIL][COL_CEL],
            entrada[COL_RES], auxiliar[COL_RES];
    int edad[FIL];
    float talla[FIL];
    char* token;
    int in=0;
    cout<<"Directorio "<<endl;
    cin.ignore(N_BYTES_LIMPIEZA,'\n');    //para limpiar el buffer
    for(int k=0;k<FIL;k++){
            cout<<"Ingrese la entrada "<<k+1<<": "<<endl;
            cin.getline(entrada,sizeof(entrada),'\n');
            strcpy(auxiliar,entrada);//copiamos el array entrada en el array auxiliar
            //determinando si la cadena cuenta con el formato establecido
            if(longitudEntrada(auxiliar)==N_TERMINOS){
                    //registrar data en directorio
                    //cout<<"Directorio"<<endl;
                    guardarData(entrada,nombre[in],direccion[in],celular[in],
                                edad[in],talla[in] );
                    in++;
            }
            strcpy(entrada,"");
            strcpy(auxiliar,"");
    }
    //visualizar el directorio
    cout<<"Los datos guardados en el Directorio son:"<<endl;
        cout<<left<<setw(20)<<"Nombre"
                <<left<<setw(40)<<"Direccion"
                <<left<<setw(15)<<"Celular"
                <<left<<setw(10)<<"Edad"
                <<left<<setw(10)<<"Talla"<<endl;
    for(int k=0;k<FIL;k++)
        cout<<left<<setw(20)<<nombre[k]
               <<left<<setw(40)<<direccion[k]
               <<left<<setw(15)<<celular[k]
               <<left<<setw(10)<<edad[k]
               <<left<<setw(10)<<talla[k]<<endl;

    return 0;
}
