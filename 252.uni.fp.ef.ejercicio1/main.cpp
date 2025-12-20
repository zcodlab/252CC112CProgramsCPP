#include <iostream>
#include <cmath>
using namespace std;

int** crearMatrizEnteros(int filas, int columnas);
void liberarMatrizEnteros(int** m, int filas);

double* crearArregloDouble(int n);
void liberarArregloDouble(double* a);

double** crearMatrizDouble(int filas, int columnas);
void liberarMatrizDouble(double** m, int filas);

void leerPuntajes(int** puntajes, int N, int M);
void calcularPromedios(int** puntajes, double* promedio, int N, int M);
void calcularSimilitud(double* promedio, double** sim, int N);
void buscarMasSimilares(double** sim, int N, int& e1, int& e2, double& maxSim);

int main() {
    int N, M;

    cout << "Ingrese numero de estudiantes: ";
    cin >> N;

    cout << "Ingrese numero de tecnologias: ";
    cin >> M;

    int** puntajes = crearMatrizEnteros(N, M);
    double* promedio = crearArregloDouble(N);
    double** sim = crearMatrizDouble(N, N);

    leerPuntajes(puntajes, N, M);
    calcularPromedios(puntajes, promedio, N, M);
    calcularSimilitud(promedio, sim, N);

    int e1, e2;
    double maxSim;
    buscarMasSimilares(sim, N, e1, e2, maxSim);

    cout <<endl<<"Promedios:"<<endl;
    for (int i = 0; i < N; i++) {
        cout << "Promedio estudiante " << i + 1 << ": " << promedio[i] << endl;
    }

    cout <<endl<<"Estudiantes mas similares: "
         << e1 + 1 << " y " << e2 + 1 << endl;
    cout << "Similitud: " << maxSim << endl;

    liberarMatrizEnteros(puntajes, N);
    liberarArregloDouble(promedio);
    liberarMatrizDouble(sim, N);

    return 0;
}


int** crearMatrizEnteros(int filas, int columnas) {
    int** m = new int*[filas];
    for (int i = 0; i < filas; i++) {
        m[i] = new int[columnas];
    }
    return m;
}

void liberarMatrizEnteros(int** m, int filas) {
    for (int i = 0; i < filas; i++) {
        delete[] m[i];
    }
    delete[] m;
}

double* crearArregloDouble(int n) {
    return new double[n];
}

void liberarArregloDouble(double* a) {
    delete[] a;
}

double** crearMatrizDouble(int filas, int columnas) {
    double** m = new double*[filas];
    for (int i = 0; i < filas; i++) {
        m[i] = new double[columnas];
    }
    return m;
}

void liberarMatrizDouble(double** m, int filas) {
    for (int i = 0; i < filas; i++) {
        delete[] m[i];
    }
    delete[] m;
}

void leerPuntajes(int** puntajes, int N, int M) {
    for (int i = 0; i < N; i++) {
        cout <<endl<<"Ingrese puntajes del estudiante " << i + 1 << ":"<<endl;
        for (int j = 0; j < M; j++) {
            cin >> puntajes[i][j];
        }
    }
}

void calcularPromedios(int** puntajes, double* promedio, int N, int M) {
    for (int i = 0; i < N; i++) {
        int suma = 0;
        for (int j = 0; j < M; j++) {
            suma += puntajes[i][j];
        }
        promedio[i] = (double)suma / M;
    }
}

void calcularSimilitud(double* promedio, double** sim, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                sim[i][j] = 1.0;
            } else {
                sim[i][j] = 1.0 - fabs(promedio[i] - promedio[j]) / 4.0;
            }
        }
    }
}

void buscarMasSimilares(double** sim, int N, int& e1, int& e2, double& maxSim) {
    e1 = 0;
    e2 = 1;
    maxSim = sim[0][1];

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (sim[i][j] > maxSim) {
                maxSim = sim[i][j];
                e1 = i;
                e2 = j;
            }
        }
    }
}

