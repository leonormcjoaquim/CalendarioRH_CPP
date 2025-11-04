#ifndef IO_H
#define IO_H

#include <vector>
#include <string>
#include <iostream>
#include "../models/colaborador.h"

void mostrarMenu();
std::string lerNomeColaborador();
int lerDia();
int lerMes();
int lerAno();
char lerTipoMarcacao();
void mostrarListaColaboradores(const std::vector<Colaborador>& lista);
void mostrarCalendario(const Colaborador& c, int mes, int ano);
void limparEcra();
void pausarEcra();

#endif
