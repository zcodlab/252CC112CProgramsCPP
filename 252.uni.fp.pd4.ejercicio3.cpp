#include <iostream>
using namespace std;

void agregar_en_arreglo(int x,int*& V,int  &cont){
    int* q=new int[cont + 1];     //+1 para el nuevo valor a consignar en el arreglo
    //proceso de reasignacion
    for(int i=0; i<cont-1;i++)
        q[i]=V[i];      //se copia
    q[cont-1]=x;    //en la penultima posicion se consigna el nuevo valor
    q[cont]=0;  //en la ultima posicion consignamos el marcador cero
    delete[] V; //liberamos memoria utilizada por el arreglo V, para evitar fugas de memoria
    V=nullptr;  //inicializamos el arreglo en nulo
    V=q;
    cont++;
}


void ingreso_datos(int*& V,int  &cont){
    int x;
    while(x>0){
            cout<<"(0 para salir) x= "; cin>>x;
            if(x>=0)
                agregar_en_arreglo(x,V,cont);
    }
}

void imprimir_arreglo(const char* titulo,int* V){
    cout<<titulo<<":"<<endl;
    for(int i=0; V[i]>0;i++)        //utilizando el marcador como condicion para salir del bucle repetitivo
        cout<<V[i]<<" ";
    cout<<endl;
}
bool encontrado(int x,int*& V){
    if(V==nullptr) return false;    //V esta invicto, no tiene datos, ni siquiera tienen memoria asignada
    for(int i=0; V[i]>0;i++){
            if(V[i]==x)
                return true;        //se econtro el valor x en el arreglo
    }
    return false;   //no se econtro el valor x en el arreglo
}

void clasificacion(int*& X,int*& Y,int*& Z,int &contX,int &contY,int &contZ){
    int x;
    for(int i=0; i<contX-1;i++){
            x=X[i];
            if(x==0) continue;
            if(x%2==0){ //es par
                if(!encontrado(x,Y))    //si es unico
                    agregar_en_arreglo(x,Y,contY);
            }else{
                        if(!encontrado(x,Z))    //si es unico
                            agregar_en_arreglo(x,Z,contZ);
            }
    }
}
void liberarMemoria(int*& X,int*& Y,int*& Z){
    cout<<"Liberando Memoria..."<<endl;
    delete[] X;
    delete[] Y;
    delete[] Z;
    X=nullptr, Y=nullptr,Z=nullptr;
}

int main()
{
    int contA=1, contB=1, contC=1;
    int *A=nullptr, *B=nullptr, *C =nullptr;
    ingreso_datos(A,contA);
    imprimir_arreglo("Arreglo original A",A);
    cout<<"Clasificando en Arreglos de pares e impares "<<endl;
    clasificacion(A,B,C,contA,contB,contC);
    imprimir_arreglo("Arreglo de pares B",B);
    imprimir_arreglo("Arreglo de impares C",C);
    liberarMemoria(A,B,C);
    return 0;
}
