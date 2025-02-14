#include <iostream>
#include <string>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;
    char genero;

public:
    Persona(string nombre, int edad, char genero) {
        this->nombre = nombre;
        this->edad = edad;
        this->genero = genero;
    }
};

int main() {
    return 0;
}
