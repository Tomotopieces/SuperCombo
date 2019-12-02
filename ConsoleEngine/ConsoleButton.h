#pragma once
#include <vector>
#include "ConsoleText.h"

namespace console_engine
{
    class ConsoleButton
        : public ConsoleText
    {
    private:
        //  color
        ConsoleColor _defaultBackColor = ConsoleColor::Light;
        ConsoleColor _defaultForeColor = ConsoleColor::Black;
            //  getMouse without get leftDown
        ConsoleColor _inactiveBackColor = ConsoleColor::White;
        ConsoleColor _inactiveForeColor = ConsoleColor::Black;
        ConsoleColor _activeBackColor = ConsoleColor::LightWhite;
        ConsoleColor _activeForeColor = ConsoleColor::Black;
        ConsoleColor _unavailableDefaultBackColor = ConsoleColor::Red;
        ConsoleColor _unavailableDefaultForeColor = ConsoleColor::Black;
        ConsoleColor _unavailableInactiveBackColor = ConsoleColor::LightRed;
        ConsoleColor _unavailableInactiveForeColor = ConsoleColor::Black;

        //  state
        bool _catchMouse = false;
        bool _available = true;
        bool _active = false;
            //  use Drag() instead of activateFunction() if true
        bool _draggable = false;

        //  action
        void(*_activateFunction)();
        int _dragOffset = 0;
        void Drag();

        //  others
        const bool CatchMouse();

        explicit ConsoleButton();
    public:
        //  constructor
        ConsoleButton(const std::string text);
        ConsoleButton(const std::string text, const ConsolePoint2D position);
        ConsoleButton(const std::string text, const int x, const int y);
        ConsoleButton(const std::string text, void(*activateFunction)());
        ConsoleButton(const ConsoleButton& button);
        ConsoleButton(ConsoleButton&& button);
        virtual const ConsoleButton& operator=(const ConsoleButton& button);

        //  get
        virtual ConsoleButton* GetClone()const override;
        const bool IsDraggable()const;

        //  set color
        ConsoleButton& SetDefaultBackColor(ConsoleColor color);
        ConsoleButton& SetDefaultForeColor(ConsoleColor color);
        ConsoleButton& SetInactiveBackColor(ConsoleColor color);
        ConsoleButton& SetInactiveForeColor(ConsoleColor color);
        ConsoleButton& SetActiveBackColor(ConsoleColor color);
        ConsoleButton& SetActiveForeColor(ConsoleColor color);
        ConsoleButton& SetUnavailableDefaultBackColor(ConsoleColor color);
        ConsoleButton& SetUnavailableDefaultForeColor(ConsoleColor color);
        ConsoleButton& SetUnavailableInactiveBackColor(ConsoleColor color);
        ConsoleButton& SetUnavailableInactiveForeColor(ConsoleColor color);

        //  set state
        ConsoleButton& SetAvailable(const bool available);
        ConsoleButton& SetActivateFunction(void(*activateFunction)());

        //  others
        const ConsoleButton& UpdateState();
        const ConsoleButton& SetDraggable(const bool draggable);
    };
}