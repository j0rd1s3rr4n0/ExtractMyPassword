#include <iostream>
#include <string>

int main() {
    // Definir la contrase$a correcta
    std::string contrasena_correcta = "Est0EsUn4ClaveAlf4Num3ric4";

    // Pedir al usuario que ingrese la contrase$a
    std::cout << "Por favor, ingresa la contrase$a: ";
    std::string contrasena_ingresada;
    std::cin >> contrasena_ingresada;

    // Verificar si la contrase$a es correcta
    if (contrasena_ingresada == contrasena_correcta) {
        std::cout << "Contrase$a correcta" << std::endl;
        // Abrir la siguiente web
        system("start https://github.com/j0rd1s3rr4n0");
    } else {
        std::cout << "Contrase$a incorrecta" << std::endl;
    }

    return 0;
}

