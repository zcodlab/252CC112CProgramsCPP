#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const int MAX=100;
const float MAX_PIXEL_VALUE=255.0;
const int filas = 4, columnas = 5;
const int kSize = 3;

//Mostrar matriz usando aritmetica de punteros
void mostrarMatriz(const char* titulo, int **matriz, int filas, int columnas) {
    cout << endl << titulo << ":" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++)
            cout << setw(5) << *(*(matriz + i) + j);
        cout << endl;
    }
}

//Aplicar convolucion con punteros
void aplicarConvolucion(int **imagen, int filas, int columnas, int **kernel, int kSize, int **resultado) {
    int offset = kSize / 2;

    for (int i = offset; i < filas - offset; i++) {
        for (int j = offset; j < columnas - offset; j++) {
            int suma = 0;
            for (int ki = 0; ki < kSize; ki++) {
                for (int kj = 0; kj < kSize; kj++) {
                    int x = i + ki - offset;
                    int y = j + kj - offset;
                    suma += *(*(imagen + x) + y) * *(*(kernel + ki) + kj);
                }
            }
            *(*(resultado + i) + j) = suma;
        }
    }
}

//Normalizar valores al rango [0,255]
void normalizar(int **matriz, int filas, int columnas, int kSize) {
    int offset = kSize / 2;

    int minVal = *(*(matriz + offset) + offset);
    int maxVal = minVal;

    // Buscar min y max solo en la zona interior
    for (int i = offset; i < filas - offset; i++) {
        for (int j = offset; j < columnas - offset; j++) {
            int val = *(*(matriz + i) + j);
            if (val < minVal) minVal = val;
            if (val > maxVal) maxVal = val;
        }
    }
    /*El incremento maxVal++ no busca precision, sino estabilidad numerica.
    Evita division por cero, solo aplica a caso imagen blanca o negra*/
    if (maxVal == minVal) maxVal++;
    // Normalizar solo la zona interior
    for (int i = offset; i < filas - offset; i++) {
        for (int j = offset; j < columnas - offset; j++) {
            int val = *(*(matriz + i) + j);
            val = (int)round(MAX_PIXEL_VALUE * (val - minVal) / (maxVal - minVal));
            *(*(matriz + i) + j) = val;
        }
    }
}


//Programa principal
int main() {
    int imagen_estatica[filas][columnas] = {
        {10, 10, 10, 10, 10},
        {10, 255, 255, 255, 10},
        {10, 255, 10, 255, 10},
        {10, 10, 10, 10, 10}
    };
    int kernel_estatico[kSize][kSize] = {
        {-1, -1, -1},
        {-1,  8, -1},
        {-1, -1, -1}
    };
    int resultado_estatico[filas][columnas] = {0};

    // Crear punteros dobles
    int *imagen_ptr[filas];
    int *kernel_ptr[kSize];
    int *resultado_ptr[filas];

    for (int i = 0; i < filas; i++) {
        *(imagen_ptr + i) = *(imagen_estatica + i);
        *(resultado_ptr + i) = *(resultado_estatico + i);
    }
    for (int i = 0; i < kSize; i++)
        *(kernel_ptr + i) = *(kernel_estatico + i);

    // Mostrar imagen original
    mostrarMatriz("Imagen original", imagen_ptr, filas, columnas);
    // Mostrar kernel
    mostrarMatriz("Kernel aplicado", kernel_ptr, kSize, kSize);

    // Aplicar convolucion y normalizar
    aplicarConvolucion(imagen_ptr, filas, columnas, kernel_ptr, kSize, resultado_ptr);
    // Mostrar resultado sin normalizar
    mostrarMatriz("Resultado de la convolucion (sin normalizar)", resultado_ptr, filas, columnas);
    // Normalizando
    normalizar(resultado_ptr, filas, columnas, kSize);
    // Mostrar resultado
    mostrarMatriz("Resultado de la convolucion (normalizado 0-255)", resultado_ptr, filas, columnas);
    return 0;
}
