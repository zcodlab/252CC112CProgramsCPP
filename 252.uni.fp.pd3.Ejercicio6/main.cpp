#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
const int MAX=20;

int EsNombreValido(char* p){
    int len=strlen(p);  //determina la longitud de la cadena
    if(len==0)
        return 1;   //Cadena vacia es invalida, error en posicion1
    //Regla: Debe iniciar con letra o guion bajo
    if(!isalpha(p[0]) && p[0]!='_')
        return 1;   //No cumple la regla de inicio de variable, error en posicion1
    //analizando el cumplimiento de los requisitos en el cuerpo del nombre de la variable
    for(int i=0;i<len;i++){
        char c=p[i];
        //Regla a: solo letras, digitos o guion bajo
        if(!isalnum(c) && c!='_')
            return i+1;
        //Regla c: no puede contener espacios
        if(isspace(c))
            return i+1;
        //Regla d: no puede contener __ dos subrayas
        if(c=='_' && p[i+1]=='_')
            return i+1;
    }
    return 0; //tod esta correcto
}

int main()
{
    char nombre[MAX];
    cout << "Ingrese un nombre de variable: " ;
    cin.getline(nombre,MAX);
    int resultado=EsNombreValido(nombre);
    if (resultado==0)
        cout<<"El nombre de la variable es valido"<<endl;
    else
        cout<<"Error en la posicion "<<resultado<<" : "<<nombre[resultado-1]<<endl;
    return 0;
}
