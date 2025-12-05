#include <iostream>
using namespace std;
/*Sobrecarga del operador +*/
class Vector2D{
public:
    int x,y;
    Vector2D(int x,int y): x(x),y(y){}
    //sobrecarga el operador +
    Vector2D operator+(const Vector2D& otro) const{
        return Vector2D(x + otro.x, y + otro.y);
    }

};

int main()
{
    Vector2D a(3,4);
    Vector2D b(1,2);
    Vector2D c=a+b; //sumando dos objetos
    Vector2D d=a.operator+(b);
    cout<<c.x<<","<<c.y<<endl; //imprime(4,6)
    cout<<d.x<<","<<d.y<<endl; //imprime(4,6)

    return 0;
}
