#include "Combate.hpp"
#include <raylib.h>

Combate::Combate(std::vector<Personagens*> aliados, std::vector<Inimigos*> inimigos)
    : aliados(aliados), inimigos(inimigos) {}
void Combate::Atualizar()
{
    // Lógica para atualizar o estado do combate, ler input, etc.
    if(!aguardandoAcao) return;

if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 mouse = GetMousePosition();

        // Botão Ataque?
        if (CheckCollisionPointRec(mouse, rectAtaque)) {
            // Precisa escolher alvo? Ex: clique no inimigo
            Personagens* alvo = SelecionarAlvo();
            if (alvo) {
                ordem[turnoAtual]->ExecutarAcao(0, alvo);
                aguardandoAcao = false;
            }
        }
        // Botão Defender?
        else if (CheckCollisionPointRec(mouse, rectDefender)) {
            ordem[turnoAtual]->ExecutarAcao(3, nullptr);
            aguardandoAcao = false;
        }
        // ... outros botões
    }

    // Se ação foi executada e já terminou, avança turno
    if (!aguardandoAcao) {
        FinalizarTurnoDe(turnoAtual);
        turnoAtual++;
        if (turnoAtual >= ordem.size()) {
            turnoAtual = 0;
            rodada++;
        }
        IniciarTurnoDe(turnoAtual);
    }
}
void Combate::Desenhar()
{
    // Lógica para desenhar HUD e entidades na tela
}
void Combate::IniciarRodada()
{
    // Lógica para iniciar uma nova rodada
}
void Combate::ExecutarAcao(int botao)
{

}
bool Combate::IniciarTurnoDe(int index)
{
    ordem[index]->IniciarTurno(); 
    aguardandoAcao = true;
    return aguardandoAcao;
}
void Combate::FinalizarTurnoDe(int index)
{
    aguardandoAcao = false;
    turnoAtual++;
    if (turnoAtual >= ordem.size()) {
        turnoAtual = 0;
        rodada++;
        IniciarRodada();
    }
}