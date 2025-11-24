#include <iostream>
#include <cstring>
using namespace std;

void mostrar_estudiantes(char** estudiantes, int cantidad, int capacidad);
void duplicar_capacidad(char** &estudiantes, int &capacidad, int cantidad);
void agregar_estudiante(char** &estudiantes, int &cantidad, int &capacidad, const char* nombre);
void eliminar_estudiante(char** estudiantes, int &cantidad, const char* nombre);
void liberar_memoria(char** estudiantes, int cantidad);

int main() {
    int capacidad = 3;
    int cantidad = 0;
    char** estudiantes = new char*[capacidad];

    // Ejemplo de lista de estudiantes a agregar
    const char* lista[] = {"Luis", "Javier", "Sofia", "Andres", "Carlos"};
    int n = 5;

    for (int i = 0; i < n; i++)
        agregar_estudiante(estudiantes, cantidad, capacidad, lista[i]);

    mostrar_estudiantes(estudiantes, cantidad, capacidad);

    eliminar_estudiante(estudiantes, cantidad, "Sofia");
    mostrar_estudiantes(estudiantes, cantidad, capacidad);

    liberar_memoria(estudiantes, cantidad);
    delete[] estudiantes;

    return 0;
}

void mostrar_estudiantes(char** estudiantes, int cantidad, int capacidad) {
    cout << "Estudiantes registrados (" << cantidad << "/" << capacidad << "):"<<endl;
    for (int i = 0; i < cantidad; i++)
        cout << "- " << estudiantes[i] <<endl;
    cout << endl;
}


void duplicar_capacidad(char** &estudiantes, int &capacidad, int cantidad) {
    int nueva_capacidad = capacidad * 2;
    char** nuevo_arreglo = new char*[nueva_capacidad];

    for (int i = 0; i < cantidad; i++) {
        nuevo_arreglo[i] = new char[strlen(estudiantes[i]) + 1];
        strcpy(nuevo_arreglo[i], estudiantes[i]);
        delete[] estudiantes[i];
    }

    delete[] estudiantes;
    estudiantes = nuevo_arreglo;
    capacidad = nueva_capacidad;

    cout << "Capacidad llena. Duplicando a " << capacidad << "endl";
}

void agregar_estudiante(char** &estudiantes, int &cantidad, int &capacidad, const char* nombre) {
    if (cantidad == capacidad)
        duplicar_capacidad(estudiantes, capacidad, cantidad);

    estudiantes[cantidad] = new char[strlen(nombre) + 1];
    strcpy(estudiantes[cantidad], nombre);
    cantidad++;

    cout << "Agregando: " << nombre <<endl;
    if (cantidad >= capacidad * 0.8) {
        cout << "Advertencia: el arreglo esta al "
             << (cantidad * 100.0 / capacidad)
             << "% de su capacidad."<<endl;
    }
}

void eliminar_estudiante(char** estudiantes, int &cantidad, const char* nombre) {
    int indice = -1;
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(estudiantes[i], nombre) == 0) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        cout << "Estudiante no encontrado: " << nombre <<endl;
        return;
    }

    cout << "Eliminando: " << nombre <<endl;
    delete[] estudiantes[indice];

    for (int i = indice; i < cantidad - 1; i++)
        estudiantes[i] = estudiantes[i + 1];
    cantidad--;
}

void liberar_memoria(char** estudiantes, int cantidad) {
    for (int i = 0; i < cantidad; i++)
        delete[] estudiantes[i];
}
