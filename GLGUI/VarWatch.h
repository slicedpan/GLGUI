#pragma once
#include "guielement.h"
#include "Primitives.h"
#include <sstream>
#include "VarPrint.h"

template<typename T>
class VarWatch :
	public GUIElement
{
public:	
	VarWatch(std::string label, T* value) : printer(new VarPrint<T>()) : label(label), value(value)
	{
		Init();
	}	
	VarWatch(std::string label, T* value, IVarPrint<T>* printer) : label(label), value(value)
	{
		this->printer = printer;
		Init();
	}
	~VarWatch(void)
	{
		delete printer;
	}
	void Draw(Vec2& position)
	{
		DrawBGQuad(colour, position, width, height, 3);
		valueString = label + ": " + printer->Print(value);
		PrintText(position + Vec2(5, 5), valueString.c_str(), textColour);
	}
private:
	void Init()
	{
		int numChars = printer->MaxChars();
		if (numChars <= 0)
			numChars = 60;
		width = (label.length() + 2 + numChars) * 7 + 10;
		height = 23;
	}
	IVarPrint<T>* printer;
	std::string label;
	T* value;
	std::string valueString;
};



