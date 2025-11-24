#include<iostream>
#include<cstdlib>
using namespace std;
struct Lectura{
	int day, month,year;
	float temp;
	};

struct Oficina {
	int id;
	int num_datos;
	Lectura* valores;
	};
int main(){
	const int num_datos=20;
	const int num_oficinas=5;
        int ESTACION[]={1,1,2,2,2,3,3,3,4,4,4,1};
	Oficina * Stn = new Oficina[num_oficinas];
	for(int k=0;k<num_oficinas;k++){
		(Stn+k)->num_datos=num_datos;
		(Stn+k)->id=k+1;
		(Stn+k)->valores = new Lectura[(Stn+k)->num_datos];
		for(int i=0;i<Stn->num_datos;i++){
			((Stn+k)->valores + i)->day = 1+(rand()%30);
			((Stn+k)->valores + i)->month = 1+(rand()%12);
			((Stn+k)->valores + i)->year = 2001+(rand()%25);
			((Stn+k)->valores + i)->temp = 15 + (rand()%26);
		}
	}

	cout<<"Calcule la temperatura promedio y extremas en"<<endl;
	cout<<"\t(1) Verano"<<endl;
	cout<<"\t(2) Otonio"<<endl;
	cout<<"\t(3) Invierno"<<endl;
	cout<<"\t(4) Primavera"<<endl;
	cout<<"\tIngrese opcion: ";
	int est;
	cin>>est;
	float temp_prom=0;
	int cont=0;
	float temp_max=-1;
	float temp_min=100;
        for(int k=0;k<num_oficinas;k++){
            for(int i=0;i<(Stn+k)->num_datos;i++){
                if(ESTACION[((Stn+k)->valores + i)->month ]==est){
                    temp_prom +=	((Stn+k)->valores + i)->temp ;
                    cont++;
                    //actualizamos si es temperatura minima
                    if (((Stn+k)->valores + i)->temp < temp_min)
                        temp_min=((Stn+k)->valores + i)->temp ;
                    //actualizamos si es temperatura maxima
                    if  (((Stn+k)->valores + i)->temp > temp_max)
                        temp_max=((Stn+k)->valores + i)->temp ;
                }
            }
	 }
	 //determinamos la temperatura promedio
     temp_prom=temp_prom/cont;
	cout<<"Temperatura promedio "<<temp_prom<< endl;
	cout<<"Temperatura maxima: "<<temp_max<< endl;
	cout<<"Temperatura minima: "<<temp_min<< endl;
    for(int k=0;k<num_oficinas;k++){
            for(int i=0;i<(Stn+k)->num_datos;i++){
                if(ESTACION[((Stn+k)->valores + i)->month ]==est){
                    if (((Stn+k)->valores + i)->temp == temp_min){
                        cout<<"Oficina "<<(Stn+k)->id
                        <<", Fecha : "
                        <<((Stn+k)->valores + i)->day<<"/"
                        <<((Stn+k)->valores + i)->month<<"/"
                        <<((Stn+k)->valores + i)->year
                        <<" Temp. Minima"<<endl;
                    }else if  (((Stn+k)->valores + i)->temp == temp_max){
                        cout<<"Oficina "<<(Stn+k)->id
                        <<", Fecha : "
                        <<((Stn+k)->valores + i)->day<<"/"
                        <<((Stn+k)->valores + i)->month<<"/"
                        <<((Stn+k)->valores + i)->year
                        <<" Temp. Maxima"<<endl;
                    }
                }
		}
	}

	// Liberar memoria dinamica
    for(int k = 0; k < num_oficinas; k++){
        delete[] (Stn+k)->valores;
    }

    delete[] Stn;
    return 0;
}
