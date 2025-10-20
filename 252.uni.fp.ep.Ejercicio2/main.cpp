#include <iostream>
#include <iomanip>
using namespace std;
const int MAX = 20;

double energiaPromedio(double*, int);
void diferenciasCentradas(double*, double*, int);
void normalizacionCascada(double*, int);
void imprimirResultados(double*, double*, double*, double, int);

int main() {
    double E[MAX] = {2, 3, 5, 7, 6};
    double D[MAX] = {0.0};
    double E_original[MAX];
    int n = 5;
    for (int i = 0; i < n; i++)
        E_original[i] = E[i];

    double promedio = energiaPromedio(E, n);
    diferenciasCentradas(E, D, n);
    normalizacionCascada(E, n);
    imprimirResultados(E_original, D, E, promedio, n);
    return 0;
}

double energiaPromedio(double *E, int n) {
    double suma = 0.0;
    for (double *p = E; p < E + n; p++)
        suma += *p;
    return suma / n;
}

void diferenciasCentradas(double *E, double *D, int n) {
    for (int i = 1; i < n - 1; i++)
        D[i] = (*(E + i + 1) - *(E + i - 1)) / 2.0;
}

void normalizacionCascada(double *E, int n) {
    double emin = *E, emax = *E;
    for (double *p = E + 1; p < E + n; p++) {
        if (*p < emin) emin = *p;
        if (*p > emax) emax = *p;
    }

    for (double *p = E; p < E + n; p++)
        *p = (*p - emin) / (emax - emin);

    double suma = 0.0;
    for (double *p = E; p < E + n; p++)
        suma += *p;
    for (double *p = E; p < E + n; p++)
        *p /= suma;
}

void imprimirResultados(double *E_original, double *D, double *E, double promedio, int n) {
    cout << fixed << setprecision(3);
    cout <<endl<<"Indice | E_original | D_centrada | E_normalizada"<<endl;
    cout << "-----------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << setw(6) << i << " | "
             << setw(10) << *(E_original + i) << " | "
             << setw(10) << *(D + i) << " | "
             << setw(10) << *(E + i) << endl;
    }
    cout <<endl<<"Energia promedio = " << promedio << endl;
}
