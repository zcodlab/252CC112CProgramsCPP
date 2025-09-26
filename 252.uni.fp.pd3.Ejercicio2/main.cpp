#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main()
{
    string atributos[]={
        "El Bueno",
        "El Grande",
        "El Veridico",
        "El Justo",
        "El Sabio",
        "El Distinguido",
        "El Noble"
    };
    int veces;
    string nombre;
    do{
        cout << "Ingrese el numero de veces que se generara el epitafio [1-5] : ";
        cin>>veces;
    }while(veces<1 || veces>5);
    cout << "Ingrese el nombre y apellido: "<<endl;
    cin.ignore(20,'\n');
    getline(cin,nombre,'\n');
    srand(time(NULL));
    for(int i=0;i<veces;i++){
            int j=rand()%7;
            int k=rand()%7;
            while(j==k)
                k=rand()%7;
            cout<<nombre<<": Se le conocia como "<<atributos[j]
            <<" pero no tan "<<atributos[k].substr(3)<<endl;

    }

    return 0;
}
