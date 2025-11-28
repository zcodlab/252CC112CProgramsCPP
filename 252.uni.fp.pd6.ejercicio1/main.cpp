#include <iostream>
#include "IntegerSet.h"

int main()
{
    //Crear conjuntos
    IntegerSet set1;    //utiliza el 1° constructor
    IntegerSet set2({10,20,30,40}); //utiliza el 2° constructor
    IntegerSet set3({30,40,50,60}); //utiliza el 2° constructor
    //visualizando los conjuntos
    std::cout<<"Set1: "<<set1.toString()<<std::endl;
    std::cout<<"Set2: "<<set2.toString()<<std::endl;
    std::cout<<"Set3: "<<set3.toString()<<std::endl;
    //insertando elementos en el conjunto1
    set1.insertElement(5);
    set1.insertElement(10);
    set1.insertElement(30);
    //visualizando el conjunto 1 despues de insertar datos
    std::cout<<"Set1 despues de insertar: "<<set1.toString()<<std::endl;
    //eliminando elementos en el conjunto1
    set1.deleteElement(10);
    std::cout<<"Set1 despues de eliminar "<<set1.toString()<<std::endl;
    //Union de conjuntos
    //invocamos directamente, sin crean un objeto o instancia;
    //al metodo unionOfSets debido a que unionOfSets es static
    IntegerSet unionSet=IntegerSet::unionOfSets(set2,set3);
    std::cout<<"union de set2 y set3: "<<unionSet.toString()<<std::endl;
    //Interseccion de conjuntos
    IntegerSet intersecSet=IntegerSet::intersectionOfSets(set2,set3);
    std::cout<<"interseccion de set2 y set3: "<<intersecSet.toString()<<std::endl;
    //comparando objetos
    std::cout<<"set2 es igual a set3? "<<(set2.isEqualTo(set3)? "Si" : "No")<<std::endl;
    //conjunto vacio; utlizando el 1° construccion
    IntegerSet emptySet;
    std::cout<<"conjunto vacio: "<<emptySet.toString()<<std::endl;
    return 0;
}
