#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct coordenada{
    float _X;
    float _Y;
    string nombre;  //nombre del vertice
};

struct arista{
    coordenada P1;  //punto o vertice inicial de la arista
    coordenada P2; //punto o vertice final de la arista
    float distancia;    //distancia de la arista
    string nombre;   //nombre de la arista
};

void registro_vertices(coordenada& A,coordenada& B,coordenada& C){
    cout<<"Ingrese el nombre del primer vertice: ";
    getline(cin,A.nombre);
    cout<<"Ingrese la coordenada x del primer vertice: ";
    cin>>A._X;
    cout<<"Ingrese la coordenada y del primer vertice: ";
    cin>>A._Y;
    cin.ignore();//limpiar buffer

    cout<<"Ingrese el nombre del segundo vertice: ";
    getline(cin,B.nombre);
    cout<<"Ingrese la coordenada x del segundo vertice: ";
    cin>>B._X;
    cout<<"Ingrese la coordenada y del segundo vertice: ";
    cin>>B._Y;
    cin.ignore();//limpiar buffer

    cout<<"Ingrese el nombre del tercer vertice: ";
    getline(cin,C.nombre);
    cout<<"Ingrese la coordenada x del tercer vertice: ";
    cin>>C._X;
    cout<<"Ingrese la coordenada y del tercer vertice: ";
    cin>>C._Y;
    cin.ignore();//limpiar buffer
}
void inicializarArista(arista* V, string np1, string np2, float x1,float y1,float x2,float y2){
    V ->P1.nombre=np1;
    V ->P2.nombre=np2;
    V ->P1._X=x1;
    V ->P1._Y=y1;
    V ->P2._X=x2;
    V ->P2._Y=y2;
    V ->nombre=V ->P1.nombre+"-"+V ->P2.nombre;
    V ->distancia=sqrt(pow((x2-x1),2)+pow((y2-y1),2));  //aplicando formula de distancia euclidiana 2D
}
float calcularArea(arista a,arista b,arista c){
    float s=(a.distancia + b.distancia + c.distancia)/2.0;
    float area=sqrt(s*(s-a.distancia)*(s-b.distancia)*(s-c.distancia));
    return area;
}
void mostrarArista(arista r){
    cout<<"---------------------------------------------------------------"<<endl;
    cout<<"Nombre de arista: "<<r.nombre<<endl;
    cout<<"Coordenada del punto "<<r.P1.nombre<<" : ("<<r.P1._X<<", "<<r.P1._Y<<")"<<endl;
    cout<<"Coordenada del punto "<<r.P2.nombre<<" : ("<<r.P2._X<<", "<<r.P2._Y<<")"<<endl;
    cout<<"Distancia de la arista: "<<r.distancia<<endl;
}

int main()
{
    coordenada A,B,C;   //triangulo definido sobre 3 vertices
    arista a,b,c;
    //registro de los vertices del triangulo
    registro_vertices(A,B,C);
    //inicializar aristas
    inicializarArista(&a, A.nombre, B.nombre, A._X,A._Y,B._X,B._Y);
    inicializarArista(&b, B.nombre, C.nombre, B._X,B._Y,C._X,C._Y);
    inicializarArista(&c, C.nombre, A.nombre, C._X,C._Y,A._X,A._Y);
    //calcular el area aplicando el metodo de heron
    float area=calcularArea(a,b,c);
    //Mostrar Resultados
    mostrarArista(a);
    mostrarArista(b);
    mostrarArista(c);
    cout<<"El area del triangulo formado por la 3 aristas es: "<<area<<endl;
    return 0;
}
