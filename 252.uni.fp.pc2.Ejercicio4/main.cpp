#include <iostream>
#include <cctype>
#include <cstring>
#include <iomanip>
using namespace std;

// ----------------------
// Constantes generales
// ----------------------
const int MAX = 100;
const int OK = 0;
const int LONGITUD_MIN=12;
const int ERR_POS_BASE     = 1;
// ----------------------
// Mensajes base
// ----------------------
const char* MSG_VALIDO     = "0 -> Contrasena valida";
// ----------------------
// Mensajes de error
// ----------------------
const char* MSG_ERR_LONGITUD     = "Muy corta (menos de 12 caracteres)";
const char* MSG_ERR_ESPACIO      = "Contiene espacio en blanco";
const char* MSG_ERR_REPETIDO     = "Caracter repetido consecutivamente";
const char* MSG_ERR_NO_PERMITIDO = "Caracter no permitido";
const char* MSG_ERR_FALTANTE     = "Faltan tipos de caracteres requeridos";

// ----------------------
// Tipos de caracteres requeridos
// ----------------------
const char* TIPO_MAYUS   = "[Mayuscula]";
const char* TIPO_MINUS   = "[Minuscula]";
const char* TIPO_DIGITO  = "[Digito]";
const char* TIPO_SIMBOLO = "[Simbolo]";

// ----------------------
// Simbolos permitidos
// ----------------------
const char* SIMBOLOS_PERMITIDOS = "!@#$%^&*()_-+=";

// ----------------------
// Funcion de validacion
// ----------------------
int EsContrasenaSegura(char *p) {
    // Regla a: longitud minima
    if (strlen(p) < LONGITUD_MIN) {
        cout <<ERR_POS_BASE << " -> "<<MSG_ERR_LONGITUD << endl;
        return ERR_POS_BASE;
    }

    bool tieneMayus = false;
    bool tieneMinus = false;
    bool tieneDigito = false;
    bool tieneSimbolo = false;

    char *ptr = p;
    char anterior = '\0';
    int pos = 1;

    while (*ptr) {
        char c = *ptr;

        // Regla e: sin espacios
        if (isspace(c)) {
            cout <<pos <<" -> " << MSG_ERR_ESPACIO << endl;
            return pos;
        }

        // Regla d: sin caracteres consecutivos iguales
        if (pos > 1 && c == anterior) {
            cout <<pos << " -> " << MSG_ERR_REPETIDO
                 << " ('" << c << "')" << endl;
            return pos;
        }

        // Verificar tipo de caracter
        if (isupper(c))
            tieneMayus = true;
        else if (islower(c))
            tieneMinus = true;
        else if (isdigit(c))
            tieneDigito = true;
        else if (strchr(SIMBOLOS_PERMITIDOS, c))
            tieneSimbolo = true;
        else {
            cout <<pos << " -> " << MSG_ERR_NO_PERMITIDO
                 << " ('" << c << "')" << endl;
            return pos;
        }

        anterior = c;
        ptr++;
        pos++;
    }

    // Regla c: debe tener todos los tipos de caracteres requeridos
    if (!tieneMayus || !tieneMinus || !tieneDigito || !tieneSimbolo) {
        cout <<ERR_POS_BASE << " -> " << MSG_ERR_FALTANTE << ": ";
        if (!tieneMayus) cout << TIPO_MAYUS << " ";
        if (!tieneMinus) cout << TIPO_MINUS << " ";
        if (!tieneDigito) cout << TIPO_DIGITO << " ";
        if (!tieneSimbolo) cout << TIPO_SIMBOLO;
        cout << endl;
        return ERR_POS_BASE;
    }

    cout << MSG_VALIDO << endl;
    return OK;
}

// ----------------------
// Programa principal
// ----------------------
int main() {
    char contrasena[MAX];
    cout << "Ingrese una contrasenia:" << endl;
    cin.getline(contrasena, MAX);
    EsContrasenaSegura(contrasena);
     return 0;
}
