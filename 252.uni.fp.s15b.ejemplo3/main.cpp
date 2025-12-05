#include <iostream>
using namespace std;
class Funcion{
public:
    int operator()(int x){
        return x*x;
    }
};

int main()
{
    Funcion f;
    cout<<f(5)<<endl;
    cout<<f.operator()(5)<<endl;

    return 0;
}
