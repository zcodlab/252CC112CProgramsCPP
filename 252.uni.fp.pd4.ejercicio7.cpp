#include <iostream>
using namespace std;

struct Estudiante{
    string nombre;
    float nota;
};

void registro_estudiantes(Estudiante*& e,int& n){
    cout<<"Ingrese el numero de estudiantes a registrar: ";cin>>n;
    cin.ignore();   //limpiar el buffer
    e = new Estudiante[n];
    for(int i=0; i<n;i++){
        cout<<"Ingrese el nombre del estudiante "<<i+1<<": ";
        getline(cin,e[i].nombre);
        cout<<"Ingrese la nota del estudiante "<<i+1<<": ";
        cin>>e[i].nota;
        cin.ignore();   //limpiar el buffer
    }
}
int calculo_mayorNota(Estudiante* e,int n){
    int indiceMayorNota=0;
    float mayorNota=e[0].nota;
    for(int i=1; i<n;i++){
            if(e[i].nota>mayorNota){
                mayorNota=e[i].nota;
                indiceMayorNota=i;
            }
    }
    return indiceMayorNota;
}
void imprimir_mayorNota(Estudiante* e,int indice){
    cout<<"El estudiante con mayor nota es: "
           <<e[indice].nombre<<endl;
    cout<<"Nota: "<<e[indice].nota<<endl;
}

void liberar_memoria(Estudiante*& e){
    delete[] e;
    e=nullptr;
}

int main()
{
    Estudiante* estudiantes=nullptr;
    int n=0;
    registro_estudiantes(estudiantes,n);
    int indiceMayorNota=calculo_mayorNota(estudiantes,n);
    imprimir_mayorNota(estudiantes,indiceMayorNota);
    liberar_memoria(estudiantes);   //para evitar fugas de memoria
    return 0;
}
