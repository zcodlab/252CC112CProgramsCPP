#ifndef INTEGERSET_H
#define INTEGERSET_H

#include <vector>
#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>

class IntegerSet{
    //miembros dato
    private:
        std::vector<bool> elementos;//un vector de booleanos
    public:
        //constructores
        //1° constructor por defecto, constructor sin parametros
        //crea un vector de 101 elementos y lo inicializa en false
        IntegerSet(): elementos(101,false){ }
        //2° constructor con arreglo de enteros
        IntegerSet(const std::vector<int>& vals): elementos(101,false){
            for(int val: vals){
                    if(val>=0 && val<=100)
                            elementos[val]=true;
            }
        }
        //Union de conjuntos
        static IntegerSet unionOfSets(const IntegerSet& a,const IntegerSet& b){
            IntegerSet result;
            for(int i=0; i<=100;i++)
                    //consignar el result el resultado de realizar un OR entre los objetos a y b
                    result.elementos[i]=a.elementos[i] || b.elementos[i];
            return result;
        }
        //Union de conjuntos
        static IntegerSet intersectionOfSets(const IntegerSet& a,const IntegerSet& b){
            IntegerSet result;
            for(int i=0; i<=100;i++)
                    //consignar el result el resultado de realizar un AND entre los objetos a y b
                    result.elementos[i]=a.elementos[i] && b.elementos[i];
            return result;
        }

        //insertar un elemento
        void insertElement(int k){
             if(k>=0 && k<=100)
                    elementos[k]=true;
        }
        //eliminar elemento
        void deleteElement(int m){
             if(m>=0 && m<=100)
                 elementos[m]=false;
        }
        //implementar la funcion miembro toString()
        //la funcion miembro toString() es const por que no va a modificar ninguno de sus miembro dato
        std::string toString() const {
            //parte de la libreria sstream (flujo de texto) que permite construir texto
            std::ostringstream oss;
            bool empty=true;
            //buscamos los elementos que estan en true y los concatena
             for(int i=0; i<=100;i++){
                    if(elementos[i]){
                        oss<<i<<" ";
                        empty=false;
                    }
             }//end for
             //si empty es true entonces retorna 2 guiones,
             //caso contrario retorna el flujo de texto que armo
             return empty ? "--": oss.str();
        }//end toString

        //compara si dos objetos son iguales
        bool isEqualTo(const IntegerSet& other) const{
            return elementos==other.elementos;
        }
};


#endif // INTEGERSET_H
