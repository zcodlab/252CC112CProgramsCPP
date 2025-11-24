#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct alumno {
    string nombre;
    string curso;
    int* notas;
};

int main() {
    // Introduciendo datos
    alumno* estudiante;
    int i, s, ne;
    double promedio;

    cout << "Ingrese cantidad de estudiantes:  ";
    cin >> ne;

    int n; // <-- leemos n una sola vez para todos
    cout << "Ingrese cantidad notas: ";
    cin >> n;
    cin.ignore();

    estudiante = new alumno[ne];

    // --- Entrada de datos de todos los estudiantes ---
    for (int j = 0; j < ne; j++) {
        cout << "Escriba el nombre " << j + 1 << ": ";
        getline(cin, estudiante[j].nombre);

        cout << "Escriba el curso " << j + 1 << ": ";
        getline(cin, estudiante[j].curso);

        // Reservar notas para este estudiante
        estudiante[j].notas = new int[n];

        cout << "Ingrese las notas"<<endl;
        for (i = 0; i < n; i++) {
            cout << "Nota " << i + 1 << ": ";
            cin >> estudiante[j].notas[i];
        }
        cin.ignore(); // limpiar salto de linea antes del proximo getline
    }

    // --- Al final: calcular e imprimir los promedios ---
    cout <<endl<<"====== PROMEDIOS FINALES ======"<<endl;
    for (int j = 0; j < ne; j++) {
        s = 0;
        for (i = 0; i < n; i++)
            s = s + estudiante[j].notas[i];
        promedio = (float)s / n;
        cout << "El alumno " << estudiante[j].nombre
             << ", tiene promedio: " << round(promedio) <<endl;
        cout << "------------------"<<endl;
    }

    // liberar memoria
    for (int j = 0; j < ne; j++)
        delete[] estudiante[j].notas;
    delete[] estudiante;
    return 0;
}

