#include "ConsoleButton.h"
using namespace ConsoleEngine;

ConsoleButton::ConsoleButton(const std::string Text)
	: ConsoleText(Text)
	, activateFunction([]() {})
{
}

ConsoleButton::ConsoleButton(const std::string Text, const ConsolePoint2D Position)
	: ConsoleText(Text, Position)
	, activateFunction([]() {})
{
}

ConsoleButton::ConsoleButton(const std::string Text, const int x, const int y)
	: ConsoleText(Text, x, y)
	, activateFunction([]() {})
{
}

ConsoleButton::ConsoleButton(const std::string Text, void(*ActivateFunction)())
	: ConsoleText(Text)
	, activateFunction(ActivateFunction)
{
}

ConsoleButton::ConsoleButton(const ConsoleButton& Button)
	: ConsoleText(Button)
	, defaultBackColor(Button.defaultBackColor)
	, defaultForeColor(Button.defaultForeColor)
	, inactiveBackColor(Button.inactiveBackColor)
	, inactiveForeColor(Button.inactiveForeColor)
	, activeBackColor(Button.activeBackColor)
	, activeForeColor(Button.activeForeColor)
	, unavailableDefaultBackColor(Button.unavailableDefaultBackColor)
	, unavailableDefaultForeColor(Button.unavailableDefaultForeColor)
	, unavailableInactiveBackColor(Button.unavailableInactiveBackColor)
	, unavailableInactiveForeColor(Button.unavailableInactiveForeColor)
	, catchMouse(Button.catchMouse)
	, active(Button.active)
	, available(Button.available)
	, draggable(Button.draggable)
	, activateFunction(Button.activateFunction)
{
}

ConsoleButton::ConsoleButton(ConsoleButton&& Button)
	: ConsoleText(Button)
	, defaultBackColor(Button.defaultBackColor)
	, defaultForeColor(Button.defaultForeColor)
	, inactiveBackColor(Button.inactiveBackColor)
	, inactiveForeColor(Button.inactiveForeColor)
	, activeBackColor(Button.activeBackColor)
	, activeForeColor(Button.activeForeColor)
	, unavailableDefaultBackColor(Button.unavailableDefaultBackColor)
	, unavailableDefaultForeColor(Button.unavailableDefaultForeColor)
	, unavailableInactiveBackColor(Button.unavailableInactiveBackColor)
	, unavailableInactiveForeColor(Button.unavailableInactiveForeColor)
	, catchMouse(Button.catchMouse)
	, active(Button.active)
	, available(Button.available)
	, draggable(Button.draggable)
	, activateFunction(Button.activateFunction)
{
	Button.~ConsoleButton();
}

const ConsoleButton& ConsoleButton::operator=(const ConsoleButton& Button)
{
	if (this == &Button)
		return*this;
	ConsoleText::operator=(Button);
	defaultBackColor = Button.defaultBackColor;
	defaultForeColor = Button.defaultForeColor;
	inactiveBackColor = Button.inactiveBackColor;
	inactiveForeColor = Button.inactiveForeColor;
	activeBackColor = Button.activeBackColor;
	activeForeColor = Button.activeForeColor;
	unavailableDefaultBackColor = Button.unavailableDefaultBackColor;
	unavailableDefaultForeColor = Button.unavailableDefaultForeColor;
	unavailableInactiveBackColor = Button.unavailableInactiveBackColor;
	unavailableInactiveForeColor = Button.unavailableInactiveForeColor;

	catchMouse = Button.catchMouse;
	active = Button.active;
	available = Button.available;
	draggable = Button.draggable;

	activateFunction = Button.activateFunction;

	return*this;
}

ConsoleButton* ConsoleEngine::ConsoleButton::GetClone() const
{
	ConsoleButton* clone = new ConsoleButton(*this);
	return clone;
}

const bool ConsoleEngine::ConsoleButton::GetDraggable() const
{
	return draggable;
}

void ConsoleEngine::ConsoleButton::Drag()
{
	SetPosition(Mouse.GetPosition().X - dragOffset, Mouse.GetPosition().Y);
}

const bool ConsoleButton::CatchMouse()
{
	catchMouse = (Mouse.GetPosition().Y == position.GetY() && Mouse.GetPosition().X >= position.GetX() && Mouse.GetPosition().X <= (position.GetX() + text.length()));
	return catchMouse;
}

ConsoleButton& ConsoleButton::SetDefaultBackColor(int Color)
{
	defaultBackColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::SetDefaultForeColor(int Color)
{
	defaultForeColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::SetInactiveBackColor(int Color)
{
	inactiveBackColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::SetInactiveForeColor(int Color)
{
	inactiveForeColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::SetActiveBackColor(int Color)
{
	activeBackColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::SetActiveForeColor(int Color)
{
	activeForeColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::SetUnavailableDefaultBackColor(int Color)
{
	unavailableDefaultBackColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::SetUnavailableDefaultForeColor(int Color)
{
	unavailableDefaultForeColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::SetUnavailableInactiveBackColor(int Color)
{
	unavailableInactiveBackColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::SetUnavailableInactiveForeColor(int Color)
{
	unavailableInactiveForeColor = Color;
	return*this;
}

ConsoleButton& ConsoleButton::SetAvailable(const bool Usable)
{
	available = Usable;
	return*this;
}

ConsoleButton& ConsoleButton::SetActivateFunction(void(*ActivateFunction)())
{
	activateFunction = ActivateFunction;
	return*this;
}

const ConsoleButton& ConsoleButton::UpdateState()
{
	if (available) {
		if (catchMouse) {
			if (Mouse.GetLeftDown()) {
				backColor = activeBackColor;
				foreColor = activeForeColor;
				active = true;
				if (draggable) {
					dragOffset = Mouse.GetPosition().X - GetPosition().GetX();
					Drag();
				}
				else
					activateFunction();
			}
			else {
				backColor = inactiveBackColor;
				foreColor = inactiveForeColor;
				active = false;
			}
		}
		else {
			backColor = defaultBackColor;
			foreColor = defaultForeColor;
		}
	}
	else {
		if (catchMouse) {
			backColor = unavailableInactiveBackColor;
			foreColor = unavailableInactiveForeColor;
		}
		else {
			backColor = unavailableDefaultBackColor;
			foreColor = unavailableDefaultForeColor;
		}
	}

	CatchMouse();

	return*this;
}

const ConsoleButton& ConsoleEngine::ConsoleButton::SetDraggable(const bool Draggable)
{
	if (draggable == Draggable)
		return*this;
	draggable = Draggable;
	return*this;
}
