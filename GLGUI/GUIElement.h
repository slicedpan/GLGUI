#pragma once
class GUIElement
{
public:
	GUIElement(void);
	~GUIElement(void);
	void Draw();
	int GetWidth() { return width; }
	int GetHeight() { return height; }
protected:
	int width;
	int height;
};

