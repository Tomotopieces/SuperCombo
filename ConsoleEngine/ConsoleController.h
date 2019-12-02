#pragma once
#include <Windows.h>

namespace  consolr_controller {
    enum class ConsoleColor
    {
        Black = 0,
        Blue = 1,
        Green = 2,
        Cyan = 3,
        Red = 4,
        Purple = 5,
        Yellow = 6,
        White = 7,
        Light = 8,
        LightBlue = 9,
        LightGreen = 10,
        LightCyan = 11,
        LightRed = 12,
        LightPurple = 13,
        LightYellow = 14,
        LightWhite = 15,
    };

    class MOUSE {
    private:
        static DWORD _fdwMode;
        static HANDLE _handle;
        static DWORD _numRead;
        static PINPUT_RECORD _inrc;
    public:
        MOUSE();

        static COORD GetPosition();
        static bool GetLeftDown();
        static bool GetRightDown();
        static bool GetBothDown();
    };
    extern MOUSE Mouse;

    class CURSOR {
    private:
        static HANDLE _handle;
        static CONSOLE_CURSOR_INFO _CursorInfo;
        static COORD _coord;
    public:
        CURSOR();

        static bool Hide();
        static bool Show();
        static bool SetPosition(short x, short y);
        static bool SetPosition(COORD pos);
    };
    extern CURSOR Cursor;

    class SCREEN {
    private:
        static HANDLE _handle;
        static CONSOLE_SCREEN_BUFFER_INFO _screenBufferInfo;
        static SMALL_RECT _rect;
        static COORD _coord;

        static ConsoleColor _backgroundColor;
    public:
        SCREEN();

        static COORD GetSize();
        static bool SetTitle(const char* str);
        static bool HideScrollBar();
        static bool FullScreen();    //  can not support Windows7
        static bool Window();
        static bool SetSize(short width, short height);
        static ConsoleColor GetBackgroundColor();
        static bool SetBackgroundColor(ConsoleColor color);
        static bool Clean();
    };
    extern SCREEN Screen;

    class CHARACTER {
    private:
        static HANDLE _handle;
        static int _currentColor;
    public:
        CHARACTER();

        static int GetForeColor();
        static int GetBackColor();
        static bool SetForeColor(ConsoleColor color);
        static bool SetBackColor(ConsoleColor color);
    };
    extern CHARACTER Character;
}