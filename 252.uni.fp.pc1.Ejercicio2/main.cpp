#include <iostream>
using namespace std;

// Funcion que verifica si un numero es perfecto
bool esPerfecto(int numero) {
    int suma = 0;
    for (int i = 1; i <= numero / 2; i++) {
        if (numero % i == 0)
            suma += i;
    }
    return suma == numero;
}

// Funcion para encontrar el numero perfecto inferior mas cercano a X
int buscarPerfectoInferior(int perfectos[], int cantidad, int x) {
    int resultado = -1;
    for (int i = 0; i < cantidad; i++) {
        if (perfectos[i] < x)
            resultado = perfectos[i];
    }
    return resultado;
}
void imprimir(int perfectos[], int cantidad){
    for (int i = 0; i < cantidad; i++)
        cout<<perfectos[i]<<" ";
    cout<<endl;
}
int registra_perfectos(int perfectos[], int cantidad, int n,int m){
     for (int i = n; i <= m; i++) {
        if (esPerfecto(i)) {
            perfectos[cantidad] = i;
            cantidad++;
        }
    }
    return cantidad;
}

int main() {
    int N, M;

    // Paso 1: Ingreso del rango
    cout << "Ingrese el limite inferior (N): ";
    cin >> N;
    cout << "Ingrese el limite superior (M): ";
    cin >> M;

    // Validacion simple
    if (N >= M) {
        cout << "El limite inferior debe ser menor que el superior." << endl;
        return 1;
    }

    // Paso 2: Encontrar numeros perfectos y almacenarlos
    int perfectos[M]; // Arreglo fijo con capacidad para hasta 100 numeros perfectos
    int cantidad =  0;
    cantidad=registra_perfectos(perfectos,cantidad,N,M);

    // Paso 3: Mostrar numeros perfectos encontrados
    if (cantidad == 0)
        cout << "No se encontraron numeros perfectos en el rango dado." << endl;
    else {
        cout << "Numeros perfectos encontrados: ";
        imprimir(perfectos,cantidad);

        // Paso 4: Buscar numero perfecto inferior a un valor dado
        int x;
        cout << "Ingrese un numero para buscar el numero perfecto inferior: ";
        cin >> x;

        int resultado = buscarPerfectoInferior(perfectos, cantidad, x);

        if (resultado == -1)
            cout << "No hay numero perfecto inferior a " << x << " en el rango dado." << endl;
        else
            cout << "Numero perfecto inferior mas cercano: " << resultado << endl;
    }

    return 0;
}

