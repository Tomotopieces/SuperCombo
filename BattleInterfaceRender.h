#pragma once
#include "ActionUnit.h"
#include "BattleManager.h"
#include "ConsoleEngine/ConsoleEngine.h"

class BattleInterfaceRender
{
private:
    static short s_windowWidth;
    static short s_indowHeight;

    BattleManager _battleManager;

    //  render layers
    ConsoleScene _interfaceFrame;
    ConsoleScene _actionUnitData;
    ConsoleScene _actionUnitImage;
    ConsoleScene _skills;
    ConsoleScene _slots;

    //  shortcut pointer
    ConsoleText* _slot1;
    ConsoleText* _slot2;
    ConsoleText* _slot3;
    ConsoleText* _playerLife;
    ConsoleText* _enemyLife;

    explicit BattleInterfaceRender();
public:
    //  constructor
    BattleInterfaceRender(const BattleManager& battleManager);

    //  render
    void InitialRender()const;
    void InterfaceFrame()const;
    void ActionUnitImage()const;
    void Skills()const;

    //  update and render
    void ActionUnitData();
    void Slots();
};