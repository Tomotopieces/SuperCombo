#include "ConsoleEngine/ConsoleEngine.h"
#include "BattleInterfaceRender.h"
using namespace console_engine;

short BattleInterfaceRender::s_windowWidth = 97;
short BattleInterfaceRender::s_indowHeight = 32;

BattleInterfaceRender::BattleInterfaceRender(
    const BattleManager& battleManager
)
    : _battleManager(battleManager)
{
    //  top and bottom line
    std::string line;
    for (int i = 0; i < s_windowWidth - 1; ++i)
    {
        line += '=';
    }
    ConsoleText cLine = line;
    cLine.SetForeColor(ConsoleColor::Cyan);
    _interfaceFrame.AddObject(cLine, 1, 0).AddObject(cLine, 1, s_indowHeight);

    //  skill slot middle line
    line.clear();
    for (int i = 0; i < 16; ++i)
    {
        line += '=';
    }
    cLine = line;
    cLine.SetForeColor(ConsoleColor::LightCyan);
    _interfaceFrame.AddObject(cLine, 1, 23);
    _interfaceFrame.AddObject(cLine, s_windowWidth - 16, 23);

    //  slot frame
    line.clear();
    for (int i = 0; i < 20; ++i)
    {
        line += '=';
    }
    cLine = line;
    _interfaceFrame.AddObject(cLine, 18, 22).AddObject(cLine, 18, 24);
    _interfaceFrame.AddObject(cLine, 39, 22).AddObject(cLine, 39, 24);
    _interfaceFrame.AddObject(cLine, 60, 22).AddObject(cLine, 60, 24);

    //  skill slot
    ConsoleText slot(_battleManager.GetSkillSlot()[0].Getname());
    slot.SetRenderMode(RenderMode::PointCentered);
    _slots.AddObject(slot, 28, 23);
    _slots.AddObject(            //  rename and then add
        slot.SetText(_battleManager.GetSkillSlot()[1].Getname()),
        49, 23
    );
    _slots.AddObject(            //  ibid
        slot.SetText(_battleManager.GetSkillSlot()[2].Getname()),
        70, 23
    );
    _pSlot1 = dynamic_cast<ConsoleText*>(_slots[0]);
    _pSlot2 = dynamic_cast<ConsoleText*>(_slots[1]);
    _pSlot3 = dynamic_cast<ConsoleText*>(_slots[2]);

    //  action unit data
        //  player name
    ConsoleText playerData(_battleManager.GetPlayer().GetName());
    playerData.SetRenderMode(RenderMode::PointCentered);
    _playerState.AddObject(playerData, 22, 9);
        //  player life
    playerData.SetText(
        "Life: " +
        std::to_string(_battleManager.GetPlayer().GetLife()) + "/" +
        std::to_string(_battleManager.GetPlayer().GetMaximumLife())
    );
    _playerState.AddObject(playerData, 22, 10);
    _playerShortcut.pLife = dynamic_cast<ConsoleText*>(_playerState[1]);
        //  player mana
    playerData.SetText(
        "Mana: " +
        std::to_string(_battleManager.GetPlayer().GetMana()) + "/" +
        std::to_string(_battleManager.GetPlayer().GetMaximumMana())
    );
    _playerState.AddObject(playerData, 22, 11);
    _playerShortcut.pMana = dynamic_cast<ConsoleText*>(_playerState[2]);

    playerData.SetRenderMode(RenderMode::Normal);
        //  player attack
    playerData.SetText(
        "Attack:  " +
        std::to_string(_battleManager.GetPlayer().GetAttack())
    );
    _playerState2.AddObject(playerData, 5, 12);
    _playerShortcut.pAttack = dynamic_cast<ConsoleText*>(_playerState2[0]);
        //  player defense
    playerData.SetText(
        "Defense: " +
        std::to_string(_battleManager.GetPlayer().GetDefense())
    );
    _playerState2.AddObject(playerData, 5, 13);
    _playerShortcut.pDefense = dynamic_cast<ConsoleText*>(_playerState2[1]);
        //  player armor
    playerData.SetText(
        "Armor:   " +
        std::to_string(_battleManager.GetPlayer().GetArmor())
    );
    _playerState2.AddObject(playerData, 5, 14);
    _playerShortcut.pArmor = dynamic_cast<ConsoleText*>(_playerState2[2]);

        //  enemy name
    ConsoleText enemyData(_battleManager.GetEnemy().GetName());
    enemyData.SetRenderMode(RenderMode::PointCentered);
    _enemyState.AddObject(enemyData, 75, 10);
        //  enemy life
    enemyData.SetText(
        "Life: " +
        std::to_string(_battleManager.GetEnemy().GetLife()) + "/" +
        std::to_string(_battleManager.GetEnemy().GetMaximumLife())
    );
    _enemyState.AddObject(enemyData, 75, 11);
    _enemyShortcut.pLife = dynamic_cast<ConsoleText*>(_enemyState[1]);

    //  unit image
    _unitImage.AddObject(_battleManager.GetPlayer().GetImage(), 20, 12);
    _unitImage.AddObject(_battleManager.GetEnemy().GetImage(), 73, 12);

    //  optional skills
    for (int i = 0; i < _battleManager.GetPlayer().GetCountOfSkill(); ++i)
    {
        ConsoleText skill(
            _battleManager.GetPlayer().GetSkillName(i),
            10 + i * 20, 26
        );
        _skills.AddObject(skill);
    }
}

void BattleInterfaceRender::InitialRender() const
{
    _interfaceFrame.Render();
    _playerState.Render();
    _playerState2.Render();
    _enemyState.Render();
    _enemyState2.Render();
    _unitImage.Render();
    _slots.Render();
    _skills.Render();
}

void BattleInterfaceRender::InterfaceFrame() const
{
    _interfaceFrame.Render();
}

void BattleInterfaceRender::ActionUnitImage() const
{
    _unitImage.Render();
}

void BattleInterfaceRender::Skills() const
{
    _skills.Render();
}

void BattleInterfaceRender::ActionUnitData()
{
    //  update data
        //  player data
    _playerShortcut.pLife->SetText(
        std::to_string(_battleManager.GetPlayer().GetLife()) + "/" + 
        std::to_string(_battleManager.GetPlayer().GetMaximumLife())
    );
    _playerShortcut.pMana->SetText(
        "Mana: " +
        std::to_string(_battleManager.GetPlayer().GetMana()) + "/" +
        std::to_string(_battleManager.GetPlayer().GetMaximumMana())
    );
    _playerShortcut.pAttack->SetText(
        "Attack: \t" +
        std::to_string(_battleManager.GetPlayer().GetAttack())
    );
    _playerShortcut.pDefense->SetText(
        "Defense: \t" +
        std::to_string(_battleManager.GetPlayer().GetDefense())
    );
    _playerShortcut.pArmor->SetText(
        "Armor: \t" +
        std::to_string(_battleManager.GetPlayer().GetArmor())
    );

        //  enemy data
    _enemyShortcut.pLife->SetText(
        std::to_string(_battleManager.GetEnemy().GetLife()) + "/" +
        std::to_string(_battleManager.GetEnemy().GetMaximumLife())
    );

    //  render
    _playerState.Render();
    _playerState2.Render();
    _enemyState.Render();
    _enemyState2.Render();
}

void BattleInterfaceRender::Slots()
{
    _pSlot1->SetText(_battleManager.GetSkillSlot()[0].Getname());
    _pSlot2->SetText(_battleManager.GetSkillSlot()[1].Getname());
    _pSlot3->SetText(_battleManager.GetSkillSlot()[2].Getname());
    _slots.Render();
}
