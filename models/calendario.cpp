/*
    Este ficheiro trata puramente da lógica de calendário, 
    como calcular se é fim de semana ou se um ano é bissexto
*/

#include "calendario.h"

// Para ver se o ano é bissexto
bool isAnoBissexto(int ano)
{
    if (ano % 400 == 0)
        return true;

    if (ano % 100 == 0)
        return false;

    if (ano % 4 == 0)
        return true;

    return false;
}


// Retorna o número de dias num dado mês e ano para confirmar se a data é válida
int diasNoMes(int mes, int ano)
{
    static int meses[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (mes < 1 || mes > 12)
    {
        return 0;
    }
    if (mes == 2)
    {
        if (isAnoBissexto(ano))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
    return meses[mes - 1];
}

// Confirma se a data é válida
bool isDataValida(int dia, int mes, int ano)
{
    if (ano < 1900 || ano > 2200 || mes < 1 || mes > 12)
        return false;

    if (dia < 1 || dia > diasNoMes(mes, ano))
        return false;

    return true;
}

// Congruência de Zeller para calcular o dia da semana
int diaSemana(int dia, int mes, int ano)
{
    if (mes < 3)
    {
        mes += 12;
        ano--;
    }
    int k = ano % 100;
    int j = ano / 100;
    int h = (dia + 13 * (mes + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
    int d = (h + 6) % 7; // 0 = Domingo, 6 = Sábado
    return d;
}

// Para calcular se é fim de semana 
bool isFimDeSemana(int dia, int mes, int ano)
{
    int fds = diaSemana(dia, mes, ano);
    
    return (fds == 0 || fds == 6); // 0 = Domingo, 6 = Sábado
}
