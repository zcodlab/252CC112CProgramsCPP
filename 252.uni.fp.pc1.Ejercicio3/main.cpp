#include <iostream>
using namespace std;
const int MAX = 100;

void combinar(int arreglo[], int inicio, int medio, int fin) {
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;

    int izquierda[MAX], derecha[MAX];

    for (int i = 0; i < n1; i++)
        izquierda[i] = arreglo[inicio + i];
    for (int j = 0; j < n2; j++)
        derecha[j] = arreglo[medio + 1 + j];

    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        if (izquierda[i] <= derecha[j])
            arreglo[k++] = izquierda[i++];
        else
            arreglo[k++] = derecha[j++];
    }
    while (i < n1) arreglo[k++] = izquierda[i++];
    while (j < n2) arreglo[k++] = derecha[j++];
}

void mergeSort(int arreglo[], int inicio, int fin) {
    if (inicio < fin) {
        int medio = (inicio + fin) / 2;
        mergeSort(arreglo, inicio, medio);
        mergeSort(arreglo, medio + 1, fin);
        combinar(arreglo, inicio, medio, fin);
    }
}

int contarFrecuencia(int arreglo[], int n, int valor) {
    int contador = 0;
    for (int i = 0; i < n; i++) {
        if (arreglo[i] == valor) contador++;
    }
    return contador;
}

void ordenarPorFrecuencia(int arreglo[], int n, int indice = 0) {
    if (indice >= n - 1) return;

    int maxFrecuencia = contarFrecuencia(arreglo, n, arreglo[indice]);
    int posMax = indice;

    for (int j = indice + 1; j < n; j++) {
        int freq = contarFrecuencia(arreglo, n, arreglo[j]);
        if (freq > maxFrecuencia || (freq == maxFrecuencia && arreglo[j] < arreglo[posMax])) {
            maxFrecuencia = freq;
            posMax = j;
        }
    }

    int temp = arreglo[indice];
    arreglo[indice] = arreglo[posMax];
    arreglo[posMax] = temp;

    ordenarPorFrecuencia(arreglo, n, indice + 1);
}
void imprimir(int arreglo[], int n){
    for (int i = 0; i < n; i++) cout << arreglo[i] << " ";
     cout <<endl;
}

int main() {
    int arreglo[] = {4, 1, 2, 2, 3, 4, 4, 1};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);
    cout << "Arreglo original:"<<endl;
    imprimir(arreglo,n);
    mergeSort(arreglo, 0, n - 1);
    cout << "Arreglo ordenado ascendentemente:"<<endl;
    imprimir(arreglo,n);
    ordenarPorFrecuencia(arreglo, n);
    cout << "Arreglo reordenado por frecuencia:"<<endl;
    imprimir(arreglo,n);

    return 0;
}

