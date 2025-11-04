#include <iostream>
using namespace std;

struct Libro{
        string titulo;
        string autor;
        int anioPublicacion;
        int numpaginas;
};
void ingresarLibros(Libro* &biblioteca,int &numLibros){
    cout<<"Ingrese el numero de libros a registrar:"; cin>>numLibros;
    //aplicando asignacion dinamica de memoria
    biblioteca=new Libro[numLibros];
    for(int i=0; i<numLibros; i++){
            cout<<"Ingrese los detalles del libro #"<<i+1<<":"<<endl;
            cout<<"Titulo: ";
            cin.ignore();//limpieza del buffer
            getline(cin,biblioteca[i].titulo);
            cout<<"Autor: ";
            getline(cin,biblioteca[i].autor);
            cout<<"Anio Publicacion: "; cin>>biblioteca[i].anioPublicacion;
            cout<<"Numero de Paginas: "; cin>>biblioteca[i].numpaginas;
    }
}
void mostrarLibros(Libro* biblioteca,int numLibros){
    cout<<"-----------------------------Lista de Libros----------------------------------"<<endl;
    for(int i=0; i<numLibros; i++){
         cout<<"Titulo: "<<biblioteca[i].titulo<<endl;
         cout<<"Autor: "<<biblioteca[i].autor<<endl;
         cout<<"Anio Publicacion: "<<biblioteca[i].anioPublicacion<<endl;
         cout<<"Numero de Paginas: "<<biblioteca[i].numpaginas<<endl;
         cout<<"------------------------------------------------------------------------------"<<endl;
    }
}
void buscarLibrosPorAutor(Libro* biblioteca,int numLibros,string autorBuscado){
    cout<<"Libros del Autor "<<autorBuscado<<": "<<endl;
    for(int i=0; i<numLibros; i++){
            if(biblioteca[i].autor.compare(autorBuscado)==0)
                cout<<"Titulo: "<<biblioteca[i].titulo<<endl;
    }
}

int main()
{
    Libro* biblioteca=nullptr;
    int numLibros=0;
    ingresarLibros(biblioteca,numLibros);
    mostrarLibros(biblioteca,numLibros);

    string autorBuscado;
    cout<<"Ingrese el autor a buscar:";
    cin.ignore();
    getline(cin,autorBuscado);
    buscarLibrosPorAutor(biblioteca,numLibros,autorBuscado);
    //liberar memoria
    delete[] biblioteca;    //liberar memoria utilizada para evitar fugas
    biblioteca=nullptr;
    return 0;
}
