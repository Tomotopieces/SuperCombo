#include "Skill.h"

Skill::Skill()
    : _name("")
    , _effect([](BattleManager&) {})
{
}

Skill::Skill(const std::string name, void(*effect)(BattleManager&))
    : _name(name)
    , _effect(effect)
{
}

Skill::Skill(const Skill& skill)
    : _name(skill._name)
    , _effect(skill._effect)
{
}

Skill::Skill(Skill&& skill)
    : _name(skill._name)
    , _effect(skill._effect)
{
    skill.~Skill();
}

const Skill& Skill::operator=(const Skill& skill)
{
    if (this == &skill)
        return*this;
    _name = skill._name;
    _effect = skill._effect;
    return*this;
}

const bool Skill::operator==(const Skill& skill)
{
    if (this == &skill)
        return true;
    if(_name == _name)
        return false;
}

const std::string Skill::Getname() const
{
    return _name;
}

const Skill& Skill::Launch(BattleManager& battleManager) const
{
    _effect(battleManager);
    return *this;
}
