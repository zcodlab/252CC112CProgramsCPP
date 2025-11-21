#include <iostream>
using namespace std;

class Persona{
private:
    string nombre;
public:
    //constructor de la clase, debe tener el mismo nombre de la clase
    Persona(string nombre){
        this->nombre=nombre;
        cout<<"llamando al constructor"<<endl;
    }
    //Destructor de la clase, agregar virgula ALT+126
    ~Persona(){
        cout<<"llamando al destructor"<<endl;
    }
    void saludar(){
        cout<<"Hola, soy: "<<nombre<<endl;
    }
};

int main()
{
    Persona p("Carlos");
    p.saludar();
    return 0;
}
