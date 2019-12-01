#pragma once
#include <string>

class Skill
{
private:
    std::string name;
    void(*effect)();
public:
    Skill();
    Skill(const std::string Name, void(*Effect)());
    Skill(const Skill& Skill2);
    Skill(Skill&& Skill2);
    const Skill& operator=(const Skill& Skill2);
    const bool operator==(const Skill& Skill2);

    //  get
    const std::string Getname()const;
    const Skill& Launch()const;
};