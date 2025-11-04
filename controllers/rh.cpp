#include "rh.h"
#include "../models/colaborador.h"
#include "../models/calendario.h"

#include <string>
#include <vector>

// Cria colaborador se não existir já um com mesmo nome e adiciona à listaColaboradores
bool adicionarColaborador(std::vector<Colaborador> &listaColaboradores, const std::string &nome)
{
    for (const auto &c : listaColaboradores) {
        if (c.nome == nome) {
            return false;
        }
    }
    Colaborador novo;
    novo.nome = nome;
    listaColaboradores.push_back(novo);
    return true;
}

// procurar colaborador para mostrar calendario
const Colaborador *encontrarColaborador(const std::vector<Colaborador> &listaColaboradores, const std::string &nome)
{
    for (const auto &c : listaColaboradores)
        if (c.nome == nome)
            return &c;
    return 0;
}

// procurar se uma marcação existe mesmo, e devolve a sua posição na lista de marcações
int procurarMarcacao(const Colaborador &c, const std::string &data)
{
    for (unsigned int i = 0; i < c.marcacoes.size(); i++) {
        if (c.marcacoes[i].data == data)
            return i;
    }
    return -1;
}

// Para construir a data no formato YYYY-MM-DD
std::string construirData(int dia, int mes, int ano)
{
    std::string anoString = std::to_string(ano);

    std::string mesString;
    if (mes < 10) // Porque quero guardar de forma consistente com 2 dígitos para mês e dia
    {
        mesString = "0" + std::to_string(mes);
    }
    else
    {
        mesString = std::to_string(mes);
    }

    std::string diaString;
    if (dia < 10)
    {
        diaString = "0" + std::to_string(dia);
    }
    else
    {
        diaString = std::to_string(dia);
    }

    return anoString + "-" + mesString + "-" + diaString;
}

// Para marcar um dia de férias ou falta para um colaborador
void marcarDia(std::vector<Colaborador> &listaColaboradores, const std::string &nome, int dia, int mes, int ano, char tipo)
{
    if (!isDataValida(dia, mes, ano))
        return;
    if (isFimDeSemana(dia, mes, ano))
        return;

    std::string data = construirData(dia, mes, ano);

    for (auto &c : listaColaboradores)
    {
        if (c.nome == nome)
        {
            int index = procurarMarcacao(c, data);
            if (index >= 0)
                c.marcacoes[index].tipo = tipo;
            else
            {
                Marcacao marc;
                marc.data = data;
                marc.tipo = tipo;
                c.marcacoes.push_back(marc);
            }
            return;
        }
    }
}

// Para desmarcar um dia de férias ou falta para um colaborador
void desmarcarDia(std::vector<Colaborador> &listaColaboradores, const std::string &nome, int dia, int mes, int ano)
{
    std::string data = construirData(dia, mes, ano);

    for (auto &c : listaColaboradores)
    {
        if (c.nome == nome)
        {
            int index = procurarMarcacao(c, data);
            if (index >= 0) {
                c.marcacoes.erase(c.marcacoes.begin() + index); //apaga a marcação naquele index 
            }
            return;
        }
    }
}
