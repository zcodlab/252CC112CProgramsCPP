#include <iostream>
#include <iomanip>
using namespace std;
const int N = 12; // 12 meses
const int K = 4; // 4 socios
void imprime_particion(int particion[],int ingresos[]){
	int j0=0;
	cout << "Distribucion de meses por socio:"<<endl;
	for (int i = 0; i < K; i++)
		cout <<setw(6) << particion[i];
	cout<<endl;

	cout<<"Ingreso por socio:"<<endl;
	for (int i = 0; i < K; i++) {
		int ingreso=0;
		for (int j = j0; j < particion[i]+j0; j++)
			ingreso+=ingresos[j];
		j0+=particion[i];
		cout<<setw(6) <<ingreso;
	}
	cout<<endl;
}
// Funcion que verifica si es posible dividir entre 4 grupos de meses
bool esPosible(int ingresos[], int n, int mid,int aux[]) {
	int grupos = 0;
	int suma = 0;
	int len = 0;
	int i = 0;
	while (i < n && grupos <K) {
		suma += ingresos[i];
		len++;
		i++;
		if (suma >= mid) {
			aux[grupos]=len;
			grupos++;
			len=0;
			suma = 0; // asignamos al siguiente socio
		}
	}
	return (grupos >= K);
}
int busqueda_binaria(int ingresos[],int particion[]){
	int low = 0;
	int high = 0;
	for (int i = 0; i < N; i++) high += ingresos[i];
	int ans = 0;
	int aux[K];
	while (low <= high) {
		int mid = (low + high) / 2;
		if (esPosible(ingresos, N, mid,aux)) {
			for(int i=0;i<K;i++) particion[i]=aux[i];
			ans = mid;        // mid es posible, intentamos uno mayor
			low = mid + 1;
		} else
			high = mid - 1;   // mid es muy alto, reducimos
	}
	return ans;
}
int main() {
	int PROD[N] = {7,2,5,10,8,7,2,5,10,8,7,2};
	int PRECIO[N]     = {3,4,4,3,3,4,4,4,4,3,3,1};
	int ingresos[N];
	// Calcular ingresos por mes
	for (int i = 0; i < N; i++)
		ingresos[i] = PROD[i] *  PRECIO[i];

	int particion[K];
	int max_minimo;
	// Búsqueda binaria sobre los ingresos
	max_minimo=busqueda_binaria(ingresos,particion);
	if (max_minimo == 0)
		cout << "No es posible realizar una particion valida."<<endl;
	else {
		// verificamos si se asignaron todos los meses
		int meses_ocupados=0;
		for (int i = 0; i < K; i++)
			meses_ocupados+= particion[i];
		//los meses restantes se asignan al ultimo socio
		particion[K-1]+=N-meses_ocupados;
		cout << "Ingreso minimo maximo: " << max_minimo << endl;
		imprime_particion(particion,ingresos);
	}
}

