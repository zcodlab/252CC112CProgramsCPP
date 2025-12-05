#include <iostream>
using namespace std;
/* b)	Implementar una clase X, para que la siguiente instrucción sea válida
    v1()(7)()[4] = 100;
    donde v1 es un objeto de la clase X.
*/
class Z{
private:
       int* datos;
       int size;
public:
    Z(int sz=10): size(sz){
        datos=new int[size];
        for(int i=0;i<size;i++)
            datos[i]=0;
    }
    ~Z(){delete[] datos;}
    //sobrecarga del operador(), sin parametro
    int* operator()(){
        return datos;
    }
};
class Y{
private:
    Z** arreglo;    //miembro datos con puntero doble a Z
    int capacidad;
public:
    Y(int cap=10): capacidad(cap){
        arreglo=new Z*[capacidad];
        for(int i=0;i<capacidad;i++)
            arreglo[i]=nullptr;
    }
    ~Y(){//aprovechamos el destructor para liberar memoria
        for(int i=0;i<capacidad;i++)
            delete arreglo[i];
        delete[] arreglo;
    }
    Z& operator()(int n){
        if(n>=capacidad){
                int nuevaCap=n+10;
                Z** nuevo=new Z*[nuevaCap];
                for(int i=0;i<nuevaCap;i++)
                    nuevo[i]=(i<capacidad)? arreglo[i]: nullptr;
                delete[] arreglo;
                arreglo=nuevo;
                capacidad=nuevaCap;
        }
        if(arreglo[n]==nullptr)
            arreglo[n]=new Z();
        return *arreglo[n]; //retorna el puntero
    }
};
class X{
    private:
    Y y;
    public:
      X()  : y(10){}
      Y& operator()(){
          return y;
      }
};

int main()
{
    X v1;
    v1()(7)()[4]=100;

    cout<<v1()(7)()[4]<<endl;   //debe imprimir 100;
    return 0;
}
