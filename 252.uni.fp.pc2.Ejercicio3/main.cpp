#include <iostream>
#include <cmath>
using namespace std;
const int MAX=10;
const int MAX_NOTA=20;

void genera_notas(int* notas,int n){
	int* p=notas;
	for (int i=0;i<n;i++){
		*(p++) = rand()%(MAX_NOTA+1);
	}
}
float nota_media_muestra(int* notas,int n){
	float yp=0;
	int *p;
	p=notas;
	for (int i=0;i<n;i++){
		yp +=*(p++);
	}
	yp=yp/n;
	p=notas;
	int ym=*p;
	for (int i=0;i<n;i++){
		if (abs(*p-yp)<abs(ym-yp)){
			ym=*p;
		}
		p++;
	}
	return ym;
}

float desv_muestra(int* notas,int n){
	float y=0,sumy=0,sumy2=0;
	int *p;
	p=notas;
	for (int i=0;i<n;i++){
		float x=*(p++);
		sumy +=x;
		sumy2 +=pow(x,2.0);
	}
	y= sqrt( (n*sumy2 - pow(sumy,2.0))/(n*(n-1)));
	return y;
}
void cambia_valores(int* notas,int n, float desv,int ym){
	int* p=notas;
	for (int i=0;i<n;i++){
		if (abs(*p-ym)>0.5*desv)
			*p=ym;
		p++;
	}
}
void imprime_notas(int* notas,int n){
	int* p=notas;
	for (int i=0;i<n;i++){
		cout<<*p++<<"\t";
	}
	cout<<endl;
}
int main(){
	int n=MAX;
	int notas[MAX];
	genera_notas(notas,n);
	float desv =desv_muestra(notas, n);
	int ym = nota_media_muestra(notas, n);
	cout<<"Desv Est: "<<desv<<"\tValor central: "<<ym<<endl;
	cout<<"Notas originales"<<endl;
	imprime_notas(notas, n);
	cambia_valores(notas,n,desv,ym);
	cout<<"Notas modificadas"<<endl;
	imprime_notas(notas, n);
}
