#include <iostream>
#include <vector>
#include <string>

#include "models/calendario.h"
#include "models/colaborador.h"
#include "models/ficheiro.h"
#include "controllers/rh.h"
#include "views/io.h"

int main()
{
    std::vector<Colaborador> colaboradores;

    carregarCSV(colaboradores);

    int opcao = 1;

    while (opcao != 0)
    {

        mostrarMenu();
        std::cin >> opcao;

        switch (opcao)
        {
        case 1:
        {
            std::string nome = lerNomeColaborador();
            if (adicionarColaborador(colaboradores, nome))
            {
                std::cout << "\nColaborador adicionado.\n";
            }
            else
            {
                std::cout << "\nJa existe colaborador com o mesmo nome.\n";
            }
            break;
        }
        case 2:
        {
            std::string nome = lerNomeColaborador();
            int dia = lerDia();
            int mes = lerMes();
            int ano = lerAno();
            if (!isDataValida(dia, mes, ano))
            {
                std::cout << "\nData invalida! Insira uma data valida por favor\n";
                break;
            }
            if (isFimDeSemana(dia, mes, ano))
            {
                std::cout << "\nNao pode marcar ferias/faltas ao fim de semana.\n";
                break;
            }
            char tipo = lerTipoMarcacao();
            if (tipo != 'F' && tipo != 'X')
            {
                std::cout << "\nTipo invalido. Utilize F para Ferias ou X para Falta, por favor.\n";
                break;
            }
            marcarDia(colaboradores, nome, dia, mes, ano, tipo);
            break;
        }
        case 3:
        {
            std::string nome = lerNomeColaborador();
            int dia = lerDia();
            int mes = lerMes();
            int ano = lerAno();

            if (!isDataValida(dia, mes, ano))
            {
                std::cout << "\nData invalida! Insira uma data valida por favor\n";
                break;
            }

            std::string data = construirData(dia, mes, ano);
            desmarcarDia(colaboradores, nome, dia, mes, ano);

            std::cout << "\nEsta marcacao foi removida!\n";
            break;
        }
        case 4:
            mostrarListaColaboradores(colaboradores);
            break;
        case 5:
        {
            std::string nome = lerNomeColaborador();
            const Colaborador *c = encontrarColaborador(colaboradores, nome);
            if (c)
            {
                int m = lerMes();
                int a = lerAno();
                mostrarCalendario(*c, m, a);
            }
            else
            {
                std::cout << "Colaborador nao encontrado.\n";
            }
            break;
        }
        case 0:
            std::cout << "A fechar programa. Obrigada!\n";
            break;
        default:
            std::cout << "Escolha invalida. Tem de ser um numero entre 1 a 4.\n";
        }
        if (opcao != 0) {
            pausarEcra();
            limparEcra();
        }
    }

    guardarCSV(colaboradores);

    return 0;
}
