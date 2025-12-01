#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

struct Qbit {
    char state;
};

void crearRegistro(const char* nombre, int N) {
    ofstream out(nombre, ios::binary);
    Qbit q;
    for (int i = 0; i < N; i++) {
        q.state = (rand() % 2) ? '1' : '0';
        out.write(reinterpret_cast<char*>(&q), sizeof(q));
    }
}

char medir(const char* nombre, int pos) {
    ifstream in(nombre, ios::binary);
    Qbit q;
    in.seekg(pos * sizeof(Qbit));
    in.read(reinterpret_cast<char*>(&q), sizeof(q));
    return q.state;
}

void puertaNOT(const char* nombre, int pos) {
    fstream file(nombre, ios::binary | ios::in | ios::out);
    Qbit q;

    file.seekg(pos * sizeof(Qbit));
    file.read(reinterpret_cast<char*>(&q), sizeof(q));

    q.state = (q.state == '0' ? '1' : '0');

    file.seekp(pos * sizeof(Qbit));
    file.write(reinterpret_cast<char*>(&q), sizeof(q));
}

void mostrar(const char* nombre) {
    ifstream in(nombre, ios::binary);
    Qbit q;
    int i = 0;
    while (in.read(reinterpret_cast<char*>(&q), sizeof(q)))
        cout << "Qbit[" << i++ << "] = |" << q.state << ">"<<endl;
}

int main() {
    const char* archivo = "qregister.dat";
    int N = 10;

    crearRegistro(archivo, N);
    cout << "Registro inicial:"<<endl;
    mostrar(archivo);

    cout <<endl<<"Aplicando NOT al qbit 3..."<<endl;
    puertaNOT(archivo, 3);

    cout<<endl<<"Estado tras NOT:"<<endl;
    mostrar(archivo);

    return 0;
}
