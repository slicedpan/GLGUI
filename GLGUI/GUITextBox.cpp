#include "GUITextBox.h"
#include "Primitives.h"

GUITextBox::GUITextBox(std::string label) : label(label)
{
	width = label.length() * 7 + 10;
	height = 23;
}

GUITextBox::~GUITextBox(void)
{
}

void GUITextBox::Draw(Vec2& position)
{
	DrawBGQuad(colour, position, width, height, 3);
	PrintText(position + Vec2(5, 5), label.c_str(), textColour);
}
