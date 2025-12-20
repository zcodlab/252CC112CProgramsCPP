#ifndef METRICAFUNCION_H
#define METRICAFUNCION_H
#include <string>
using namespace std;

class MetricaFuncion {
public:
    virtual double calcular() const = 0;
    virtual string nombre() const = 0;
    virtual ~MetricaFuncion() {}
};

#endif // METRICAFUNCION_H
