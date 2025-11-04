#ifndef CALENDARIO_H
#define CALENDARIO_H

int diasNoMes(int mes, int ano);
bool isAnoBissexto(int ano);
int diaSemana(int dia, int mes, int ano);
bool isFimDeSemana(int dia, int mes, int ano);
bool isDataValida(int dia, int mes, int ano);

#endif
