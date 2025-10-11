#include <iostream>
using namespace std;

const int M = 4;   // filas
const int N = 5;   // columnas
const int Q = 13;  // módulo entero positivo

// =====================================================
// Mostrar matriz con punteros
// =====================================================
void mostrarMatriz(int** A, const char* nombre) {
    cout << nombre << " (" << M << "x" << N << "):" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << *(*(A + i) + j) << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

// =====================================================
// Mostrar vector con punteros
// =====================================================
void mostrarVector(int* v, int n, const char* nombre) {
    cout << nombre << " = [ ";
    for (int i = 0; i < n; i++) {
        cout << *(v + i);
        if (i < n - 1) cout << " ";
    }
    cout << " ]" << endl;
}

// =====================================================
// (a) Cifrado: b_i = ( S A_ij * s_j + e_i ) mod Q
// =====================================================
void cifrar(int** A, int* s, int* e, int* b) {
    for (int i = 0; i < M; i++) {
        int suma = 0;
        // Sumatoria
        for (int j = 0; j < N; j++) {
            suma = suma + *(*(A + i) + j) * (*(s + j));
        }
        // Aplicar modulo
        *(b + i) = (suma + *(e + i)) % Q;
    }
}

// =====================================================
// (b) Verificacion: (b - e) mod q = (A*s) mod q
// =====================================================
void verificar(int** A, int* s, int* e, int* b) {
    cout <<endl<<"Verificacion (b - e) mod q = (A*s) mod q " << endl;
    for (int i = 0; i < M; i++) {
        int suma = 0;
        for (int j = 0; j < N; j++) {
            suma = suma + *(*(A + i) + j) * (*(s + j));
        }
        int izq = (*(b + i) - *(e + i)) % Q;
        if (izq < 0) izq = izq + Q; // El modulo no puede ser negativo
        int der = suma % Q;

        cout << "Fila " << i << ": (b-e) mod q =" << izq << " , (A*s) mod q =" << der;
        if (izq == der)
            cout << "  es Correcto"<<endl;
        else
            cout << "  es Error"<<endl;
    }
}

// =====================================================
// (c) Error promedio entre cifrado con y sin ruido
// =====================================================
double errorPromedio(int** A, int* s, int* b) {
    double suma = 0, diferencia, promedio;
    for (int i = 0; i < M; i++) {
        int bsr = 0;
        for (int j = 0; j < N; j++) {
            bsr = bsr + *(*(A + i) + j) * (*(s + j));
        }
        bsr = bsr % Q;
        diferencia = abs(*(b + i) - bsr);
        suma = suma + diferencia;
    }

    promedio = (double)suma / M;
    return promedio;
}


// =====================================================
// Programa principal
// =====================================================
int main() {
    int matriz[M][N] = { // Matriz publica (lattice)
        {4, 8, 1, 5, 13},
        {9, 11, 2, 6, 17},
        {7, 12, 3, 10, 15},
        {14, 18, 0, 16, 19}
    };

    // Crear arreglo de punteros a las filas
    int* A[M];
    for (int i = 0; i < M; i++)
        A[i] = matriz[i];

    int s[N] = { 1, 2, 3, 4, 5 }; // Clave privada
    int e[M] = { 1, 3, 2, 4 }; // Ruido aleatorio
    int b[M]; // Vector cifrado (clave publica)

    // Cifrado
    cifrar(A, s, e, b);

    // Mostrar resultados
    cout << "=== Cifrado tipo LWE (Learning With Errors) ==="<<endl<<endl;
    mostrarMatriz(A, "Matriz A");
    mostrarVector(s, N, "Clave privada s");
    mostrarVector(e, M, "Ruido e");
    cout << "Modulo q = " << Q << endl << endl;
    mostrarVector(b, M, "Vector cifrado b");

    // Verificacion
    verificar(A, s, e, b);

    // Error promedio
    double E = errorPromedio(A, s, b);
    cout <<endl<<"Error promedio E = " << E << endl;

    return 0;
}

