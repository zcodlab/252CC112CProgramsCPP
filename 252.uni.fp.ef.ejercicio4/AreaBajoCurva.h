#ifndef AREABAJOCURVA_H_INCLUDED
#define AREABAJOCURVA_H_INCLUDED
#include "MetricaFuncion.h"

class AreaBajoCurva : public MetricaFuncion {
private:
    double a, b;
    int n;

    double f(double x) const;

public:
    AreaBajoCurva(double a, double b, int n);
    double calcular() const override;
    string nombre() const override;
};

#endif // AREABAJOCURVA_H_INCLUDED
