#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
const int NVAC=3;

struct Postulante {
    string nombre;
    string carrera;
    double puntaje;
    int ranking;
    string estado;
};

// Prototipos
void ingresarPostulantes(Postulante*& lista, int& n);
void ordenarPostulantes(Postulante* lista, int n);
void calcularRankingYEstado(Postulante* lista, int n);
void mostrarRankingPorCarrera(Postulante* lista, int n);
void mostrarIngresantesPorCarrera(Postulante* lista, int n);
void mostrarMenu();
void liberarMemoria(Postulante*& lista);

int main() {
    Postulante* lista = nullptr;
    int n = 0;
    int opcion;
    do {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();
        switch (opcion) {
            case 1:
                ingresarPostulantes(lista, n);
                break;
            case 2:
                calcularRankingYEstado(lista, n);
                break;
             case 3:
                mostrarRankingPorCarrera(lista, n);
                break;
            case 4:
                mostrarIngresantesPorCarrera(lista, n);
                break;
            case 5:
                liberarMemoria(lista);
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }
        cout << endl;
    } while (opcion != 5);
    return 0;
}

// --------------------------------------------------------------
void mostrarMenu() {
    cout << "==============================" << endl;
    cout << " PROCESO DE ADMISION - UNI" << endl;
    cout << "==============================" << endl;
    cout << "1. Ingresar postulantes" << endl;
    cout << "2. Calcular ranking y estado" << endl;
    cout << "3. Mostrar ranking por carrera" << endl;
    cout << "4. Mostrar ingresantes por carrera" << endl;
    cout << "5. Salir" << endl;
    cout << "==============================" << endl;
}

// --------------------------------------------------------------
void ingresarPostulantes(Postulante*& lista, int& n) {
    cout << "Ingrese el numero de postulantes: ";
    int nuevos;
    cin >> nuevos;
    cin.ignore();
    Postulante* nuevaLista = new Postulante[n + nuevos];
    // Copiar los anteriores
    for (int i = 0; i < n; i++)
        nuevaLista[i] = lista[i];
    delete[] lista;
    // Leer los nuevos
    for (int i = n; i < n + nuevos; i++) {
        cout << endl << "Postulante #" << i + 1 << endl;
        cout << "Nombre completo: ";
        getline(cin, nuevaLista[i].nombre);
        cout << "Carrera profesional: ";
        getline(cin, nuevaLista[i].carrera);
        cout << "Puntaje obtenido: ";
        cin >> nuevaLista[i].puntaje;
        cin.ignore();
        nuevaLista[i].ranking = 0;
        nuevaLista[i].estado = "Sin asignar";
    }
    lista = nuevaLista;
    n += nuevos;
    cout << endl << ">> Postulantes registrados correctamente." << endl;
}

// --------------------------------------------------------------
// Funcion que ordena postulantes por carrera y puntaje descendente
void ordenarPostulantes(Postulante* lista, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            bool debeIntercambiar = false;
            if (lista[i].carrera > lista[j].carrera)
                debeIntercambiar = true;
            else if (lista[i].carrera == lista[j].carrera &&
                       lista[i].puntaje < lista[j].puntaje) {
                      debeIntercambiar = true;
            }
            if (debeIntercambiar)
                swap(lista[i], lista[j]);
        }
    }
}

// --------------------------------------------------------------
void calcularRankingYEstado(Postulante* lista, int n) {
    if (n == 0) {
        cout << "No hay postulantes registrados." << endl;
        return;
    }
    ordenarPostulantes(lista, n);
    string carreraActual = "";
    int rankingCarrera = 1;
    int contadorCarrera = 0;

    for (int i = 0; i < n; i++) {
        if (lista[i].carrera != carreraActual) {
            carreraActual = lista[i].carrera;
            rankingCarrera = 1;
            contadorCarrera = 0;
        }

        contadorCarrera++;

        // Asignar ranking
        if (contadorCarrera == 1)
            lista[i].ranking = rankingCarrera;
        else {
            if (lista[i].carrera == lista[i - 1].carrera &&
                lista[i].puntaje == lista[i - 1].puntaje)
                // Empate, mismo ranking
                lista[i].ranking = lista[i - 1].ranking;
            else {
                rankingCarrera++;
                lista[i].ranking = rankingCarrera;
            }
        }

        // Asignar estado segun ranking
        if (lista[i].ranking <= NVAC)
            lista[i].estado = "Ingreso";
        else
            lista[i].estado = "No ingreso";
    }
    mostrarRankingPorCarrera( lista, n);
}

void mostrarRankingPorCarrera(Postulante* lista, int n){
      if (n == 0) {
        cout << "No hay postulantes registrados." << endl;
        return;
    }
    cout << endl << ">> Ranking y estado asignados correctamente." << endl;
    cout << endl << "LISTA GENERAL DE POSTULANTES:" << endl;
    cout << left << setw(25) << "Nombre"
         << setw(30) << "Carrera"
         << setw(10) << "Puntaje"
         << setw(10) << "Ranking"
         << setw(15) << "Estado" << endl;
    cout << "---------------------------------------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        cout << left << setw(25) << lista[i].nombre
             << setw(30) << lista[i].carrera
             << setw(10) << lista[i].puntaje
             << setw(10) << lista[i].ranking
             << setw(15) << lista[i].estado << endl;
    }
}
// --------------------------------------------------------------
void mostrarIngresantesPorCarrera(Postulante* lista, int n) {
    if (n == 0) {
        cout << "No hay postulantes registrados." << endl;
        return;
    }

    string carreraBuscada;
    cout << "Ingrese la carrera a consultar: ";
    getline(cin, carreraBuscada);

    bool encontrado = false;
    cout << endl << "Postulantes que ingresaron a " << carreraBuscada << ":" << endl;
    cout << left << setw(25) << "Nombre"
         << setw(10) << "Puntaje"
         << setw(10) << "Ranking" << endl;
    cout << "---------------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        if (lista[i].carrera == carreraBuscada && lista[i].estado == "Ingreso") {
            cout << left << setw(25) << lista[i].nombre
                 << setw(10) << lista[i].puntaje
                 << setw(10) << lista[i].ranking << endl;
            encontrado = true;
        }
    }
    if (!encontrado)
        cout << "No se encontraron ingresantes en esa carrera." << endl;
}

// --------------------------------------------------------------
void liberarMemoria(Postulante*& lista) {
    delete[] lista;
    lista = nullptr;
}
