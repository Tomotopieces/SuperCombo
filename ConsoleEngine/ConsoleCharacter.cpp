#include <iostream>
#include "ConsoleCharacter.h"
using namespace console_engine;

ConsoleCharacter::ConsoleCharacter(const char character)
    : ConsoleText("")
    , _character(character)
{
    _text = _character;
}

ConsoleCharacter::ConsoleCharacter(
    const char character,
    const ConsolePoint2D& position
)
    : ConsoleText("", position)
    , _character(character)
{
    _text = _character;
}

ConsoleCharacter::ConsoleCharacter(
    const char character,
    const int x,
    const int y
)
    : ConsoleText("", x, y)
    , _character(character)
{
    _text = _character;
}

ConsoleCharacter::ConsoleCharacter(const ConsoleCharacter& character)
    : ConsoleText(character)
    , _character(character._character)
{
    _text = _character;
}

ConsoleCharacter::ConsoleCharacter(ConsoleCharacter&& character)
    : ConsoleText(character)
    , _character(character._character)
{
    _text = _character;
    character.~ConsoleCharacter();
}

const ConsoleCharacter& ConsoleCharacter::operator=(
    const ConsoleCharacter& character
    )
{
    if (this == &character)
        return*this;
    _text = _character;
    ConsoleText::operator=(character);
    _character = character._character;
    return*this;
}

const bool ConsoleCharacter::operator==(char character) const
{
    return _character == character;
}

ConsoleCharacter::operator char() const
{
    return _character;
}

ConsoleCharacter* ConsoleCharacter::GetClone() const
{
    ConsoleCharacter* clone = new ConsoleCharacter(*this);
    return clone;
}

const char& ConsoleCharacter::GetCharacter() const
{
    return _character;
}

const ConsoleCharacter& ConsoleCharacter::SetCharacter(const char character)
{
    _character = character;
    return*this;
}
