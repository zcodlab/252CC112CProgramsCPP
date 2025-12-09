#include <iostream>
#include <cmath>    // sqrt, pow

using namespace std;

class Qubit {
public:
    double alpha; // amplitud de |0>
    double beta;  // amplitud de |1>

    // Constructor con valores por defecto: |0>
    Qubit(double a = 1.0, double b = 0.0) {
        double norma = sqrt(a * a + b * b);
        alpha = a / norma;
        beta = b / norma;
    }
};

// Devuelve la amplitud del estado base "index" (0..2^n-1)
// para un sistema de n qubits almacenados en qubits[]
double amplitud_base(Qubit qubits[], int n, int index) {
    double amp = 1.0;
    int valor = index;

    // Recorremos los qubits de derecha a izquierda
    for (int k = n - 1; k >= 0; k--) {
        int bit = valor % 2;   // 0 o 1
        valor = valor / 2;     // siguiente "bit"

        if (bit == 0)
            amp = amp * qubits[k].alpha;
        else
            amp = amp * qubits[k].beta;
    }

    return amp;
}

// Muestra x en "binario" con n dígitos 0/1, sin operadores de bits
void mostrar_binario(int x, int n) {
    char* bits = new char[n];
    int valor = x;

    for (int pos = n - 1; pos >= 0; pos--) {
        int bit = valor % 2;     // 0 o 1
        valor = valor / 2;
        bits[pos] = (bit == 0) ? '0' : '1';
    }

    for (int i = 0; i < n; i++)
        cout << bits[i];

    delete[] bits;
}

int main() {
    int n;
    cout << "Ingrese el numero de qubits del sistema: ";
    cin >> n;

    if (n <= 0) return 0;

    Qubit* qubits = new Qubit[n];

    // Leer alpha y beta de cada qubit (el constructor normaliza)
    for (int i = 0; i < n; i++) {
        double a, b;
        cout << "\nQubit " << (i + 1) << endl;
        cout << "alpha: ";
        cin >> a;
        cout << "beta : ";
        cin >> b;
        qubits[i] = Qubit(a, b);
    }

    // Mostrar los n qubits normalizados
    cout <<endl<<"Qubits normalizados:"<<endl<<endl;
    for (int i = 0; i < n; i++) {
        double norma2 = qubits[i].alpha * qubits[i].alpha +
            qubits[i].beta * qubits[i].beta;
        cout << "Qubit " << (i + 1) << ": "
            << "alpha = " << qubits[i].alpha
            << ", beta = " << qubits[i].beta
            << "  (alpha^2 + beta^2 = " << norma2 << ")"<<endl;
    }
    cout << endl;

    // Dimension del espacio de estados: 2^n usando pow
    int dim = (int)pow(2.0, n);

    cout <<endl<< "\nEstado total del sistema de " << n << " qubits:"<<endl<<endl;

    for (int i = 0; i < dim; i++) {
        cout << amplitud_base(qubits, n, i);
        cout << "|";
        mostrar_binario(i, n);
        cout << ">";
        if (i < dim - 1) cout << " + ";
        cout << endl;
    }

    delete[] qubits;
    return 0;
}



