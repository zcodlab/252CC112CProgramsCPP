#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Estructura que almacena un partido y sus votos acumulados
struct Partido {
    string nombre;
    long votos;
    int ranking;
};

// Lee un registro del archivo con formato: partido;departamento;votos
void leerRegistro(ifstream& ar, string& partido,
                  string& departamento, int& votos) {
    string cadena;

    getline(ar, cadena, ';'); // partido
    partido = cadena;

    getline(ar, cadena, ';'); // departamento
    departamento = cadena;

    getline(ar, cadena);      // votos
    if (cadena.size() > 0)
        votos = stoi(cadena);
    else
        votos = 0;
}

// Busca la posicion del partido en el arreglo
int buscarPartido(Partido* lista, int n, const string& nombre) {
    for (int i = 0; i < n; i++)
        if (lista[i].nombre == nombre) return i;

    return -1;
}

// Agrega un partido si no existe aun
void agregarPartido(Partido*& lista, int& n, const string& nombre) {
    // Verificar si ya existe
    for (int i = 0; i < n; i++)
        if (lista[i].nombre == nombre) return;

    // Crear arreglo nuevo
    Partido* nuevo = new Partido[n + 1];

    for (int i = 0; i < n; i++)
        nuevo[i] = lista[i];

    nuevo[n].nombre = nombre;
    nuevo[n].votos = 0;

    delete[] lista;
    lista = nuevo;
    n++;
}
// Ordenar por votos descendente
void ordenar(Partido* lista, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (lista[j].votos > lista[i].votos)
                swap(lista[i], lista[j]);
        }
    }
}

void asignarRanking(Partido* lista, int n) {
    long prev = -1;
    int ranking = 1;
    int pos = 1;

    for (int i = 0; i < n; i++) {
        if (lista[i].votos != prev)
            ranking = pos;
        lista[i].ranking = ranking;
        prev = lista[i].votos;
        pos++;
    }
}

// Guardar resultados en archivo
void guardarResultados(const char* archivo, Partido* lista, int n) {
    ofstream ar(archivo);
    if (!ar.is_open()) {
        cout << "No se pudo crear archivo de salida" << endl;
        return;
    }
    ar << "RESULTADOS NACIONALES ELECCIONES 2026" << endl << endl;
    ar << "Ranking final:" << endl;
    // Se imprime el ranking completo
    for (int i = 0; i < n; i++) {
        ar << lista[i].ranking << ". "
           << lista[i].nombre << " - "
           << lista[i].votos << " votos" << endl;
    }
    ar << endl;
    ar << "Pasan a segunda vuelta:" << endl;
    // Como la lista ya esta ordenada, solo se imprimen rankings 1 y 2
    for (int i = 0; i < n; i++) {

        if (lista[i].ranking <= 2) {
            ar << lista[i].nombre
               << " - " << lista[i].votos
               << " votos (ranking " << lista[i].ranking << ")"
               << endl;
        }
        else
            // En cuanto aparece un ranking mayor a 2, se termina
            break;
    }
    ar.close();
}


// Programa principal
int main() {
    ifstream ar("votos.txt");
    if (!ar.is_open()) {
        cout << "No se pudo abrir datos.txt" << endl;
        return 1;
    }
    Partido* partidos = nullptr;
    int numPartidos = 0, votos;
    string partido, departamento;
    // leer, agregar partido y acumular votos
    while (true) {
        leerRegistro(ar, partido, departamento, votos);
        if (ar.fail()) break;
        // Agregar si no existe
        agregarPartido(partidos, numPartidos, partido);
        // Buscar posicion
        int pos = buscarPartido(partidos, numPartidos, partido);
        // Acumular votos
        if (pos != -1)
            partidos[pos].votos += votos;
    }
    ar.close();
    // Ordenar por votos
    ordenar(partidos, numPartidos);
    // Asignar Ranking
    asignarRanking(partidos, numPartidos);
    // Guardar archivo de salida
    guardarResultados("resultado.txt", partidos, numPartidos);
    cout << "Procesamiento completado. Ver resultado.txt" << endl;
    delete[] partidos;
    return 0;
}

