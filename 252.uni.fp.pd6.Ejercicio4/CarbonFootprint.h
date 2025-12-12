#ifndef CARBONFOOTPRINT_H
#define CARBONFOOTPRINT_H
//clase abstracta huella de carbono con 3 funciones virtuales puras
class CarbonFootprint{
public:
    virtual double getCarbonFootprint() const=0;
    virtual void printInfo() const=0;
    virtual ~CarbonFootprint()=default;
};


#endif // CARBONFOOTPRINT_H
