#include <iostream>
using namespace std;
const int MAX = 100;
const int R = 2;

// La función devuelve un arreglo de 2 enteros: [0] = sumaTotal, [1] = máximo
void mostrarTriangulo(int arreglo[], int n, int nivel, int resultado[]) {
    cout << "Nivel " << nivel << ": ";
    for (int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
        resultado[0] += arreglo[i];            // acumulamos suma
        if (arreglo[i] > resultado[1])         // buscamos máximo
            resultado[1] = arreglo[i];
    }
    cout << endl;

    // Caso base
    if (n == 1) return;

    // Crear el siguiente nivel
    int siguiente[MAX];
    for (int i = 0; i < n - 1; i++) {
        siguiente[i] = arreglo[i] + arreglo[i + 1];
    }

    // Caso recursivo
    mostrarTriangulo(siguiente, n - 1, nivel + 1, resultado);
}

int main() {
    int arreglo[] = {-3, 1, 2, -4};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);

    int resultado[R];
    resultado[0] = 0;           // suma total inicializada
    resultado[1] = arreglo[0];  // maximo inicial

    cout << "Triangulo de sumas recursivas:" << endl;
    mostrarTriangulo(arreglo, n, 0, resultado);

    cout << endl << "Suma total de todos los niveles: " << resultado[0] << endl;
    cout << "Numero maximo en el triangulo: " << resultado[1] << endl;

    return 0;
}
