#pragma once
#include "ConsoleObject.h"

namespace ConsoleEngine
{
	using namespace ConsoleController;
	enum RenderMode {
		Normal = 0,
		HorizontallyCentered = 1,
		VerticallyCentered = 2,
		PointCentered = 4
	};

	class ConsoleText
		: public ConsoleObject
	{
	protected:
		int backColor = black;
		int foreColor = light;
		RenderMode currentMode = Normal;
	private:
		explicit ConsoleText();
	public:
		//	constructor
		ConsoleText(const std::string Text);
		ConsoleText(const std::string Text, const ConsolePoint2D Position);
		ConsoleText(const std::string Text, const int x, const int y);
		ConsoleText(const ConsoleText& Text);
		ConsoleText(ConsoleText&& Text);
		virtual const ConsoleText& operator=(const ConsoleText& Text);

		//	get
		virtual ConsoleText* GetClone()const override;
		const int GetBackColor()const;
		const int GetForeColor()const;

		//	set
		ConsoleText& SetBackColor(const int Color);
		ConsoleText& SetForeColor(const int Color);
		ConsoleText& SetRenderMode(const RenderMode newMode);

		//	others
		virtual const ConsoleText& Render()const override;
	};
}