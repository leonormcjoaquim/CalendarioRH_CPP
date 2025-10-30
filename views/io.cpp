#include "io.h"
#include "../models/colaborador.h"

void mostrarMenu() {
    std::cout << "\n--- MENU ---\n"
            << "1. Adicionar Colaborador\n"
            << "2. Marcar/Desmarcar Ferias e Faltas\n"
            << "3. Listar Colaboradores\n"
            << "4. Visualizar Calendario mensal\n"
            << "5. Sair\n"
            << "Escolha: ";
}