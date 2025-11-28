#include <stdexcept>
#include "TwoDayPackage.h"
//implementacion del constructor
TwoDayPackage::TwoDayPackage(string rNom,string rDir, string rCiu,string rEst, string rCP,
                   string dNom,string dDir, string dCiu,string dEst, string dCP,
                   double p,double costo, double tarifa)
:Package(rNom,rDir, rCiu,rEst, rCP,dNom,dDir, dCiu,dEst, dCP, p, costo)
{   if(tarifa<0)
         throw std::invalid_argument("Tarifa Fija no puede ser negativa");
    tarifaFija=tarifa;
}
//redefiniendo la funcion miembro calcular costo
double TwoDayPackage:: calculateCost() const{
    //a la costo estandar le sumamos una tarifa fija, de acuerdo al enunciado
    return Package::calculateCost() + tarifaFija;
}
