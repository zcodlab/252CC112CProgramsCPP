#ifndef VALORPROMEDIO_H
#define VALORPROMEDIO_H
#include "MetricaFuncion.h"

class ValorPromedio : public MetricaFuncion {
private:
    double a, b;
    int n;

    double f(double x) const;

public:
    ValorPromedio(double a, double b, int n);

    double calcular() const override;
    std::string nombre() const override;
};

#endif // VALORPROMEDIO_H
