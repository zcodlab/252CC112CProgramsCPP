#include <iostream>
#include <vector>
#include "AreaBajoCurva.h"
#include "ValorPromedio.h"
#include "VariacionTotal.h"

using namespace std;

void crearMetricas(vector<MetricaFuncion*>& v,
                   double a, double b, int n) {
    v.push_back(new AreaBajoCurva(a, b, n));
    v.push_back(new ValorPromedio(a, b, n));
    v.push_back(new VariacionTotal(a, b, n));
}

void mostrarResultados(const vector<MetricaFuncion*>& v) {
    cout << "Resultados:\n\n";
    for (const MetricaFuncion* m : v) {
        cout << m->nombre()
             << " = "
             << m->calcular()
             << endl;
    }
}

void liberarMemoria(vector<MetricaFuncion*>& v) {
    for (MetricaFuncion* m : v)
        delete m;
    v.clear();
}

int main()
{
    double a = 0.0, b = 2.0;
    int n = 100;

    vector<MetricaFuncion*> metricas;

    crearMetricas(metricas, a, b, n);
    mostrarResultados(metricas);
    liberarMemoria(metricas);
    return 0;
}
