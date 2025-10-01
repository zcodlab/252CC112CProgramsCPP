#include <iostream>
#include <cstring>
using namespace std;

void eliminar(char* frase,int &len){
    char* src=frase;
    char* dst=frase;
    while(*src){    //mientras sea puntero valido
            if((*src>='A' && *src<='Z') || (*src>='a' && *src<='z')){
                *dst=*src;
                 dst++;
            }
            src++;
    }
    *dst='\0';  //se consigne el caracter nulo, en señal de fin de la cadena
    len=dst-frase;
    /*
    frase-> tiene la direccion base
    dst->frase+5
    dst-frase=frase+5 - frase=5
    */
}
void invertir(char* frase, int len){
    char* inicio=frase;
    char* fin=frase+len-1;
    while(inicio<fin){
            char temp=*inicio;
            *inicio=*fin;
            *fin=temp;
            inicio++;
            fin--;
    }
}
void dividir(char* frase,int len){
    int n=1, i=0;
    while(i<len){
            for(int j=0;j<n && i+j<len;j++)
                cout<<*(frase+i+j);
            cout<<endl;
            i+=n;
            n++;
    }
}


int main()
{
    char oracion[]="Hola, mundo feliz!";
    int len=strlen(oracion);
    eliminar(oracion,len);  //eliminar espacios y signos de puntuacion
    invertir(oracion,len);
    dividir(oracion,len);   //dividor en tokens de longitud secuencial, iniciando en 1
    return 0;
}
