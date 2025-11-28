#include <iostream>
#include "Package.h"
//implementacion del constructor
Package::Package(string rNom,string rDir,string rCiu, string rEst, string rCP,
                 string dNom,string dDir,string dCiu, string dEst, string dCP,
                 double p,double costo)
     : remitenteNombre(rNom),destinatarioNombre(dNom),
     remitenteDireccion(rDir),destinatarioDireccion(dDir),
     remitenteCiudad(rCiu),destinatarioCiudad(dCiu),
     remitenteEstado(rEst),destinatarioEstado(dEst),
     remitenteCP(rCP),destinatarioCP(dCP){
         if(p<=0 || costo<=0)
                throw invalid_argument("Peso y Costo deben ser positivos");
         peso=p;
         costoPorOnza=costo;
     }
     //implementacion de la funcion miembro calcular costo
     double Package::calculateCost() const{
         return peso*costoPorOnza;
     }
     //implementacion de la funcion mostrar informacion
     void Package::mostrarInfo() const{
         cout<<"De: "<<remitenteNombre<<" -> Para: "<<destinatarioNombre<<endl;
     }

