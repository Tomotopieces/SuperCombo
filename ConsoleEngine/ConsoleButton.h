#pragma once
#include "ConsoleObject.h"
#include "ConsoleText.h"
#include <vector>

namespace ConsoleEngine
{
	using namespace ConsoleController;
	class ConsoleButton
		: public ConsoleText
	{
	private:
		//	color
		int defaultBackColor = light;
		int defaultForeColor = black;
		int inactiveBackColor = white;			//	getMouse without get leftDown
		int inactiveForeColor = black;
		int activeBackColor = white + light;
		int activeForeColor = black;
		int unavailableDefaultBackColor = red;
		int unavailableDefaultForeColor = black;
		int unavailableInactiveBackColor = red + light;
		int unavailableInactiveForeColor = black;

		//	state
		bool catchMouse = false;
		bool available = true;
		bool active = false;
		bool draggable = false;		//	use Drag() instead of activateFunction() if true

		RenderMode currentMode = Normal;

		//	action
		void(*activateFunction)();
		int dragOffset = 0;
		void Drag();

		//	others
		const bool CatchMouse();

		explicit ConsoleButton();
	public:
		//	constructor
		ConsoleButton(const std::string Text);
		ConsoleButton(const std::string Text, const ConsolePoint2D Position);
		ConsoleButton(const std::string Text, const int x, const int y);
		ConsoleButton(const std::string Text, void(*ActivateFunction)());
		ConsoleButton(const ConsoleButton& Button);
		ConsoleButton(ConsoleButton&& Button);
		virtual const ConsoleButton& operator=(const ConsoleButton& Button);

		//	get
		virtual ConsoleButton* GetClone()const override;
		const bool GetDraggable()const;

		//	set color
		ConsoleButton& SetDefaultBackColor(int Color);
		ConsoleButton& SetDefaultForeColor(int Color);
		ConsoleButton& SetInactiveBackColor(int Color);
		ConsoleButton& SetInactiveForeColor(int Color);
		ConsoleButton& SetActiveBackColor(int Color);
		ConsoleButton& SetActiveForeColor(int Color);
		ConsoleButton& SetUnavailableDefaultBackColor(int Color);
		ConsoleButton& SetUnavailableDefaultForeColor(int Color);
		ConsoleButton& SetUnavailableInactiveBackColor(int Color);
		ConsoleButton& SetUnavailableInactiveForeColor(int Color);

		//	set state
		ConsoleButton& SetAvailable(const bool Usable);
		ConsoleButton& SetActivateFunction(void(*ActivateFunction)());

		//	others
		const ConsoleButton& UpdateState();
		const ConsoleButton& SetDraggable(const bool Draggable);
		//const ConsoleButton& Render()const override;
	};
}