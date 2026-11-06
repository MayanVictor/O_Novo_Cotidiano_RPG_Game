#include "Entidade.hpp"
#include <algorithm>
#include <raylib.h>


Entidade::Entidade(std::string nome, tipoPersonagem classe, 
    int hp, int psi, int barreira, int defesa, Rectangle hitbox, int ataque)
{
    this->nome = nome;
    this->classe = classe;
    this->hp = hp;
    this->psi = psi;
    this->ataque = ataque;
    this->barreira = barreira;
    this->defesa = defesa;
    this->ataque = ataque;
    this->hitbox = hitbox; // Use the provided hitbox

}
void Entidade::ReceberDano(const DanoInfo& info)
{
    int danoFinal = info.valor;

    if (!info.ignoraBarreira) {
        if (barreira > 0) {
            int danoNaBarreira = std::min(barreira, danoFinal);
            barreira -= danoNaBarreira;
            danoFinal -= danoNaBarreira;
        }
    }

    if (!info.ignoraDefesa) {
        danoFinal -= defesa;
        if (danoFinal < 0) {
            danoFinal = 0;
        }
    }

    hp -= danoFinal;
    if (hp < 0) {
        hp = 0;
    }
}
void Entidade::ExecutarAcao(int botao, Entidade* alvo)
{
    switch (botao) {
        case 0: // Ataque
            if (alvo) {
                DanoInfo info;
                info.valor = ataque;
                info.tipo = tipoAtaque::FISICO;
                info.fonte = this;
                alvo->ReceberDano(info);
            }
            break;
        case 1: // Habilidades
            // Lógica para usar habilidades
            break;
        case 2: // Inventário
            // Lógica para usar itens
            break;
        case 3: // Defender
            // Lógica para defender (ex: aumentar barreira temporariamente)
            break;
        default:
            break;
    }
}
void Entidade::IniciarTurno()
{
 // 1. Aplica dano de status (queimadura, veneno, etc.)
    for (auto& st : penalidadesAtivas) {
        if (st.tipo == Penalidade::QUEIMADURA) {
            int dano = st.valorPorRodada;
            // aplica direto no HP sem passar por barreira (queimadura ignora)
            hp -= dano;
            if (hp < 0) hp = 0;
        }
    }

    // 2. Decrementa durações de buffs/status
    for (auto& st : penalidadesAtivas) {
        st.duracaoRodadas--;
    }
    // remove os que expiraram
    penalidadesAtivas.erase(
        std::remove_if(penalidadesAtivas.begin(), penalidadesAtivas.end(),
            [](const EfeitoPenalidade& s){ return s.duracaoRodadas <= 0; }),
        penalidadesAtivas.end());

    // 3. Marca que pode agir
    // (seu Combate vai ler isso)
    podeAgir = true;
}
int Entidade::GetPSI() const
{
    return psi;
}
int Entidade::GetHP() const
{
    return hp;
}
int Entidade::GetBarreira() const
{
    return barreira;
}
int Entidade::GetAtaque() const
{
    return ataque;
}
Rectangle Entidade::GetHitbox() const
{
    return hitbox;
}
void Entidade::Draw(Cor cor)
{
    Color color;
    switch (cor)
    {
        case Cor::VERMELHO: color = RED; break;
        case Cor::AZUL: color = BLUE; break;
        case Cor::VERDE: color = GREEN; break;
        case Cor::AMARELO: color = YELLOW; break;
        case Cor::ROXO: color = PURPLE; break;
        case Cor::LARANJA: color = ORANGE; break;
        default: color = WHITE; break;
    }
    DrawRectangleRec(hitbox, color);
}