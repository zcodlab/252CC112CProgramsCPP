#include <iostream>
using namespace std;

int max_vector(int A[],int k){
    int max=A[0];
    for(int i=1;i<k;i++)
        if(max<A[i]) max=A[i];
    return max;
}
int suma_vector(int A[],int k){
    int suma=A[0];
    for(int i=1;i<k;i++)
        suma+=A[i];
    return suma;
}
int es_posible_grupo(int A[],int k,int n,int max_viaje){
    int cont=1; // cont es el numero de grupos posibles
    int sum=0;
    for(int i=0;i<k;i++){
            int distancia=A[i];
            if(distancia>max_viaje)
                return 0;   //imposible, un pedido excede el limite
            if(sum+distancia>max_viaje){
                    cont++;
                    sum=distancia;      //actualizamos suma con el valor de distancia
            }else
                sum+=distancia;         //continuamos acumulando en el grupo
    }//end for
    return (cont<=n);
}

int reparto_minimo(int A[],int k,int n){
    int menor_viaje=max_vector(A,k);    //un paquete en un grupo
    int mayor_viaje=suma_vector(A,k);   //todos los paquetes en un grupo
    int resultado=mayor_viaje;
    while(menor_viaje<=mayor_viaje){
            int max_viaje=(menor_viaje+mayor_viaje)/2;
            if(es_posible_grupo(A,k,n,max_viaje)){
                resultado=max_viaje;
                //intentamos con una menor distancia
                mayor_viaje=max_viaje - 1;
            }else
                //intentamos con una mayor distancia
                menor_viaje=max_viaje + 1;
    }
    return resultado;
}

int main()
{
    int A[]={7,2,5,10,8};   //32, distancia de cada pedido(km)
    int k=5;                     //numero de pedidos
    int n=2;                    //numero de repqartidores
    int dmax=reparto_minimo(A,k,n);
    cout<<dmax;

    return 0;
}
