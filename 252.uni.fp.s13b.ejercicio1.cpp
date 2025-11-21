#include <iostream>
using namespace std;

class Persona{
    private:
        //miembros datos, atributos, variables de clase
        string nombre;
        int edad;
    public:
        //funciones miembro de la clase o metodos
        void setDatos(string n,int e){
            nombre=n;
            edad=e;
        }
        void mostrar(){
            cout<<"Nombre: "<<nombre<<",Edad:  "<<edad<<endl;
        }
};
int main()
{
    //Declarando dos objetos del tipo Persona
    Persona p1,p2;
    //Invocando las funciones miembro del primer objeto
    p1.setDatos("Ana",30);
    p1.mostrar();
    //Invocando las funciones miembro del segundo objeto
    p2.setDatos("Juan",22);
    p2.mostrar();
    return 0;
}
