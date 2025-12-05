#include <iostream>
using namespace std;
/**sobrecarga del operador []*/
class Arreglo{
    int datos[5];//miembro dato
public:
    Arreglo(){
        for(int& x : datos)
            x=0;
    }
    //sobrecargando el operador []
    int& operator[](int i){
        return datos[i];
    }
};


int main()
{
    Arreglo arr;
    arr[2]=50;
    cout<<arr[2]<<endl;// imprime 50
    cout<<arr.operator[](2)<<endl;// imprime 50
    return 0;
}
