#include "ActionUnit.h"
#include "SkillList.h"
#include <iostream>

ActionUnit::ActionUnit()
	: name("DefaultPlayer")
	, maximumLife(20)
	, life(maximumLife)
	, maximumMana(5)
	, mana(maximumMana)
	, attack(1)
	, defensive(0)
	, armor(0)
	, image(RawImage({""}))
{
	learnedSkills.push_back(Beat);
	learnedSkills.push_back(Beat2);
	learnedSkills.push_back(Beat3);
	learnedSkills.push_back(Beat4);
}

ActionUnit::ActionUnit(const std::string Name)
	: image(RawImage({ "" }))
{
	ActionUnit();
	name = Name;
}

ActionUnit::ActionUnit(const ActionUnit& Unit)
	: name(Unit.name)
	, maximumLife(Unit.maximumLife)
	, life(Unit.life)
	, maximumMana(Unit.maximumMana)
	, mana(Unit.mana)
	, attack(Unit.attack)
	, defensive(Unit.defensive)
	, armor(0)
	, learnedSkills(Unit.learnedSkills)
	, image(Unit.image)
{
}

ActionUnit::ActionUnit(ActionUnit&& Unit)
	: name(Unit.name)
	, maximumLife(Unit.maximumLife)
	, life(Unit.life)
	, maximumMana(Unit.maximumMana)
	, mana(Unit.mana)
	, attack(Unit.attack)
	, defensive(Unit.defensive)
	, armor(0)
	, learnedSkills(Unit.learnedSkills)
	, image(RawImage({ "" }))
{
	Unit.~ActionUnit();
}

const ActionUnit& ActionUnit::operator=(const ActionUnit& Unit)
{
	if (this == &Unit)
		return*this;

	name = Unit.name;
	maximumLife = Unit.maximumLife;
	life = Unit.life;
	maximumMana = Unit.maximumMana;
	mana = Unit.mana;
	attack = Unit.attack;
	defensive = Unit.defensive;
	armor = Unit.armor;
	learnedSkills = Unit.learnedSkills;
	return*this;
}

const std::string ActionUnit::GetName() const
{
	return name;
}

const int ActionUnit::GetMaximumLife() const
{
	return maximumLife;
}

const int ActionUnit::GetLife() const
{
	return life;
}

const int ActionUnit::GetMaximumMana() const
{
	return maximumMana;
}

const int ActionUnit::GetMana() const
{
	return mana;
}

const int ActionUnit::GetAttack() const
{
	return attack;
}

const int ActionUnit::GetDefensive() const
{
	return defensive;
}

const int ActionUnit::GetCountOfSkill() const
{
	return learnedSkills.size();
}

const std::string ActionUnit::GetSkillName(const int number) const
{
	try{
		if (number >= learnedSkills.size())
			throw "out of range!";
		else
			return learnedSkills[number].Getname();
	}
	catch (std::string & msg) {
		std::cerr << msg << std::endl;
	}
}

const ConsoleImage& ActionUnit::GetImage() const
{
	return image;
}

ActionUnit& ActionUnit::SetName(const std::string Name)
{
	name = Name;
	return*this;
}

ActionUnit& ActionUnit::SetMaximumLife(const int MaximumLife)
{
	maximumLife = MaximumLife;
	return*this;
}

ActionUnit& ActionUnit::SetLife(const int Life)
{
	life = Life;
	return*this;
}

ActionUnit& ActionUnit::SetMaximumMana(const int Mana)
{
	mana = Mana;
	return*this;
}

ActionUnit& ActionUnit::SetAttack(const int Attack)
{
	attack = Attack;
	return*this;
}

ActionUnit& ActionUnit::SetDefensive(const int Defensive)
{
	defensive = Defensive;
	return*this;
}

ActionUnit& ActionUnit::SetImage(const RawImage& Image)
{
	image = Image;
	return*this;
}

ActionUnit& ActionUnit::SetImage(const ConsoleImage& Image)
{
	image = Image;
	return*this;
}

ActionUnit& ActionUnit::AddSkill(const Skill newSkill)
{
	learnedSkills.push_back(newSkill);
	return*this;
}

ActionUnit& ActionUnit::RemoveSkill(const Skill targetSkill)
{
	for (auto skill = learnedSkills.begin(); skill != learnedSkills.end(); ++skill) {
		if (*skill == targetSkill)
			learnedSkills.erase(skill);
	}
	return*this;
}
