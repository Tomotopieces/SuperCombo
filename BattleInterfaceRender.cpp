#include "BattleInterfaceRender.h"
#include "ConsoleEngine/ConsoleEngine.h"
using namespace console_engine;

short BattleInterfaceRender::s_indowHeight = 97;
short BattleInterfaceRender::s_indowHeight = 32;

BattleInterfaceRender::BattleInterfaceRender(
    const BattleManager& battleManager
)
    : _battleManager(battleManager)
{
    //  render top and bottom line
    std::string line;
    for (int i = 0; i < s_windowWidth - 1; ++i)
    {
        line += '=';
    }
    ConsoleText cLine = line;
    cLine.SetForeColor((int)ConsoleColor::Cyan);
    _interfaceFrame.AddObject(cLine, 1, 0).AddObject(cLine, 1, s_indowHeight);

    //  render skill slot middle line
    line.clear();
    for (int i = 0; i < 16; ++i)
    {
        line += '=';
    }
    cLine = line;
    cLine.SetForeColor((int)ConsoleColor::Cyan + (int)ConsoleColor::Light);
    _interfaceFrame.AddObject(cLine, 1, 23);
    _interfaceFrame.AddObject(cLine, s_windowWidth - 16, 23);

    //  render slot frame
    line.clear();
    for (int i = 0; i < 20; ++i)
    {
        line += '=';
    }
    cLine = line;
    _interfaceFrame.AddObject(cLine, 18, 22).AddObject(cLine, 18, 24);
    _interfaceFrame.AddObject(cLine, 39, 22).AddObject(cLine, 39, 24);
    _interfaceFrame.AddObject(cLine, 60, 22).AddObject(cLine, 60, 24);

    //  add skill slot
    ConsoleButton slot(_battleManager.GetSkillSlot()[0].Getname());
    slot.SetDraggable(true);
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
    _slot1 = dynamic_cast<ConsoleText*>(_slots[0]);
    _slot2 = dynamic_cast<ConsoleText*>(_slots[1]);
    _slot3 = dynamic_cast<ConsoleText*>(_slots[2]);

    //  add player and enemy Life data
    ConsoleText PlayerLife(
        std::to_string(_battleManager.GetPlayer().GetLife()) + "/" + 
        std::to_string(_battleManager.GetPlayer().GetMaximumLife())
    );
    PlayerLife.SetRenderMode(RenderMode::PointCentered);
    ConsoleText EnemyLife(
        std::to_string(_battleManager.GetEnemy().GetLife()) + "/" + 
        std::to_string(_battleManager.GetEnemy().GetMaximumLife())
    );
    EnemyLife.SetRenderMode(RenderMode::PointCentered);
    _actionUnitData.AddObject(PlayerLife, 22, 17).AddObject(EnemyLife, 71, 17);
    _playerLife = dynamic_cast<ConsoleText*>(_actionUnitData[0]);
    _enemyLife = dynamic_cast<ConsoleText*>(_actionUnitData[1]);

    //  add player and enemy image
    _actionUnitImage.AddObject(_battleManager.GetPlayer().GetImage(), 20, 18);
    _actionUnitImage.AddObject(_battleManager.GetEnemy().GetImage(), 69, 18);

    //  add optional skills
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
    _actionUnitData.Render();
    _actionUnitImage.Render();
    _slots.Render();
    _skills.Render();
}

void BattleInterfaceRender::InterfaceFrame() const
{
    _interfaceFrame.Render();
}

void BattleInterfaceRender::ActionUnitImage() const
{
    _actionUnitData.Render();
}

void BattleInterfaceRender::Skills() const
{
    _skills.Render();
}

void BattleInterfaceRender::ActionUnitData()
{
    _playerLife->SetText(
        std::to_string(_battleManager.GetPlayer().GetLife()) + "/" + 
        std::to_string(_battleManager.GetPlayer().GetMaximumLife())
    );
    _enemyLife->SetText(
        std::to_string(_battleManager.GetEnemy().GetLife()) + "/" +
        std::to_string(_battleManager.GetEnemy().GetMaximumLife())
    );
    _actionUnitData.Render();
}

void BattleInterfaceRender::Slots()
{
    _slot1->SetText(_battleManager.GetSkillSlot()[0].Getname());
    _slot2->SetText(_battleManager.GetSkillSlot()[1].Getname());
    _slot3->SetText(_battleManager.GetSkillSlot()[2].Getname());
    _slots.Render();
}
