#include "Personagens.hpp"

Personagens CriarCausadorDeDano()
{
    Personagens p("Mike", tipoPersonagem::DMGDEALER, 100, 50, 20, 10, {0, 0, 50, 100}, 30);
    p.AdicionarHabilidade({"PSI Rubro", "Dano físico alto", tipoHabilidade::ATAQUE, 25, 0});
    p.AdicionarHabilidade({"Extensão Psionica", "Aumenta barreira", tipoHabilidade::BUFF, 20, 10});
    return p;
}
Personagens CriarSuporte()
{
    Personagens p("Sara", tipoPersonagem::SUPORTE, 80, 100, 10, 5, {0, 0, 50, 100}, 10);
    p.AdicionarHabilidade({"Onomatopeias", "pode Provocar atordoamento entre 1 a 4 rodadas", 
        tipoHabilidade::DEBUFF, 20, 15, AlvoHabilidade::ALVO_INIMIGO, { Penalidade::ATORDOAMENTO, 3, 0, nullptr }});
    p.AdicionarHabilidade({"Descrição Imersiva", "Aumenta ataque de um aliado", tipoHabilidade::BUFF, 10, 10});
    return p;
}