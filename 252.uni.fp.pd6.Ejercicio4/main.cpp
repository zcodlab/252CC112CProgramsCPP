#include <iostream>
#include <vector>
#include <memory>

#include "Building.cpp"
#include "Bicycle.cpp"
#include "Car.cpp"
using namespace std;

int main()
{
    vector<shared_ptr<CarbonFootprint>> objeto;
    //CarbonFootprint *
    objeto.push_back(make_shared<Building>(12000));
    //make_shared: crea un shared_ptr<T> de forma segura, eficiente y clara
    //es mas limpio, mas rapido y evita errores comunes
    //crea un objeto dinamico de tipo Building usando su constructor que recibe 12,000
    //KWh/anio, lo encapsula en un puntero inteligente shared_ptr,
    //luego inserta ese puntero dentro del vector
    objeto.push_back(make_shared<Bicycle>(850));
    objeto.push_back(make_shared<Car>(12));
    //Realizando un procesamiento polimorfico para imprimir la
    //informacion de los objetos y la contaminacion anual que esta genera
    for(const auto& obj : objeto)  {
            obj->printInfo();
            cout<<"Huella de Carbono: "<<obj->getCarbonFootprint()<<" kg CO2/anio"<<endl;
      }

      return 0;
}
