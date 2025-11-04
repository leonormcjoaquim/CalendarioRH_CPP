#ifndef COLABORADOR_H
#define COLABORADOR_H

#include <string>
#include <vector>

//Estrutura para guardar as marcações de férias/faltas
struct Marcacao {
    std::string data;
    char tipo;
};

//Estrutura para guardar colaboradores e um array das marcações
struct Colaborador {
    std::string nome;
    std::vector<Marcacao> marcacoes;
};

#endif
