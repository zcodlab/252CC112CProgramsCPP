#include "AreaBajoCurva.h"

AreaBajoCurva::AreaBajoCurva(double a, double b, int n)
    : a(a), b(b), n(n) {}

double AreaBajoCurva::f(double x) const {
    return x * x;   // f(x) = x²
}

double AreaBajoCurva::calcular() const {
    double h = (b - a) / n;
    double suma = 0.0;

    // Regla del rectángulo izquierdo
    for (int i = 0; i < n; ++i) {
        double x = a + i * h;
        suma += f(x);
    }

    return suma * h;
}

std::string AreaBajoCurva::nombre() const {
    return "Area bajo la curva";
}
