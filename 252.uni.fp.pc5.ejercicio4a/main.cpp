#include <iostream>
using namespace std;
class Contador {
private:
    int valor;

public:
    // a.i) Constructor por defecto Inicializa valor a 0
    Contador() : valor(0) {
        cout << "Constructor por defecto: valor inicializado a 0."<<endl;
    }

    // a.ii) Constructor con parámetro, permite establecer un valor inicial específico
    Contador(int v) : valor(v) {
        cout << "Constructor con parámetro: valor inicializado a " << valor << "."<<endl;
    }

    // a.iii) Método incrementar, retorna el objeto usando el puntero this (retornar *this)
    // Esto permite encadenar llamadas: c.incrementar(5).incrementar(10)
    Contador& incrementar(int cantidad) {
        valor += cantidad;
        return *this;
    }

    // a.iv) Método mostrar, imprime el valor actual
    void mostrar() const {
        cout << "Valor actual del contador: " << valor <<endl;
    }

    // Destructor, se ejecuta al destruir el objeto y muestra un mensaje
    ~Contador() {
        cout << "Destructor llamado: objeto Contador destruido."<<endl;
    }
};

int main() {
    Contador c(10);

    //a.v) Llamada encadenada usando el puntero this
    c.incrementar(5).incrementar(10).mostrar();

    return 0;
}

