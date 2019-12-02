#pragma once
#include "ConsoleObject.h"

namespace console_engine
{
    using namespace consolr_controller;

    class ConsoleText
        : public ConsoleObject
    {
    private:
        ConsoleColor _backColor = ConsoleColor::Black;
        ConsoleColor _foreColor = ConsoleColor::Light;
        RenderMode _currentMode = RenderMode::Normal;

        explicit ConsoleText();
    public:
        //  constructor
        ConsoleText(const std::string text);
        ConsoleText(const std::string text, const ConsolePoint2D position);
        ConsoleText(const std::string text, const int x, const int y);
        ConsoleText(const ConsoleText& text);
        ConsoleText(ConsoleText&& text);
        virtual const ConsoleText& operator=(const ConsoleText& text);
        virtual const ConsoleText& operator=(const std::string& text);

        //  get
        virtual ConsoleText* GetClone()const override;
        const ConsoleColor GetBackColor()const;
        const ConsoleColor GetForeColor()const;

        //  set
        ConsoleText& SetBackColor(const ConsoleColor color);
        ConsoleText& SetForeColor(const ConsoleColor color);
        ConsoleText& SetRenderMode(const RenderMode mode);

        //  others
        virtual const ConsoleText& Render()const override;
    };
}