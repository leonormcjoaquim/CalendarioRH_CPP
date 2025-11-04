#include "ficheiro.h"
#include "cifra.h"
#include <fstream>
#include <sstream>

// Guarda os colaboradores e as marcações num ficheiro CSV quando o programa termina
bool guardarCSV(const std::vector<Colaborador> &listaColaboradores)
{
    std::ofstream f("colaboradores.csv");
    if (!f)
        return false;

    f << "Nome,Data,Tipo\n";

    for (const auto &c : listaColaboradores)
    {
        std::string nomeComCifra = cifrar(c.nome);

        if (c.marcacoes.empty())
        {
            f << nomeComCifra << ",,\n";
        }
        else
        {
            for (const auto &m : c.marcacoes)
            {
                f << nomeComCifra << "," << m.data << "," << m.tipo << "\n";
            }
        }
    }
    return true;
}

// Carrega os colaboradores e as marcações de um ficheiro CSV quando o programa inicia
bool carregarCSV(std::vector<Colaborador> &listaColaboradores)
{
    std::ifstream f("colaboradores.csv");
    if (!f)
        return false;

    listaColaboradores.clear();
    std::string linha;

    std::getline(f, linha); // lê cabeçalho e ignora

    while (std::getline(f, linha))
    {

        std::stringstream ss(linha);
        std::string nomeEnc, data, tipoStr;

        std::getline(ss, nomeEnc, ',');
        std::getline(ss, data, ',');
        std::getline(ss, tipoStr, ',');

        std::string nome = decifrar(nomeEnc);

        for (char &c : nome)
            c = std::tolower(c);

        Colaborador *col = nullptr;
        for (auto &c : listaColaboradores) {
            if (c.nome == nome){
                col = &c;
                break;
            }
        }

        if (!col)
        {
            Colaborador novo;
            novo.nome = nome;
            listaColaboradores.push_back(novo);
            col = &listaColaboradores.back();
        }

        if (data.size() == 10 && tipoStr.size() == 1)
        {
            Marcacao marc;
            marc.data = data;
            marc.tipo = tipoStr[0];
            col->marcacoes.push_back(marc);
        }
    }
    return true;
}
