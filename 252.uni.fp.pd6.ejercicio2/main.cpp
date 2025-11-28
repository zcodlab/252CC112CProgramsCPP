#include <iostream>
#include <iomanip>
#include "Package.cpp"
#include "TwoDayPackage.cpp"

using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

int main()
{
    cout << fixed<<setprecision(2);
    //Entrega de paquete estandar
    Package p1("Ana","Calle1","Lima","Lima","150101",
               "Luis","Av. 28 julio 255","Cuzco","Cuzco","320101",5.0,2.0);
    p1.mostrarInfo();
    cout<<"Costo S/ "<<p1.calculateCost()<<endl;

    //Entrega de paquete urgente, en dos dias
    TwoDayPackage p2("Ana","Calle1","Lima","Lima","150101",
               "Luis","Av. 28 julio 255","Cuzco","Cuzco","320101",5.0,2.0,3.0);
    p2.mostrarInfo();
    cout<<"Costo S/ "<<p2.calculateCost()<<endl;

    return 0;
}
