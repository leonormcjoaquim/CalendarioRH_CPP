#ifndef RH_H
#define RH_H

#include <vector>
#include <string>
#include "../models/colaborador.h"

bool adicionarColaborador(std::vector<Colaborador>& listaColaboradores, const std::string& nome);
const Colaborador* encontrarColaborador(const std::vector<Colaborador>& listaColaboradores, const std::string& nome);
void marcarDia(std::vector<Colaborador>& listaColaboradores, const std::string& nome, int dia, int mes, int ano, char tipo);
void desmarcarDia(std::vector<Colaborador>& listaColaboradores, const std::string& nome, int dia, int mes, int ano);
std::string construirData(int dia, int mes, int ano);

#endif
