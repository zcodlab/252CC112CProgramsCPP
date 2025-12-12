#ifndef BICYCLE_H
#define BICYCLE_H
#include "CarbonFootprint.h"
class Bicycle: public CarbonFootprint{
private:
    double maintenanceHours;   //Horas de mantenimiento
public:
    Bicycle(double hours);
    double getCarbonFootprint() const override;
    void printInfo() const override;
};

#endif // BICYCLE_H
