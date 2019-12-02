#include <iostream>
#include "ConsoleEngine/ConsoleEngine.h"
#include "BattleManager.h"


int main() {
    Screen.SetSize(97, 32);
    Screen.HideScrollBar();
    Screen.SetTitle("Super Combo");
    Screen.SetBackgroundColor((int)ConsoleColor::Black);
    Cursor.Hide();

    BattleManager battleManager;
    
    getchar();
    return 0;
}