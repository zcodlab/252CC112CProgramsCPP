#include <iostream>
using namespace std;

void compactarUnicos(int** arr, int* n) {
    int* original = *arr;
    int tam = *n;

    int contador = 0;

    // Contar los elementos que aparecen solo una vez
    for (int i = 0; i < tam; i++) {
        int veces = 0;
        for (int j = 0; j < tam; j++) {
            if (original[i] == original[j]) {
                veces++;
            }
        }
        if (veces == 1) {
            contador++;
        }
    }

    // Reservar el nuevo arreglo con el tamaño exacto
    int* nuevo = new int[contador];

    // Copiar los elementos únicos
    int k = 0;
    for (int i = 0; i < tam; i++) {
        int veces = 0;
        for (int j = 0; j < tam; j++) {
            if (original[i] == original[j]) {
                veces++;
            }
        }
        if (veces == 1) {
            nuevo[k++] = original[i];
        }
    }

    // Liberar memoria del arreglo original
    delete[] original;
    original = nullptr;   // buena práctica

    // Actualizar puntero y tamaño
    *arr = nuevo;
    *n = contador;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    compactarUnicos(&arr, &n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    arr = nullptr;   // buena práctica

    return 0;
}

/*
Al pasar un puntero simple por valor, la función solo recibe una copia
de la dirección de memoria. Para modificar el puntero original y reasignar memoria 
dinámica correctamente, es necesario un puntero doble (int**) o una referencia a puntero
*/

