#include "ValorPromedio.h"

ValorPromedio::ValorPromedio(double a, double b, int n)
    : a(a), b(b), n(n) {}

double ValorPromedio::f(double x) const {
    return x * x;   // f(x) = x²
}

double ValorPromedio::calcular() const {
    double h = (b - a) / n;
    double suma = 0.0;

    for (int i = 0; i < n; ++i) {
        double x = a + i * h;
        suma += f(x);
    }

    return (suma * h) / (b - a);
}

std::string ValorPromedio::nombre() const {
    return "Valor promedio de la funcion";
}
