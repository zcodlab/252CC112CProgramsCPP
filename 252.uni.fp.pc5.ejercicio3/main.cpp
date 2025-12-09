#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
const int MAX_NUM_TRANSACCION=5;
struct Transaccion {
	char tipo;  // 'D'=Depósito, 'R'=Retiro
	float monto;
};
class CuentaLimitada {
private:
	int numeroCuenta;
	char* titular;
	float saldo;
	Transaccion* historial;
	int numTransacciones;
	int capacidadHistorial;

public:
	CuentaLimitada(int,const char* );
	~CuentaLimitada();
	// Métodos de la clase
	bool depositar(float monto);
	bool retirar(float monto);
	void mostrarInformacion() const;
	void mostrarHistorial() const;
	bool agregarTransaccion(char tipo, float monto);

};
CuentaLimitada::CuentaLimitada(int numeroCuenta,const char* titular){
	this->numeroCuenta=numeroCuenta;
	this->titular = new char[strlen(titular) + 1];
	strcpy(this->titular,titular);
	this->saldo=0;
	this->numTransacciones=0;
	this->capacidadHistorial=MAX_NUM_TRANSACCION;
	this->historial = new Transaccion[capacidadHistorial];
}

// Destructor
CuentaLimitada::~CuentaLimitada() {
	delete[] titular;
	delete[] historial;
}
bool CuentaLimitada::agregarTransaccion(char tipo, float monto) {
	if (this->numTransacciones >= this->capacidadHistorial) {
		cout<<"Alcanzo el maximo numero de transacciones"<<endl;
		return false;
	}
	// Crear y agregar transacción usando 'this->' explícitamente
	this->historial[this->numTransacciones].monto=monto;
	this->historial[this->numTransacciones].tipo=tipo;
	this->numTransacciones++;
	return true;
}
bool CuentaLimitada::depositar(float monto) {
	if (monto <= 0) {
		cout << "Error: Monto a depositar debe ser positivo" << endl;
		return false;
	}
	// Registrar transacción
	if (!this->agregarTransaccion('D', monto)){
		return false;
	}
	this->saldo += monto;
	cout << setw(20)<<"Deposito exitoso: +" << monto
	<< " | Saldo actual: " << this->saldo << endl;
	return true;
}
bool CuentaLimitada::retirar(float monto) {
	if (monto <= 0) {
		cerr << "Error: Monto a retirar debe ser positivo" << endl;
		return false;
	}
	// Verificar fondos suficientes
	if (monto > this->saldo) {
		cerr << "Error: Fondos insuficientes. Saldo: "
		<< this->saldo << ", Intento: " << monto << endl;
		return false;
	}
	// Registrar transacción
	if (!this->agregarTransaccion('R', monto)){
		return false;
	}
	this->saldo -= monto;
	cout << setw(20)<<"Retiro exitoso: -" << monto
	<< " | Saldo actual: " << this->saldo << endl;
	return true;
}
void CuentaLimitada::mostrarInformacion() const {
	cout <<endl<< "=== INFORMACION DE CUENTA ===" << endl;
	cout << "Numero de cuenta: " << this->numeroCuenta << endl;
	cout << "Titular: " << this->titular << endl;
	cout << "Saldo actual: $" << this->saldo << endl;
	cout << "Transacciones registradas: " << this->numTransacciones << endl;
	cout << "=============================" << endl;
}

void CuentaLimitada::mostrarHistorial() const {
	cout <<endl<<"=== HISTORIAL DE TRANSACCIONES ===" << endl;
	cout << "Cuenta: " << this->numeroCuenta << " - " << this->titular << endl;
	cout << string(50, '-') << endl;

	if (this->numTransacciones == 0) {
		cout << "No hay transacciones registradas" << endl;
		return;
	}

	cout << setw(10)<<"Tipo"<<setw(10)<<"Monto"<<endl;
	cout << string(50, '-') << endl;

	for (int i = 0; i < this->numTransacciones; i++) {
		const Transaccion& t = this->historial[i];
		string tipoStr;
		switch (t.tipo) {
			case 'D': tipoStr = "Deposito"; break;
			case 'R': tipoStr = "Retiro";  break;
			break;
		}
	    cout <<setw(10)<<tipoStr<<setw(10)<<t.monto << endl;
	}

	cout << string(50, '-') << endl;
	cout << "Saldo final: $" << this->saldo << endl;
}

void testCuenta() {
	CuentaLimitada cuenta(1,"Juan Perez");

	cuenta.depositar(200.0);
	cuenta.retirar(300.0);
	cuenta.depositar(300.0);
	cuenta.retirar(100.0);
	cuenta.retirar(200.0);
	cuenta.depositar(300.0);
	cuenta.depositar(100.0);

	cuenta.mostrarInformacion();
	cuenta.mostrarHistorial();
}
int main(){
	testCuenta();
}
