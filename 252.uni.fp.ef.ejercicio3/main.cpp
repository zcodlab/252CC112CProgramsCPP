#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_DIAS = 31;
const int MAX_USUARIOS = 50;

struct Usuario {
    string nombre;
    int total;
    int ok;
    int fail;
    string* dias;
    int* conteoDias;
    int cantDias;

    Usuario() : total(0), ok(0), fail(0), cantDias(0) {
        dias = new string[MAX_DIAS];
        conteoDias = new int[MAX_DIAS];
        for (int i = 0; i < MAX_DIAS; ++i) {
            conteoDias[i] = 0;
        }
    }

    ~Usuario() {
        delete[] dias;
        delete[] conteoDias;
    }
};

int buscarUsuario(Usuario** usuarios, int cant, string nombre) {
    for (int i = 0; i < cant; i++) {
        if (usuarios[i]->nombre == nombre)
            return i;
    }
    return -1;
}

int buscarDia(Usuario& u, string dia) {
    for (int i = 0; i < u.cantDias; i++) {
        if (u.dias[i] == dia)
            return i;
    }
    return -1;
}

int main() {
    ifstream archivo("accesos.log");
    if (!archivo) {
        cout << "Error al abrir accesos.log"<<endl;
        return 1;
    }

    Usuario* usuarios[MAX_USUARIOS];
    int cantUsuarios = 0;
    string linea;

    while (getline(archivo, linea)) {
    	if (linea.empty()) continue;

        int p1 = linea.find(';');
        int p2 = linea.find(';', p1 + 1);
        int p3 = linea.find(';', p2 + 1);

        string nombre = linea.substr(0, p1);
        string fechaHora = linea.substr(p1 + 1, p2 - p1 - 1);
        string evento = linea.substr(p3 + 1);

        string fecha = fechaHora.substr(0, 10);

        int idx = buscarUsuario(usuarios, cantUsuarios, nombre);
        if (idx == -1) {
            idx = cantUsuarios;
            usuarios[idx] = new Usuario();
            usuarios[idx]->nombre = nombre;
            cantUsuarios++;
        }

        usuarios[idx]->total++;

        if (evento == "LOGIN_OK")
            usuarios[idx]->ok++;
        else if (evento == "LOGIN_FAIL")
            usuarios[idx]->fail++;

        int d = buscarDia(*usuarios[idx], fecha);
        if (d == -1) {
            d = usuarios[idx]->cantDias;
            usuarios[idx]->dias[d] = fecha;
            usuarios[idx]->conteoDias[d] = 1;
            usuarios[idx]->cantDias++;
        } else {
            usuarios[idx]->conteoDias[d]++;
        }
    }

    archivo.close();

    for (int i = 0; i < cantUsuarios - 1; i++) {
        for (int j = i + 1; j < cantUsuarios; j++) {
            if (usuarios[j]->total > usuarios[i]->total) {
                Usuario* aux = usuarios[i];
                usuarios[i] = usuarios[j];
                usuarios[j] = aux;
            }
        }
    }

    ofstream salida("reporte_usuarios.txt");

    for (int i = 0; i < cantUsuarios; i++) {
        int max = 0;
        string diaMasActivo;

        for (int j = 0; j < usuarios[i]->cantDias; j++) {
            if (usuarios[i]->conteoDias[j] > max) {
                max = usuarios[i]->conteoDias[j];
                diaMasActivo = usuarios[i]->dias[j];
            }
        }

        salida << "USUARIO: " << usuarios[i]->nombre <<endl;
        salida << "Eventos totales: " << usuarios[i]->total <<endl;
        salida << "Login exitosos: " << usuarios[i]->ok <<endl;
        salida << "Login fallidos: " << usuarios[i]->fail <<endl;
        salida << "Dia mas activo: " << diaMasActivo <<endl<<endl;

        delete usuarios[i];
    }

    salida.close();
    return 0;
}

