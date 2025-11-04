#ifndef RH_H
#define RH_H

#include <vector>
#include <string>
#include "../models/colaborador.h"

bool adicionarColaborador(std::vector<Colaborador>& lista, const std::string& nome);
const Colaborador* encontrarColaborador(const std::vector<Colaborador>& lista, const std::string& nome);
void marcarDia(std::vector<Colaborador>& lista, const std::string& nome, int d, int m, int a, char tipo);
void desmarcarDia(std::vector<Colaborador>& lista, const std::string& nome, int d, int m, int a);
std::string construirData(int dia, int mes, int ano);

#endif
