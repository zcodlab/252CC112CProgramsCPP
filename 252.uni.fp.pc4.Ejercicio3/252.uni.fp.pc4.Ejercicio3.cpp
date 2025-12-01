#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
struct Fecha {
	int dia;
	int mes;
	int anio;
};
struct Empleado {
	int id;
	char nombre[40];
	float remuneracion;
	Fecha FechaIngreso;
	bool activo;
};
struct Cesante {
	int id;
	char nombre[40];
	float CTS;
	Fecha FechaIngreso;
	Fecha FechaCese;
};
// Función para calcular la diferencia en meses entre dos fechas
Fecha calcularTiempoTrabajado(const Fecha& ingreso, const Fecha& cese) {
	int anios;
	int meses;
	int dias;
	Fecha duracion;
	anios = max(cese.anio-ingreso.anio-1,0);
	meses = (12-ingreso.mes) + (cese.mes-1);
	dias = (31-ingreso.dia) + (cese.dia);
	if (dias>30){
		meses++;
		dias-=30;
	}
	if (meses>=12){
		meses-=12;
		anios++;
	}
	duracion.dia = dias;
	duracion.mes = meses;
	duracion.anio = anios;
	return duracion;
}

// Funcion para calcular la CTS
float calcularCTS(float remuneracion, Fecha duracion) {
	float CTS;
	CTS = duracion.anio*remuneracion;
	if (duracion.mes>=6 && duracion.dia>0)
		CTS += remuneracion;
	else
		CTS += remuneracion*(duracion.mes/12.0f + duracion.dia/360.0f);
	return CTS;
}
// Funcion para generar datos de ejemplo
void escribirArchivoEmpleado(const string& nombre_archivo) {
	ofstream archivo(nombre_archivo, ios::binary | ios::out);
	if (!archivo.is_open()) {
		cerr << "Error al abrir el archivo: " << nombre_archivo << endl;
		return;
	}
	int n=11;
	Empleado emp[n] = { {1,"Andres",4500.0,{2,1,2010},true},
		{2,"Luis",3500.0,{4,2,2006},true},{3,"Cesar",5000.0,{12,11,2006},true},
		{4,"Esteban",4300.0,{3,3,2009},false},{5,"Carla",6500.0,{22,10,2007},false},
		{6,"Ana",4700.0,{5,4,2011},true},{7,"Julio",4000.0,{20,9,2009},false},
		{8,"Laura",3800.0,{7,5,2012},true},{9,"Cecilia",4100.0,{11,8,2018},false},
		{10,"Brian",3500.0,{10,6,2015},true},{11,"Pedro",4700.0,{15,7,2017},true}	};

	archivo.write(reinterpret_cast<const char*>(&n), sizeof(int));
	// Escribir cada persona en el archivo binario
	for (int i = 0; i < n; i++) {
		archivo.write(reinterpret_cast<const char*>(&emp[i]), sizeof(Empleado));
		// Verificar si la escritura fue exitosa
		if (!archivo.good()) {
			cout << "Error al escribir la persona " << i << endl;
			break;
		}
	}
	archivo.close();
	cout << "Datos escritos exitosamente en " << nombre_archivo << endl;
}

void leerEmpleados(const string& nombreArchivo,Empleado*& empleados, int &n) {
	ifstream archivo(nombreArchivo, ios::binary);
	if (!archivo.is_open()) {
		cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << endl;
		empleados=nullptr;
		n=0;
		return;
	}
	archivo.read(reinterpret_cast<char*>(&n), sizeof(int));
	empleados = new Empleado[n];
	cout << "Leyendo "<<n<<" empleados desde el archivo binario..." << endl;
	Empleado emp;
	for(int i=0;i<n;i++){
		archivo.read(reinterpret_cast<char*>(&emp), sizeof(Empleado));
		empleados[i]=emp;
	}
	archivo.close();
	return;
}

Fecha solicitarFechaCese() {
	Fecha cese;
	char guion;
	cout << "FECHA DE CESE (dd-mm-yyyy) : ";
	cin >>  cese.dia>>guion>> cese.mes >>guion>> cese.anio;
	return cese;
}

