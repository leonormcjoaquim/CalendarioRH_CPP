#include "io.h"
#include "../models/calendario.h"
#include <limits>

// Mostra o menu principal
void mostrarMenu()
{
    std::cout << "============= MENU RH =============\n";
    std::cout << "1. Adicionar colaborador\n";
    std::cout << "2. Marcar ferias/faltas\n";
    std::cout << "3. Desmarcar dia\n";
    std::cout << "4. Listar colaboradores\n";
    std::cout << "5. Ver calendario mensal\n";
    std::cout << "0. Sair\n";
    std::cout << "Escolha: ";
}

// Pede o nome do colaborador e coloca em minusculas para comparação 
std::string lerNomeColaborador()
{
    std::string nome;
    std::cout << "Nome: ";
    std::getline(std::cin >> std::ws, nome);

    for(char &c : nome)
        c = std::tolower(static_cast<unsigned char>(c));

    return nome;
}



// Pede o dia
int lerDia()
{
    int d;
    std::cout << "Dia: ";
    std::cin >> d;
    return d;
}

// Pede o mês
int lerMes()
{
    int m;
    std::cout << "Mes: ";
    std::cin >> m;
    return m;
}

// Pede o ano
int lerAno()
{
    int a;
    std::cout << "Ano: ";
    std::cin >> a;
    return a;
}

// Pede o tipo de marcação, transforma em uppercase para guardar no ficheiro e ficar consistente
char lerTipoMarcacao()
{
    char t;
    std::cout << "Tipo (F = Ferias, X = Falta): ";
    std::cin >> t;
    if (t == 'f')
        t = 'F';
    if (t == 'x')
        t = 'X';
    return t;
}

// Mostra a lista de colaboradores
void mostrarListaColaboradores(const std::vector<Colaborador> &lista)
{
    std::cout << "\nColaboradores:\n";
    for (const auto &c : lista) {
        std::cout << c.nome << "\n";
    }
}


char obterMarcacao(const Colaborador &c, const std::string &data)
{
    for (unsigned int i = 0; i < c.marcacoes.size(); i++)
        if (c.marcacoes[i].data == data)
            return c.marcacoes[i].tipo;
    return ' ';
}

void mostrarCalendario(const Colaborador &c, int mes, int ano)
{
    std::cout << "\nCalendario de " << c.nome << "                  " << mes << "/" << ano << "\n\n";
    std::cout << "Seg    Ter    Qua    Qui    Sex    Sab    Dom\n";

    int start = diaSemana(1, mes, ano);
    int total = diasNoMes(mes, ano);
    int col = 1;

    for (int i = 1; i < start; i++)
    {
        std::cout << "       ";
        col++;
    }

    for (int d = 1; d <= total; d++)
    {

        std::string dd = (d < 10 ? "0" + std::to_string(d) : std::to_string(d));
        std::string mm = (mes < 10 ? "0" + std::to_string(mes) : std::to_string(mes));
        std::string data = std::to_string(ano) + "-" + mm + "-" + dd;

        char marca = ' ';
        for (const auto &m : c.marcacoes)
            if (m.data == data)
                marca = m.tipo;

        int diaDaSemana = diaSemana(d, mes, ano);
        bool fimDeSemana = (diaDaSemana == 0 || diaDaSemana == 6);

        std::string cor = "\033[0m"; // default

        if (marca == 'F')
        {
            cor = "\033[32m"; // verde
        }
        else if (marca == 'X')
        {
            cor = "\033[31m"; // vermelho
        }
        else if (fimDeSemana)
        {
            cor = "\033[33m"; // amarelo
        }
        std::cout << cor;
        std::cout.width(2);
        std::cout << d << " ";

        if (marca != ' ')
            std::cout << marca;
        else
            std::cout << " ";

        std::cout << "\033[0m"; // default
        std::cout << "   ";

        if (col % 7 == 0)
            std::cout << "\n";
        col++;
    }
    std::cout << "\n";
}

// Limpa o ecrã em ambientes windows
void limparEcra()
{
    system("cls");
}

// Pausa até o utilizador premir Enter
void pausarEcra()
{
    std::cout << "\nPrima Enter para continuar...";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}