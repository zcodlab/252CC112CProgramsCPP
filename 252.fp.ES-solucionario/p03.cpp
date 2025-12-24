#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>

using namespace std;

struct Estudiante {
    string codigo;
    string nombre;
    int edad;
    string carrera;
    float promedio;
    Estudiante* sig;
};

string timestamp() {
    time_t now = time(nullptr);
    tm* t = localtime(&now);
    char buffer[20];
    strftime(buffer, 20, "%Y-%m-%d %H:%M", t);
    return string(buffer);
}

Estudiante* buscar(Estudiante* head, string codigo) {
    while (head) {
        if (head->codigo == codigo)
            return head;
        head = head->sig;
    }
    return nullptr;
}

void cargarDesdeArchivo(Estudiante*& head) {
    ifstream file("estudiantes.txt");
    if (!file.is_open()) return;

    string linea;
    while (getline(file, linea)) {
        stringstream ss(linea);
        Estudiante* nuevo = new Estudiante();
        nuevo->sig = nullptr;

        string edadStr, promStr;

        if (!getline(ss, nuevo->codigo, '|')) continue;
        getline(ss, nuevo->nombre, '|');
        getline(ss, edadStr, '|');
        getline(ss, nuevo->carrera, '|');
        getline(ss, promStr);

        nuevo->edad = stoi(edadStr);
        nuevo->promedio = stof(promStr);

        // insertar ordenado
        if (!head || nuevo->codigo < head->codigo) {
            nuevo->sig = head;
            head = nuevo;
        } else {
            Estudiante* aux = head;
            while (aux->sig && aux->sig->codigo < nuevo->codigo)
                aux = aux->sig;
            nuevo->sig = aux->sig;
            aux->sig = nuevo;
        }
    }
    file.close();
}

void guardarTodo(Estudiante* head) {
    ofstream file("estudiantes.txt");
    while (head) {
        file << head->codigo << "|"
             << head->nombre << "|"
             << head->edad << "|"
             << head->carrera << "|"
             << head->promedio << endl;
        head = head->sig;
    }
    file.close();
}

void insertar(Estudiante*& head) {
    Estudiante* nuevo = new Estudiante();
    nuevo->sig = nullptr;

    cout << "Codigo: "; cin >> nuevo->codigo;
    if (buscar(head, nuevo->codigo)) {
        cout << "Codigo duplicado\n";
        delete nuevo;
        return;
    }

    cout << "Nombre: "; cin.ignore(); getline(cin, nuevo->nombre);
    cout << "Edad: "; cin >> nuevo->edad;
    cout << "Carrera: "; cin.ignore(); getline(cin, nuevo->carrera);
    cout << "Promedio: "; cin >> nuevo->promedio;

    if (!head || nuevo->codigo < head->codigo) {
        nuevo->sig = head;
        head = nuevo;
    } else {
        Estudiante* aux = head;
        while (aux->sig && aux->sig->codigo < nuevo->codigo)
            aux = aux->sig;
        nuevo->sig = aux->sig;
        aux->sig = nuevo;
    }

    guardarTodo(head);
}

void modificar(Estudiante* head) {
    string codigo;
    cout << "Codigo: ";
    cin >> codigo;

    Estudiante* e = buscar(head, codigo);
    if (!e) {
        cout << "No encontrado\n";
        return;
    }

    int opcion;
    cout << "1.Nombre 2.Edad 3.Carrera 4.Promedio: ";
    cin >> opcion;

    ofstream hist("historial.txt", ios::app);

    if (opcion == 1) {
        hist << timestamp() << "|" << codigo << "|nombre|" << e->nombre << endl;
        cin.ignore();
        getline(cin, e->nombre);
    } else if (opcion == 2) {
        hist << timestamp() << "|" << codigo << "|edad|" << e->edad << endl;
        cin >> e->edad;
    } else if (opcion == 3) {
        hist << timestamp() << "|" << codigo << "|carrera|" << e->carrera << endl;
        cin.ignore();
        getline(cin, e->carrera);
    } else if (opcion == 4) {
        hist << timestamp() << "|" << codigo << "|promedio|" << e->promedio << endl;
        cin >> e->promedio;
    }

    hist.close();
    guardarTodo(head);
}

void eliminar(Estudiante*& head) {
    string codigo;
    cout << "Codigo: ";
    cin >> codigo;

    if (!head) return;

    if (head->codigo == codigo) {
        Estudiante* tmp = head;
        head = head->sig;
        delete tmp;
        guardarTodo(head);
        return;
    }

    Estudiante* aux = head;
    while (aux->sig && aux->sig->codigo != codigo)
        aux = aux->sig;

    if (aux->sig) {
        Estudiante* borrar = aux->sig;
        aux->sig = borrar->sig;
        delete borrar;
        guardarTodo(head);
    }
}

void consultarHistorial() {
    string codigo;
    cout << "Codigo: ";
    cin >> codigo;

    ifstream file("historial.txt");
    string linea;

    while (getline(file, linea)) {
        if (linea.find("|" + codigo + "|") != string::npos)
            cout << linea << endl;
    }
    file.close();
}

void generarReporte(Estudiante* head) {
    ofstream rep("reporte.txt");

    int total = 0;
    float suma = 0;
    Estudiante *max = nullptr, *min = nullptr;

    while (head) {
        if (!max || head->promedio > max->promedio) max = head;
        if (!min || head->promedio < min->promedio) min = head;
        suma += head->promedio;
        total++;
        head = head->sig;
    }

    rep << "Total: " << total << endl;
    rep << "Promedio general: " << (total ? suma / total : 0) << endl;
    if (max) rep << "Mayor promedio: " << max->nombre << endl;
    if (min) rep << "Menor promedio: " << min->nombre << endl;

    rep.close();
}

int main() {
    Estudiante* head = nullptr;
    cargarDesdeArchivo(head);

    int op;
    do {
        cout << "\n1.Insertar\n2.Modificar\n3.Eliminar\n4.Historial\n5.Reporte\n0.Salir\n";
        cin >> op;

        switch (op) {
            case 1: insertar(head); break;
            case 2: modificar(head); break;
            case 3: eliminar(head); break;
            case 4: consultarHistorial(); break;
            case 5: generarReporte(head); break;
        }
    } while (op != 0);

    return 0;
}
