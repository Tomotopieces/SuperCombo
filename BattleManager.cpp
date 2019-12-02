#include "BattleManager.h"
#include "BattleInterfaceRender.h"
#include "SkillLibrary.h"

BattleManager::BattleManager()
    : _player()
    , _enemy()
{
    _skillSlot.push_back(Empty);
    _skillSlot.push_back(Empty);
    _skillSlot.push_back(Empty);
    RawImage image =
    {
        "$O$",
        "/|\\",
        "/$\\"
    };
    ConsoleImage cImage = image;
    cImage.SetAllColor(
        ConsoleColor::Black,
        ConsoleColor::LightYellow
    );
    _player.SetImage(cImage);
    cImage.SetAllColor(
        ConsoleColor::Black,
        ConsoleColor::LightRed
    );
    _enemy.SetImage(cImage);
    BattleInterfaceRender render(*this);
    render.InitialRender();
}

BattleManager::BattleManager(const BattleManager& Manager)
    : _player(Manager._player)
    , _enemy(Manager._enemy)
    , _skillSlot(Manager._skillSlot)
{
}

ActionUnit& BattleManager::GetPlayer()
{
    return _player;
}

ActionUnit& BattleManager::GetEnemy()
{
    return _enemy;
}

std::vector<Skill>& BattleManager::GetSkillSlot()
{
    return _skillSlot;
}

void BattleManager::Start()
{
}
