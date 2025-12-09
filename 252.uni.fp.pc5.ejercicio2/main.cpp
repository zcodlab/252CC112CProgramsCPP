#include <iostream>
#include <string>
using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    int codigo;
    bool prestado;
    int vecesPrestado;

public:
    // Constructor vacio
    Libro() {}

    // Metodo para configurar datos del libro
    void configurarDatos(const string& t, const string& a, int c) {
        if (t.empty() || a.empty()) {
            cout << "Error: el titulo y el autor no pueden estar vacios." << endl;
            return;
        }
        if (c <= 0) {
            cout << "Error: el codigo debe ser un entero positivo." << endl;
            return;
        }

        titulo = t;
        autor = a;
        codigo = c;
        prestado = false;
        vecesPrestado = 0;
    }

    // Prestar el libro
    void prestar() {
        if (!prestado) {
            prestado = true;
            vecesPrestado++;
            cout << "Libro prestado correctamente." << endl;
        } else {
            cout << "El libro ya esta prestado. No se puede prestar nuevamente." << endl;
        }
    }

    // Devolver el libro
    void devolver() {
        if (prestado) {
            prestado = false;
            cout << "Libro devuelto correctamente." << endl;
        } else {
            cout << "El libro no estaba prestado. No se puede devolver." << endl;
        }
    }

    // Mostrar informacion del libro
    void mostrarInformacion() const {
        cout << "----------------------------------------" << endl;
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Codigo: " << codigo << endl;
        cout << "Estado: " << (prestado ? "Prestado" : "Disponible") << endl;
        cout << "Veces prestado: " << vecesPrestado << endl;
        cout << "----------------------------------------" << endl;
    }

    // Resetear historial de prestamos
    void resetearHistorial() {
        vecesPrestado = 0;
        cout << "Historial de prestamos reiniciado." << endl;
    }
};


// -------------------------------------------------------------

int main() {
    Libro libro;

    // Se configuran los datos usando el metodo correspondiente
    libro.configurarDatos("Cien anios de soledad", "Gabriel Garcia Marquez", 101);

    libro.mostrarInformacion();

    libro.prestar();
    libro.mostrarInformacion();

    libro.prestar(); // intenta prestar otra vez

    libro.devolver();
    libro.mostrarInformacion();

    libro.resetearHistorial();
    libro.mostrarInformacion();

    return 0;
}

