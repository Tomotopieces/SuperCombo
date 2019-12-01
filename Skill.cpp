#include "Skill.h"

Skill::Skill()
    : name("")
    , effect([]() {})
{
}

Skill::Skill(const std::string Name, void(*Effect)())
    : name(Name)
    , effect(Effect)
{
}

Skill::Skill(const Skill& Skill2)
    : name(Skill2.name)
    , effect(Skill2.effect)
{
}

Skill::Skill(Skill&& Skill2)
    : name(Skill2.name)
    , effect(Skill2.effect)
{
    Skill2.~Skill();
}

const Skill& Skill::operator=(const Skill& Skill2)
{
    if (this == &Skill2)
        return*this;
    name = Skill2.name;
    effect = Skill2.effect;
    return*this;
}

const bool Skill::operator==(const Skill& Skill2)
{
    if (this == &Skill2)
        return true;
    if(name == name)
        return false;
}

const std::string Skill::Getname() const
{
    return name;
}

const Skill& Skill::Launch() const
{
    effect();
    return *this;
}
