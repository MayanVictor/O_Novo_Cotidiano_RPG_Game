#include <raylib.h>
#include "Personagens.hpp"

struct SlotCombatente {
    int numero;              // 1..5
    Personagens* personagem; // nullptr se slot vazio
    Vector2 posicaoTela;     // onde desenhar a carta
    bool ativo;              // é o turno dele agora?
};

int main()
{
    InitWindow(1280, 720, "My Game");

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello, World!", 10, 10, 20, LIGHTGRAY);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}