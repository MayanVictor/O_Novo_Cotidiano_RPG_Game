#pragma once
#include <vector>
#include "Personagens.hpp"
#include "Inimigos.hpp"

enum class EstadoUI {
    ESCOLHENDO_BOTAO,    // HUD principal
    ESCOLHENDO_HABILIDADE,
    ESCOLHENDO_ALVO,
    ESCOLHENDO_ITEM,
    RESOLVENDO           // animação/tempo
};

class Combate
{
public:
    Combate(std::vector<Personagens*> aliados, std::vector<Inimigos*> inimigos);
    void Atualizar(); // chamado no loop, lê input
    void Desenhar(); // desenha HUD e entidades

    // Fluxo de turnos
    void IniciarRodada();
    bool IniciarTurnoDe(int index); // retorna true se for turno de um aliado, false se for turno de inimigo
    void FinalizarTurnoDe(int index);

    // açoes
    void ExecutarAcao(int botao); // 0=Ataque, 1=Habilidades, 2=Inventário, 3=Defender
private:
    std::vector<Personagens*> aliados;
    std::vector<Inimigos*> inimigos;
    std::vector<Personagens*> ordem; // ordem de turnos (aliados + inimigos)
    EstadoUI estadoUI = EstadoUI::ESCOLHENDO_BOTAO;
    Rectangle rectAtaque = { 10, 500, 100, 50 };
    Rectangle rectDefender = { 120, 500, 100, 50 };
    Rectangle rectHabilidade = { 230, 500, 100, 50 };
    Rectangle rectInventario = { 340, 500, 100, 50 };
    Rectangle rectHP = { 10, 10, 200, 20 };
    Rectangle rectPSI = { 10, 40, 200, 20 };
    int turnoAtual = 0;
    int rodada = 1;
    bool aguardandoAcao = true;
};