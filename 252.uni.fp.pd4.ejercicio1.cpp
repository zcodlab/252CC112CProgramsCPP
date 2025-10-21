#include <iostream>
using namespace std;
const int NUM_VENDEDORES=99;
const int BLOQUE_INICIAL=3;

int* expandirArrayInt(int* original,int tamanioActual,int nuevoTamanio){
    int* nuevoArray=new int[nuevoTamanio];
    //Realizar la reasignacion
    for(int i=0;i<tamanioActual;i++)
        nuevoArray[i]=original[i];  //se transfiere todos los datos actuales del arrya original al array actual
    delete[] original;
    return nuevoArray;
}

float* expandirArrayFloat(float* original,int tamanioActual,int nuevoTamanio){
    float* nuevoArray=new float[nuevoTamanio];
    //Realizar la reasignacion
    for(int i=0;i<tamanioActual;i++)
        nuevoArray[i]=original[i];  //se transfiere todos los datos actuales del arrya original al array actual
    delete[] original;
    return nuevoArray;
}

void ingresarVentas(float*& montos,int*& codigos,int& numVentas){
    float monto;
    int codigo;
    int capacidad=BLOQUE_INICIAL;
    numVentas=0;
    montos=new float[capacidad];
    codigos=new int[capacidad];
    while(true){
            cout<<"Ingrese el monto de la venta (-1 para terminar): ";
            cin>>monto;
            if(monto<0) break;  //salimos del bucle while, negativo es la terminacion del ingreso de ventas
            cout<<"Ingrese el codigo del vendedor (1-99): ";
            cin>>codigo;
            //validando el codigo ingresado
            if(codigo<1 || codigo>NUM_VENDEDORES){
                cout<<"Codigo invalido. Intente nuevamente. ";
                continue;
            }
            //verificamos si se supero la capacidad del array dinamico-> incrementar el tama�o del array dinamico
            if(numVentas>=capacidad){
                capacidad+=BLOQUE_INICIAL;
                montos=expandirArrayFloat(montos,numVentas,capacidad);  //monto apunta al nuevo array
                codigos=expandirArrayInt(codigos,numVentas,capacidad);  //codigos apunta al nuevo array
            }
            montos[numVentas]=monto;
            codigos[numVentas]=codigo;
            numVentas++;
    }
}

float calcularTotalYPromedio(float* vecMontos,int* vecCodigos,int numVentas, float totalVentas[]){
    float sumaTotal=0.0f;
    for(int i=0;i<numVentas;i++){
            int cod=vecCodigos[i];
            totalVentas[cod-1]+=vecMontos[i]; //acumulamos el importe de ventas por cada vendedor
            sumaTotal+=vecMontos[i];   //acumulamos el importe de ventas de todos los vendedores
    }
    return (numVentas>0)? sumaTotal/numVentas : 0.0f;
}
int obtenerCodigosUnicos(int* vecCodigos,int numVentas,int codigosUnicos[]){
    int totalUnicos=0;
    //recorremos el array de codigos de vendedores pra recuperar los codigos unicos y el numero de vendedroe
    for(int i=0;i<numVentas;i++){
            int cod=vecCodigos[i];
            bool existe=false;
            //se busca si existe el codigo del vendedor en el array de codigosUnicos
            for(int j=0;j<totalUnicos;j++){
                    if(codigosUnicos[j]==cod){
                            existe=true;
                            break;
                    }
            }
            //si no existe en el array de codigosUnicos
            if(!existe){
                codigosUnicos[totalUnicos]=cod;
                totalUnicos++;
            }
    }
    return totalUnicos;
}
void mostrarVendedoresSuperiores(float totalVentas[],int codigosUnicos[],int totalUnicos,float promedio){
    cout<<"Monto promedio de ventas: "<<promedio<<endl;
    cout<<"Vendedores que superan el promedio: "<<endl;
    bool existe=false;  //flag para contralar si existe minimamente algun vendedor que supero el promedio
    for(int i=0; i<totalUnicos;i++){
            int cod=codigosUnicos[i];   //recupera el codigo del vendedor
            if(totalVentas[cod-1]>promedio){
                    cout<<"Vendedor: "<<cod<<" | Monto vendido: "<<totalVentas[cod-1]<<endl;
                    existe=true;
            }
    }
    if(!existe)
        cout<<"Ningun vendedor supero el promedio"<<endl;
}


int main()
{
    float* vecMontos=nullptr;   //Array de Importes
    int* vecCodigos=nullptr;    //Array de Codigos de Vendedores
    int numVentas=0;
    //Paso1: Ingreso de Ventas
    ingresarVentas(vecMontos,vecCodigos,numVentas);
    //Paso2: Calcular el total de ventas por vendedor y el promedio de las ventas
    float totalVentas[NUM_VENDEDORES]={0.0f};
    float promedio=calcularTotalYPromedio(vecMontos,vecCodigos,numVentas, totalVentas);
    //Paso3: Obtener los codigos unicos utilizados;
    int codigosUnicos[NUM_VENDEDORES];
    int totalUnicos=obtenerCodigosUnicos(vecCodigos,numVentas,codigosUnicos);
    //Paso4: Mostrar los vendedores que superan el promedio de ventas
    mostrarVendedoresSuperiores(totalVentas,codigosUnicos,totalUnicos,promedio);
    //Paso5: Liberar memoria dinamica
    delete[] vecMontos;
    delete[] vecCodigos;
    vecMontos=nullptr;
    vecCodigos=nullptr;
    return 0;
}
