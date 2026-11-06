#include <raylib.h>
#include <vector>
#include <string>
#include "habilidades.hpp"

enum class tipoPersonagem { DMGDEALER, TANK, SUPORTE, TATICO, SUMMONER };
enum class tipoAtaque { FISICO, PSIQUICO, ENERGIA };
enum class Cor { VERMELHO, AZUL, VERDE, AMARELO, ROXO, LARANJA, CIANO };

struct DanoInfo {
    int valor;
    tipoAtaque tipo;       // FISICO, PSIQUICO, ENERGIA
    bool ignoraDefesa = false;
    bool ignoraBarreira = false;
    Entidade* fonte = nullptr;  // para reflexão (Samy, Mike)
};

class Entidade
{
    public:
        Entidade(std::string nome, tipoPersonagem classe, int hp, 
            int psi, int barreira, int defesa, Rectangle hitbox, int ataque);
        virtual ~Entidade() = default;
        virtual void ReceberDano(const DanoInfo& info);
        virtual void IniciarTurno();
        virtual void ExecutarAcao(int botao, Entidade* alvo); // 0=Ataque, 1=Habilidades, 2=Inventário, 3=Defender
        const std::string& GetNome() const { return nome; }
        void AdicionarHabilidade(const Habilidade& hab) { habilidades.push_back(hab); };
        const std::vector<Habilidade>& GetHabilidades() const { return habilidades; };
        void Draw(Cor cor);
        int GetHP() const;
        int GetPSI() const;
        int GetBarreira() const;
        int GetAtaque() const;
        Rectangle GetHitbox() const;
    protected:
        std::string nome;
        tipoPersonagem classe;
        Rectangle hitbox;
        int hp, psi, barreira, defesa, ataque;
        std::vector<Habilidade> habilidades;
        std::vector<EfeitoPenalidade> penalidadesAtivas;  // até 10 penalidades ativas
        bool podeAgir = false;
};