#include <iostream>
#include "Bicycle.h"
using namespace std;

Bicycle:: Bicycle(double hours): maintenanceHours(hours){}

double Bicycle::getCarbonFootprint() const {
    return maintenanceHours*0.5;
}

void Bicycle::printInfo() const {
    cout<<"Bicycle: "<<maintenanceHours<<" horas de mantenimiento anual."<<endl;
}
