#include <iostream>
#include <string>

class Persona {
private:
    std::string nombre;
    int edad;
    char genero;

public:
    Persona(std::string nombre, int edad, char genero) {
        this->nombre = nombre;
        this->edad = edad;
        this->genero = genero;
    }
};

int main() {
    return 0;
}
