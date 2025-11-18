#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstddef>  //para uso de la funcion offsetof
using namespace std;

struct Usuario{
    int id;
    char nombre[80];
    double saldo;
};
//crea un archivo binario con informacion de usuarios
void crearArchivoUsuarios(const char* nombreArchivo,int n){
    ofstream archivo(nombreArchivo, ios::binary);
    if(!archivo){
            //cerr: es equivalente a cout, pero utiliza para imprimir errores
            cerr<<"Error, el archivo no existe"<<endl;
            return;
    }
    Usuario usuario;
    for(int i=0;i<n;i++){
            cout<<"Nuevo Usuario"<<endl;
            cout<<"\tCodigo:";cin>>usuario.id;
            cin.get();
            cout<<"\tNombre:"; cin.getline(usuario.nombre,80);
            cout<<"\tSaldo:";cin>>usuario.saldo;
            //Escribir en el archivo la memoria cruda(data como esta en memoria) de la estructura usuario
            archivo.write(reinterpret_cast<const char*>(&usuario), sizeof(Usuario));
    }
    archivo.close();
    cout<<"Usuarios registrados en archivo binario"<<endl;
}
void listaUsuarios(const char* nombreArchivo){
    ifstream archivo(nombreArchivo, ios::binary);
    if(!archivo){
            cerr<<"Error, el archivo no existe"<<endl;
            return;
    }
    Usuario usuario;
    cout<<fixed<<setprecision(2);
    cout<<"Contenido del archivo: "<<endl;
    while(archivo.read(reinterpret_cast<char*>(&usuario), sizeof(Usuario))){
            cout<<"Codigo: "<<setw(5)<<usuario.id
                    <<" | Nombre: "<<setw(10)<<usuario.nombre
                    <<" | Saldo: "<<setw(5)<<usuario.saldo<<endl;
    }
    archivo.close();
}
void incrementarSaldoUsuario(const char* nombreArchivo){
    fstream archivo(nombreArchivo, ios::binary | ios::in | ios:: out);
     if(!archivo){
            cerr<<"Error, el archivo no existe"<<endl;
            return;
    }
    int codigo;
    double incremento;
    cout<<"Modificacion del Saldo"<<endl;
    cout<<"\tCodigo de usuario: ";
    cin>>codigo;
    cout<<"\tIncremento de Saldo : ";
    cin>>incremento;
    Usuario usuario;
    while(archivo.read(reinterpret_cast<char*>(&usuario), sizeof(Usuario))){
            if(usuario.id==codigo){
                // tellg(): devuelve la posicion actual del archivo
                //posRegistro: a la posicion actual le resta el numero de bytes utilizados por la estructura Usuario (+/- 92bytes en este ejercicio)
                //con la finalidad de posicionarse al inicio del item usuario
                streampos posRegistro=archivo.tellg() - streamoff(sizeof(Usuario));
                //se desea que el puntero se posicione exactamente en el campo
                //saldo del usuario con la posicion: posRegistro
                //para ello a posRegistro le sumamos el desplazamiento, que corresponde al
                //numero de bytes hasta saldo
                streampos posSaldo=posRegistro + offsetof(Usuario,saldo);
                double nuevoSaldo=usuario.saldo + incremento;
                //seekp: permite posicionamiento para escritura, aqui estamos
                //colocando el puntero exactamente en la inicio de saldo
                archivo.seekp(posSaldo);
                archivo.write(reinterpret_cast<const char*>(&nuevoSaldo), sizeof(double));
                cout<<"Saldo actualizado correctamente"<<endl;
                archivo.close();
                return;
            }
    }
    cout<<"Usuario con codigo "<<codigo<<" no existe"<<endl;
    archivo.close();
}

int main()
{
    const char* nombreArchivo="usuarios.dat";
    int numUsuarios;
    cout<<"Numero de usuarios: ";
    cin>>numUsuarios;
    crearArchivoUsuarios(nombreArchivo,numUsuarios);
    listaUsuarios(nombreArchivo);
    incrementarSaldoUsuario(nombreArchivo);
    cout<<"Despues de modificar el saldo "<<endl;
    listaUsuarios(nombreArchivo);
    return 0;
}
