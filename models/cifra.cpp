/*
    Este ficheiro trata da encriptação e decriptação dos nomes dos colaboradores,
    utilizando a cifra de César com uma chave fixa.
*/

#include "cifra.h"
#include <cctype>

//Chave constante para a cifra de César
static const int CHAVE = 23;

// Cifra de César para encriptar
static std::string encriptar(const std::string &texto, int chave) {
    std::string resultado = texto;

    for (std::size_t i = 0; i < texto.size(); ++i) {
        char c = texto[i];

        if (std::isalpha(static_cast<unsigned char>(c))) { 
            char base = std::isupper(c) ? 'A' : 'a';
            resultado[i] = char((c - base + chave) % 26 + base);
        } else {
            resultado[i] = c;
        }
    }
    return resultado;
}

// Cifra de César para desencriptar
static std::string desencriptar(const std::string &texto, int chave) {
    return encriptar(texto, 26 - (chave % 26));
}

// função que vem do ficheiro.cpp
std::string cifrar(const std::string& s) {
    return encriptar(s, CHAVE);
}

// função que vem do ficheiro.cpp
std::string decifrar(const std::string& s) {
    return desencriptar(s, CHAVE);
}