#include <iostream>
#include <string>
#include <bitset>
#include <sstream>

// Función para convertir un texto a binario
std::string text_to_binary(const std::string &text) {
    std::string binary_text;
    for (char c : text) {
        binary_text += std::bitset<8>(c).to_string();
    }
    return binary_text;
}

// Función para realizar la operación XOR con una clave dada
std::string Xor(const std::string &input, const std::string &key) {
    std::string output = input;
    for (size_t i = 0; i < input.size(); ++i) {
        output[i] = input[i] ^ key[i % key.size()];
    }
    return output;
}

// Función para codificar una cadena en base64
std::string base64_encode(const std::string &input) {
    const std::string base64_chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";

    std::string output;
    int i = 0;
    int j = 0;
    unsigned char char_array_3[3];
    unsigned char char_array_4[4];

    for (auto c : input) {
        char_array_3[i++] = c;
        if (i == 3) {
            char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
            char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
            char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
            char_array_4[3] = char_array_3[2] & 0x3f;

            for (i = 0; i < 4; i++)
                output += base64_chars[char_array_4[i]];

            i = 0;
        }
    }

    if (i) {
        for (j = i; j < 3; j++)
            char_array_3[j] = '\0';

        char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
        char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
        char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
        char_array_4[3] = char_array_3[2] & 0x3f;

        for (j = 0; j < i + 1; j++)
            output += base64_chars[char_array_4[j]];

        while (i++ < 3)
            output += '=';
    }

    return output;
}

int main() {
    std::string password = "U11RRlVSXFBGVFJdUUZUUlxQR1RTXVFGVVNdUEZVU1xRR1VTXFBGVFNdUEdVU11QRlRTXVFHVVJcUEdVUl1QRlVTXVBGVFNcUUdVU1xRR1RTXVBGVFJcUUZUUlxRRlVSXFBHVFNdUEZVUl1RRlRTXVFHVVNcUUZUU11QRlRSXFFGVFJcUUdUU1xRR1RTXVFGVVJcUUdUUlxRR1RSXFBGVFNdUEZUUlxQRlVSXVFGVFJcUEdUU1xQRlVSXVFHVVNdUUdUU1xRR1RTXFBHVVJcUUZUU11QRlVTXFBGVVJdUEdVUlxQRlVSXFFHVFNdUUZUU11QR1RTXVFGVFJcUUZVUlxQR1VTXVFGVVJdUUZVU10=";
    std::string user_pass;
    std::cout << "Password: ";
    std::getline(std::cin, user_pass);
    std::string bin = text_to_binary(user_pass);
    std::string key = "clave";
    std::string orisada = Xor(bin, key);
    std::string b64 = base64_encode(orisada);
    if(b64==password){
        std::cout << "Gotcha!";
    }else{
        std::cout << "Wrong Password!";
    }

    

    return 0;
}
