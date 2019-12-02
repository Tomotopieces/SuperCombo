#pragma once
#include <iostream>
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
    ConsoleLayer _interfaceFrame;
    ConsoleLayer _playerState;      //  player's name, life, mana
    ConsoleLayer _playerState2;     //  player's atk, def, armor
    ConsoleLayer _enemyState;       //  enemy's name, life, mana
    ConsoleLayer _enemyState2;      //  enemy's atk, def, armor
    ConsoleLayer _unitImage;
    ConsoleLayer _skills;
    ConsoleLayer _slots;

    //  shortcut pointer
    ConsoleText* _pSlot1;
    ConsoleText* _pSlot2;
    ConsoleText* _pSlot3;
    struct UnitShortcut
    {
        ConsoleText* pLife = nullptr;
        ConsoleText* pMana = nullptr;
        ConsoleText* pAttack = nullptr;
        ConsoleText* pDefense = nullptr;
        ConsoleText* pArmor = nullptr;
    };
    UnitShortcut _playerShortcut;
    UnitShortcut _enemyShortcut;

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