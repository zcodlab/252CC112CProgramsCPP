#include <iostream>
#include <iomanip>
using namespace std;
const int MAX = 100;

void merge(int* doc, int* hash, int ini, int med, int fin);
void mergeSort(int* doc, int* hash, int ini, int fin);
void buscarPorHash(int* doc, int* hash, int n, int hashBuscado);
void imprimir(int* documentos, int* hashes, int n, const char* titulo);

int main() {
    int documentos[MAX] = {101, 102, 103, 104, 105};
    int hashes[MAX]     = {500, 200, 500, 100, 300};
    int n = 5;
    imprimir(documentos, hashes, n, "Datos Originales");
    mergeSort(documentos, hashes, 0, n - 1);
    imprimir(documentos, hashes, n, "Datos Ordenados por Hash");
    int hashBuscado = 500;
    buscarPorHash(documentos, hashes, n, hashBuscado);
    return 0;
}

void merge(int* doc, int* hash, int ini, int med, int fin) {
    int n = fin - ini + 1;

    int tempDoc[MAX];
    int tempHash[MAX];

    int i = ini;
    int j = med + 1;
    int k = 0;

    while (i <= med && j <= fin) {
        if (*(hash + i) <= *(hash + j)) {
            *(tempDoc + k) = *(doc + i);
            *(tempHash + k) = *(hash + i);
            i++;
        } else {
            *(tempDoc + k) = *(doc + j);
            *(tempHash + k) = *(hash + j);
            j++;
        }
        k++;
    }

    while (i <= med) {
        *(tempDoc +  k) = *(doc + i);
        *(tempHash + k) = *(hash + i);
        i++; k++;
    }

    while (j <= fin) {
        *(tempDoc +  k) = *(doc + j);
        *(tempHash + k) = *(hash + j);
        j++; k++;
    }

    for (int m = 0; m < k; ++m) {
        *(doc + ini + m) = *(tempDoc + m);
        *(hash + ini + m) = *(tempHash + m);
    }
}

void mergeSort(int* doc, int* hash, int ini, int fin) {
    if (ini < fin) {
        int med = (ini + fin) / 2;
        mergeSort(doc, hash, ini, med);
        mergeSort(doc, hash, med + 1, fin);
        merge(doc, hash, ini, med, fin);
    }
}

void buscarPorHash(int* doc, int* hash, int n, int hashBuscado) {
    int inicio = 0, fin = n - 1, pos = -1;

    while (inicio <= fin) {
        int medio = (inicio + fin) / 2;
        if (*(hash + medio) == hashBuscado) {
            pos = medio;
            break;
        } else if (*(hash + medio) < hashBuscado) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }

    if (pos == -1) {
        cout <<endl<<"No se encontraron documentos con hash = " << hashBuscado <<endl;
    } else {
        int i = pos;
        while (i > 0 && *(hash + i - 1) == hashBuscado)
            i--;
        cout <<endl<<"Documentos con hash = " << hashBuscado << ":"<<endl;
        cout << setw(7) << "Indice" << setw(12) << "Documento" << setw(8) << "Hash"<<endl;
        while (i < n && *(hash + i) == hashBuscado) {
            cout  << setw(7) << i << setw(12) << *(doc + i) << setw(8) << *(hash + i)  <<endl;
            ++i;
        }
    }
}

void imprimir(int* documentos, int* hashes, int n, const char* titulo) {
    cout <<endl<< titulo <<endl;
    cout << setw(7) << "Indice" << setw(12) << "Documento" << setw(8) << "Hash"<<endl;
    for (int i = 0; i < n; ++i) {
        cout << setw(7) << i << setw(12) << *(documentos + i) << setw(8) << *(hashes + i) <<endl;
    }
}
