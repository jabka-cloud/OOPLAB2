#include <iostream>
#include <windows.h> 
#include "GameController.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);

    GameController game(6, 6);
    game.run();

    return 0;
}
