#ifndef VARIACIONTOTAL_H
#define VARIACIONTOTAL_H
#include "MetricaFuncion.h"
#include <cmath>

class VariacionTotal : public MetricaFuncion {
private:
    double a, b;
    int n;

    double f(double x) const;

public:
    VariacionTotal(double a, double b, int n);

    double calcular() const override;
    std::string nombre() const override;
};
#endif // VARIACIONTOTAL_H
