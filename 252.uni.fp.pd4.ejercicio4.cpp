#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
const int MAX=5;  //numero de selecciones
const int PARTIDOS=100;

struct seleccion{
    string nombre;          //nombre de la seleccion
    int pganados;       //puntos ganados
    int pempatados;       //puntos empatados
    int pperdidos;       //puntos perdidos
    int puntajetotal;       //puntaje total obtenido
    double rendimiento;
};


int main()
{
    seleccion tabla[MAX];
    srand(time(NULL));
    int pg,pp,pe,n=MAX;
    int mejorrendimiento=-1,imjr=-1; //para mantener el valor y el indice de la seleccion con mejor rendimiento
    //Generar Tabla
    for(int i=0;i<n;i++){
            tabla[i].nombre="Pais_Seleccion "+ to_string(i); //autogenera los nombres de la seleccion
            pg=rand()%PARTIDOS;
            tabla[i].pganados=pg;
            pe=rand()%(PARTIDOS - pg);
            tabla[i].pempatados=pe;
            pp=PARTIDOS-(pg+pe);    //calcula los pp restando del total de partidos, los pg y pe
            tabla[i].pperdidos=pp;
            tabla[i].puntajetotal=3*pg+1*pe;
            tabla[i].rendimiento=100.0*(double)tabla[i].puntajetotal/(3*PARTIDOS);
            if(tabla[i].rendimiento>mejorrendimiento){
                    mejorrendimiento=tabla[i].rendimiento;
                    imjr=i;
            }
    }
    //imprimir la tabla
    cout<<"Seleccion \t\t"<<"PG \t"<<"PE \t"<<"PP \t"<<"Puntaje Total \t\t"<<"Rendimiento"<<endl;
    for(int i=0;i<n;i++){
        cout<<tabla[i].nombre<<"\t"
        << tabla[i].pganados<<"\t"
        << tabla[i].pempatados<<"\t"
        << tabla[i].pperdidos<<"\t"
        << tabla[i].puntajetotal<<"\t\t"
        //setprecision(3): indica el numero de digitos significativos se muestra
        //showpoint: fuerza la viusalizacion del puntos decimal y ceros finales
        << std::setprecision(3)<<std::showpoint<<tabla[i].rendimiento<<"%"<<endl;
    }
    cout<<"La seleccion con mejor rendimiento es: "<<tabla[imjr].nombre<<endl;
    cout<<"Rendimiento: "<<tabla[imjr].rendimiento<<"%"<<endl;
    return 0;
}
