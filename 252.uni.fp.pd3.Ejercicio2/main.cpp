#include <iostream>
#include <string>
#include <ctime>
using namespace std;
const int N_ATRIBUTOS=7;
const int N_VECES_MIN=1;
const int N_VECES_MAX=5;
const int SUBSTR_POS=3;
const int N_BYTES_LIMPIEZA=20;

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
    }while(veces<N_VECES_MIN || veces>N_VECES_MAX);
    cout << "Ingrese el nombre y apellido: "<<endl;
    cin.ignore(N_BYTES_LIMPIEZA,'\n');
    getline(cin,nombre,'\n');
    srand(time(NULL));
    for(int i=0;i<veces;i++){
            int j=rand()%N_ATRIBUTOS;
            int k=rand()%N_ATRIBUTOS;
            while(j==k)
                k=rand()%N_ATRIBUTOS;
            cout<<nombre<<": Se le conocia como "<<atributos[j]
            <<" pero no tan "<<atributos[k].substr(SUBSTR_POS)<<endl;

    }

    return 0;
}
