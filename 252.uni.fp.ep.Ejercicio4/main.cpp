#include <iostream>
using namespace std;
const int MAX=200;

bool esEspacio(char c) {
    return c == ' ' || c == '\t';
}

char toLower(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + ('a' - 'A');
    return c;
}

void normalizarYCodificar(char *cadena) {
    char *src = cadena; // puntero de lectura
    char *dst = cadena; // puntero de escritura
    bool ultimoFueEspacio = true; // para evitar espacios iniciales o múltiples

    while (*src != '\0') {
        char c = toLower(*src);

        if (esEspacio(c)) {
            if (!ultimoFueEspacio) {
                *dst = ' ';
                dst++;
                ultimoFueEspacio = true;
            }
        } else {
            // Reemplazo de vocales
            switch (c) {
                case 'a':
                    *dst++ = '1'; break;
                case 'e':
                    *dst++ = '5'; break;
                case 'i':
                    *dst++ = '9'; break;
                case 'o':
                    *dst++ = '1'; *dst++ = '5'; break;
                case 'u':
                    *dst++ = '2'; *dst++ = '1'; break;
                default:
                    *dst++ = c;
            }
            ultimoFueEspacio = false;
        }
        src++;
    }

    // Eliminar espacio final si existe
    if (dst > cadena && *(dst - 1) == ' ')
        dst--;

    *dst = '\0'; // terminamos la cadena
}

int main() {
    char texto[MAX];
    cout << "Ingrese una cadena: ";
    cin.getline(texto, MAX);
    normalizarYCodificar(texto);
    cout << "Cadena transformada: " << texto << endl;
    return 0;
}
