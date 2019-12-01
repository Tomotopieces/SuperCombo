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
        (int)ConsoleColor::Black,
        (int)ConsoleColor::Yellow + (int)ConsoleColor::Light
    );
    _player.SetImage(cImage);
    cImage.SetAllColor(
        (int)ConsoleColor::Black,
        (int)ConsoleColor::Red + (int)ConsoleColor::Light
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

const ActionUnit& BattleManager::GetPlayer() const
{
    return _player;
}

const ActionUnit& BattleManager::GetEnemy() const
{
    return _enemy;
}

const std::vector<Skill>& BattleManager::GetSkillSlot() const
{
    return _skillSlot;
}
