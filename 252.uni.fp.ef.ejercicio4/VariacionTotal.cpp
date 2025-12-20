#include "VariacionTotal.h"

VariacionTotal::VariacionTotal(double a, double b, int n)
    : a(a), b(b), n(n) {}

double VariacionTotal::f(double x) const {
    return x * x;   // f(x) = x²
}

double VariacionTotal::calcular() const {
    double h = (b - a) / n;
    double variacion = 0.0;

    for (int i = 0; i < n - 1; ++i) {
        double x1 = a + i * h;
        double x2 = x1 + h;
        variacion += std::fabs(f(x2) - f(x1));
    }

    return variacion;
}

std::string VariacionTotal::nombre() const {
    return "Variacion total de la funcion";
}
