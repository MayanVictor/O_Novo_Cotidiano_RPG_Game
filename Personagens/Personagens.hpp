#pragma once
#include <raylib.h>
#include <string>
#include <vector>
#include "habilidades.hpp"
#include "Entidade.hpp"


class Personagens : public Entidade
{
public:
    Personagens(std::string nome, tipoPersonagem classe, int hp, 
        int psi, int barreira, int defesa, Rectangle hitbox, int ataque);
};