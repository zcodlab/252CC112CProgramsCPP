#include <iostream>
using namespace std;

struct Tarea {
    int id;
    string descripcion;
    int duracion;
    Tarea* siguiente;
};

struct Proyecto {
    int codigo;
    string nombre;
    Tarea* tareas;
    Proyecto* siguiente;
};

// ================= PROYECTOS =================

void agregarProyecto(Proyecto*& lista, int codigo, string nombre) {
    Proyecto* nuevo = new Proyecto{codigo, nombre, nullptr, nullptr};

    if (!lista) {
        lista = nuevo;
        return;
    }

    Proyecto* aux = lista;
    while (aux->siguiente)
        aux = aux->siguiente;

    aux->siguiente = nuevo;
}

Proyecto* buscarProyecto(Proyecto* lista, int codigo) {
    while (lista) {
        if (lista->codigo == codigo)
            return lista;
        lista = lista->siguiente;
    }
    return nullptr;
}

// ================= TAREAS =================

void agregarTarea(Proyecto* proyecto, int id, string desc, int duracion) {
    if (!proyecto) return;

    Tarea* nueva = new Tarea{id, desc, duracion, nullptr};

    if (!proyecto->tareas) {
        proyecto->tareas = nueva;
        return;
    }

    Tarea* aux = proyecto->tareas;
    while (aux->siguiente)
        aux = aux->siguiente;

    aux->siguiente = nueva;
}

int duracionTotal(Proyecto* proyecto) {
    int total = 0;
    Tarea* t = proyecto->tareas;
    while (t) {
        total += t->duracion;
        t = t->siguiente;
    }
    return total;
}

void eliminarTarea(Proyecto* proyecto, int id) {
    if (!proyecto || !proyecto->tareas) return;

    Tarea* actual = proyecto->tareas;
    Tarea* anterior = nullptr;

    while (actual && actual->id != id) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (!actual) return;

    if (!anterior)
        proyecto->tareas = actual->siguiente;
    else
        anterior->siguiente = actual->siguiente;

    delete actual;
}

// ================= MOVER TAREA =================

void moverTarea(Proyecto* origen, Proyecto* destino, int id) {
    if (!origen || !destino) return;

    Tarea* actual = origen->tareas;
    Tarea* anterior = nullptr;

    while (actual && actual->id != id) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (!actual) return;

    // Desconectar de origen
    if (!anterior)
        origen->tareas = actual->siguiente;
    else
        anterior->siguiente = actual->siguiente;

    // Insertar en destino
    actual->siguiente = nullptr;
    if (!destino->tareas) {
        destino->tareas = actual;
    } else {
        Tarea* aux = destino->tareas;
        while (aux->siguiente)
            aux = aux->siguiente;
        aux->siguiente = actual;
    }
}

// ================= LIMPIEZA POR DURACIÓN =================

void eliminarTareasCortas(Proyecto* lista, int minDuracion) {
    while (lista) {
        Tarea* actual = lista->tareas;
        Tarea* anterior = nullptr;

        while (actual) {
            if (actual->duracion < minDuracion) {
                Tarea* borrar = actual;
                if (!anterior)
                    lista->tareas = actual->siguiente;
                else
                    anterior->siguiente = actual->siguiente;

                actual = actual->siguiente;
                delete borrar;
            } else {
                anterior = actual;
                actual = actual->siguiente;
            }
        }
        lista = lista->siguiente;
    }
}

// ================= LIBERAR MEMORIA =================

void liberarSistema(Proyecto*& lista) {
    while (lista) {
        Proyecto* p = lista;
        Tarea* t = p->tareas;

        while (t) {
            Tarea* borrar = t;
            t = t->siguiente;
            delete borrar;
        }

        lista = lista->siguiente;
        delete p;
    }
}

// ================= MAIN DE PRUEBA =================

int main() {
    Proyecto* sistema = nullptr;

    agregarProyecto(sistema, 1, "IA");
    agregarProyecto(sistema, 2, "Videojuegos");

    agregarTarea(buscarProyecto(sistema, 1), 101, "Recolectar datos", 10);
    agregarTarea(buscarProyecto(sistema, 1), 102, "Entrenar modelo", 25);

    agregarTarea(buscarProyecto(sistema, 2), 201, "Motor gráfico", 30);

    moverTarea(buscarProyecto(sistema, 1), buscarProyecto(sistema, 2), 101);

    eliminarTareasCortas(sistema, 15);

    cout << "Duración total proyecto IA: "
         << duracionTotal(buscarProyecto(sistema, 1)) << endl;

    liberarSistema(sistema);
    return 0;
}

