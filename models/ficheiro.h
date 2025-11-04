#ifndef FICHEIRO_H
#define FICHEIRO_H

#include <vector>
#include "colaborador.h"

bool guardarCSV(const std::vector<Colaborador>& lista);
bool carregarCSV(std::vector<Colaborador>& lista);

#endif
