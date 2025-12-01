#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int NLECTURAS=5;

struct Sensor {
    int id;
    float* lecturas;
    float promedio;
};

int main() {
    srand(time(nullptr));

    int N;
    cout << "Ingrese el numero de sensores: ";
    cin >> N;

    Sensor* sensores = new Sensor[N]; // 1. asignación dinámica

    for (int i = 0; i < N; i++) {
        sensores[i].id = i + 1;
        sensores[i].lecturas = new float[NLECTURAS];

        float suma = 0;

        for (int j = 0; j < NLECTURAS; j++) { // 2. generacion aleatoria de lecturas
            float lectura = 15.0 + static_cast<float>(rand()) / RAND_MAX * 25.0;
            sensores[i].lecturas[j] = lectura;
            suma += lectura;
        }
        sensores[i].promedio = suma / NLECTURAS; // 3. Calcular promedio
    }

    // 4. Reporte
    cout <<endl<<"=== Reporte de Sensores ==="<<endl<<endl;

    for (int i = 0; i < N; i++) {
        cout << "Sensor " << sensores[i].id << ":"<<endl;
        cout << "Lecturas: ";

        for (int j = 0; j < NLECTURAS; j++)
            cout << sensores[i].lecturas[j] << " ";

        cout <<endl<<"Promedio: "<<sensores[i].promedio<<endl;

        if (sensores[i].promedio >= 30.0)
            cout << "Alerta: Temperatura critica"<<endl<<endl;
        else
            cout << "Estado estable"<<endl<<endl;
    }
    // 5. Liberar memoria dinamica interna y externa
    for (int i = 0; i < N; i++)
        delete[] sensores[i].lecturas;

    delete[] sensores;

    return 0;
}
