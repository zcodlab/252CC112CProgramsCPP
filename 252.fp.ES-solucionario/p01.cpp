#include <iostream>
using namespace std;

void reordenarParImpar(int*, int); // a) Prototipo

int main() {
    int n = 7;
    int* A = new int[n]{3, 2, 5, 8, 1, 4, 7};

    reordenarParImpar(A, n);

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    delete[] A;
    return 0;
}


// b) Implementación de la función
void reordenarParImpar(int* A, int n) {  
    int pos = 0;                   // indica la posición donde debe colocarse el siguiente número par  

    for (int i = 0; i < n; i++) { // se recorre el arreglo
        if (A[i] % 2 == 0) {      // Si encontramos un número par
            int valorPar = A[i];  
            int j = i;
            while (j > pos) {     // Para preservar el orden, 
                A[j] = A[j - 1];  // desplazamos a la derecha todos los elementos entre pos y i-1
                j--;
            }

            A[pos] = valorPar;   // Insertamos el par en su posición correcta

            pos++;               // Actualizamos la posicion de pares
        }
    }
}

// Complejidad temporal, en el peor caso: impares a la izquierda, pares a la derecha
// tenemos complejidad cuadrática O(n^2)
