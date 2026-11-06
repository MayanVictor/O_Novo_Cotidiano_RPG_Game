#include "Inimigos.hpp"
#include <raylib.h>


Inimigos::Inimigos(std::string nome, int hp, int psi, int barreira, int defesa, int ataque, 
    Rectangle hitbox, std::vector<Habilidade> habilidades)
{
    this->nome = nome;
    this->hitbox = hitbox;
    this->hp = hp;
    this->psi = psi;
    this->barreira = barreira;
    this->defesa = defesa;
    this->ataque = ataque;
    this->habilidades = habilidades;
}
void Inimigos::ReceberDano(int dano)
{
    int danoFinal = dano;

    if (barreira > 0)
    {
        if (barreira >= danoFinal)
        {
            barreira -= danoFinal;
            danoFinal = 0;
        }
        else
        {
            danoFinal -= barreira;
            barreira = 0;
        }
    }

    hp -= danoFinal;
    if (hp < 0)
        hp = 0;
}
Rectangle Inimigos::GetHitbox() const
{
    return hitbox;
}
int Inimigos::GetHP() const
{
    return hp;
}