#include <iostream>
#include <cmath>
using namespace std;

struct Punto{
    double x;
    double y;
    double z;
};

void registro_puntos(Punto &p,int numero){
    cout<<"Ingrese las coordenadas del punto "<<numero<<":"<<endl;
    cout<<"X: ";cin>> p.x;
    cout<<"Y: ";cin>> p.y;
    cout<<"Z: ";cin>> p.z;
}
double calculo_distancia(const Punto &p1,const Punto &p2){
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}
void imprimir_distancia(double d){
    cout<< "La distancia entre los dos puntos es: "<<d<<endl;
}

int main()
{
    Punto punto1, punto2;
    registro_puntos(punto1,1);
    registro_puntos(punto2,2);
    //calculo de la distancia euclidiana
    double distancia=calculo_distancia(punto1,punto2);
    imprimir_distancia(distancia);
    return 0;
}
