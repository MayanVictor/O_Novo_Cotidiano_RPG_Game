#pragma once
#include <string>


class Entidade;

enum class tipoHabilidade { ATAQUE, DEFESA, CURA, BUFF, DEBUFF, INVOCACAO };
enum class Penalidade { NENHUMA, QUEIMADURA, ATORDOAMENTO };
enum class AlvoHabilidade { ALVO_INIMIGO, ALVO_AMIGO, ALVO_TODOS_INIMIGOS, ALVO_TODOS_AMIGOS, ALVO_PRÓPRIO };

struct EfeitoPenalidade {
    Penalidade tipo;
    int duracaoRodadas;
    int valorPorRodada;  // dano de queimadura, etc.
    Entidade* fonte;  // quem aplicou (para crédito)
};


struct Habilidade
{
    Habilidade(const std::string& nome, const std::string& descricao, 
        tipoHabilidade tipo, int valor, int custoPsi, 
        const EfeitoPenalidade& efeitoPenalidade = { Penalidade::NENHUMA, 0, 0, nullptr }, AlvoHabilidade alvoPermitido = AlvoHabilidade::ALVO_INIMIGO)
        : nome(nome), descricao(descricao), tipo(tipo), valor(valor), custoPsi(custoPsi), efeitoPenalidade(efeitoPenalidade) {}
    tipoHabilidade tipo;
    std::string nome;
    std::string descricao;
    EfeitoPenalidade efeitoPenalidade;  // efeito adicional da habilidade
    AlvoHabilidade alvoPermitido;  // quem a habilidade afeta
    int valor;
    int custoPsi;
};