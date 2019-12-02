#include "ActionUnit.h"
#include "SkillLibrary.h"
#include <iostream>

ActionUnit::ActionUnit()
    : _name("DefaultPlayer")
    , _maximumLife(20)
    , _life(_maximumLife)
    , _maximumMana(5)
    , _mana(_maximumMana)
    , _attack(1)
    , _defensive(0)
    , _armor(0)
    , _image(RawImage({""}))
{
    _learnedSkills.push_back(Beat);
    _learnedSkills.push_back(Beat2);
    _learnedSkills.push_back(Beat3);
    _learnedSkills.push_back(Beat4);
}

ActionUnit::ActionUnit(const std::string name)
    : _image(RawImage({ "" }))
{
    ActionUnit();
    _name = name;
}

ActionUnit::ActionUnit(const ActionUnit& unit)
    : _name(unit._name)
    , _maximumLife(unit._maximumLife)
    , _life(unit._life)
    , _maximumMana(unit._maximumMana)
    , _mana(unit._mana)
    , _attack(unit._attack)
    , _defensive(unit._defensive)
    , _armor(0)
    , _learnedSkills(unit._learnedSkills)
    , _image(unit._image)
{
}

ActionUnit::ActionUnit(ActionUnit&& unit)
    : _name(unit._name)
    , _maximumLife(unit._maximumLife)
    , _life(unit._life)
    , _maximumMana(unit._maximumMana)
    , _mana(unit._mana)
    , _attack(unit._attack)
    , _defensive(unit._defensive)
    , _armor(0)
    , _learnedSkills(unit._learnedSkills)
    , _image(RawImage({ "" }))
{
    unit.~ActionUnit();
}

const ActionUnit& ActionUnit::operator=(const ActionUnit& unit)
{
    if (this == &unit)
        return*this;

    _name = unit._name;
    _maximumLife = unit._maximumLife;
    _life = unit._life;
    _maximumMana = unit._maximumMana;
    _mana = unit._mana;
    _attack = unit._attack;
    _defensive = unit._defensive;
    _armor = unit._armor;
    _learnedSkills = unit._learnedSkills;
    return*this;
}

const std::string ActionUnit::GetName() const
{
    return _name;
}

const int ActionUnit::GetMaximumLife() const
{
    return _maximumLife;
}

const int ActionUnit::GetLife() const
{
    return _life;
}

const int ActionUnit::GetMaximumMana() const
{
    return _maximumMana;
}

const int ActionUnit::GetMana() const
{
    return _mana;
}

const int ActionUnit::GetAttack() const
{
    return _attack;
}

const int ActionUnit::GetDefensive() const
{
    return _defensive;
}

const int ActionUnit::GetCountOfSkill() const
{
    return _learnedSkills.size();
}

const std::string ActionUnit::GetSkillName(const int number) const
{
    try{
        if (number >= _learnedSkills.size())
            throw "out of range!";
        else
            return _learnedSkills[number].Getname();
    }
    catch (std::string & msg) {
        std::cerr << msg << std::endl;
    }
}

const ConsoleImage& ActionUnit::GetImage() const
{
    return _image;
}

ActionUnit& ActionUnit::SetName(const std::string name)
{
    _name = name;
    return*this;
}

ActionUnit& ActionUnit::SetMaximumLife(const int maximumLife)
{
    _maximumLife = maximumLife;
    return*this;
}

ActionUnit& ActionUnit::SetLife(const int life)
{
    _life = life;
    return*this;
}

ActionUnit& ActionUnit::SetMaximumMana(const int mana)
{
    _mana = mana;
    return*this;
}

ActionUnit& ActionUnit::SetAttack(const int attack)
{
    _attack = attack;
    return*this;
}

ActionUnit& ActionUnit::SetDefensive(const int defensive)
{
    _defensive = defensive;
    return*this;
}

ActionUnit& ActionUnit::SetImage(const RawImage& image)
{
    _image = image;
    return*this;
}

ActionUnit& ActionUnit::SetImage(const ConsoleImage& image)
{
    _image = image;
    return*this;
}

ActionUnit& ActionUnit::AddSkill(const Skill skill)
{
    _learnedSkills.push_back(skill);
    return*this;
}

ActionUnit& ActionUnit::RemoveSkill(const Skill targetSkill)
{
    for (auto skill = _learnedSkills.begin(); skill != _learnedSkills.end(); ++skill) {
        if (*skill == targetSkill)
            _learnedSkills.erase(skill);
    }
    return*this;
}