void creaCesantes(Empleado* empleados, int n,Cesante* &cesantes,int &numCesantes) {
	Cesante* ptr_ces;
	Fecha fechaCese;
	numCesantes=0;
	for(int i=0;i<n;i++){
		if (!empleados[i].activo)
			numCesantes++;
	}
	cesantes = new Cesante[numCesantes];
	ptr_ces = cesantes;
	cout <<endl << string(80, '=') << endl;
	cout << "INGRESE FECHA DE CESE DEL PERSONAL NO ACTIVO" << endl;
	cout << string(80, '=') << endl;
	for(int i=0;i<n;i++){
		Empleado emp = empleados[i];
		if (!emp.activo){
			cout<<"Cesante "<<emp.id<<"\t";
			fechaCese = solicitarFechaCese();
			Fecha duracion = calcularTiempoTrabajado(emp.FechaIngreso, fechaCese);
			float cts = calcularCTS(emp.remuneracion, duracion);

			ptr_ces->id = emp.id;
			strcpy(ptr_ces->nombre,emp.nombre);
			ptr_ces->CTS = cts;

			ptr_ces->FechaIngreso = emp.FechaIngreso;
			ptr_ces->FechaCese = fechaCese;
			ptr_ces++;
		}
	}
}
void generaReporteCTS(Cesante* cesantes,int numCesantes) {
		float totalCTS = 0;
		cout <<endl<< string(80, '=') << endl;
		cout << "INFORME DE COMPENSACION POR TIEMPO DE SERVICIOS (CTS)" << endl;
		cout << string(80, '=') << endl;

		cout << left << setw(5) << "ID"
		<< setw(25) << "NOMBRE"
		<< setw(15) << "FECHA INGRESO"
		<< setw(15) << "FECHA CESE"
		<< setw(15) << "CTS" << endl;
		cout << string(80, '-') << endl;

		for (int i=0;i<numCesantes;i++){
			Cesante ces = cesantes[i];
			totalCTS += ces.CTS;
			cout << left << setw(5) << ces.id
				<< setw(25) << ces.nombre
				<< setw(2) << ces.FechaIngreso.dia << "/"
				<< setw(2) << ces.FechaIngreso.mes << "/"
				<< setw(11) << ces.FechaIngreso.anio

				<< setw(2) << ces.FechaCese.dia << "/"
				<< setw(2) << ces.FechaCese.mes << "/"
				<< setw(11) << ces.FechaCese.anio
				<< "S/." << setw(12) << fixed << setprecision(2) << ces.CTS << endl;
		}
		cout << string(80, '-') << endl;
		cout << right << setw(65) << "TOTAL CTS: S/." << fixed << setprecision(2) << totalCTS << endl;
		cout << string(80, '=') << endl;
}

void escribirArchivoCesantes(const string& nombre_archivo,Cesante* cesantes,int numCesantes) {
	ofstream archivo(nombre_archivo, ios::binary | ios::out);

	if (!archivo.is_open()) {
		cerr << "Error al abrir el archivo: " << nombre_archivo << endl;
		return;
	}
	archivo.write(reinterpret_cast<const char*>(&numCesantes), sizeof(int));
	// Escribir cada persona en el archivo binario
	for (int i = 0; i < numCesantes; i++) {
		Cesante& ces = cesantes[i];
		archivo.write(reinterpret_cast<const char*>(&ces), sizeof(Empleado));
		// Verificar si la escritura fue exitosa
		if (!archivo.good()) {
			cout << "Error al escribir la persona " << i << endl;
			break;
		}
	}
	archivo.close();
	cout << "Datos escritos exitosamente en " << nombre_archivo << endl;
}
int main(){
	Empleado* empleados;
	Cesante* cesantes;
	int numEmpleados;
	int numCesantes;
	escribirArchivoEmpleado("empleados.info");
	leerEmpleados("empleados.info",empleados,numEmpleados);
	creaCesantes(empleados, numEmpleados, cesantes,numCesantes) ;
	generaReporteCTS(cesantes,numCesantes) ;
	escribirArchivoCesantes("cesantes.info",cesantes,numCesantes);
	delete[] empleados;
	delete[] cesantes;
}
