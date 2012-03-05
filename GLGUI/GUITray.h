#pragma once

#include <vector>

class GUIElement;

class GUITray
{
public:
	GUITray(void);
	~GUITray(void);
	void Draw();
private:
	std::vector<GUIElement*> elements;
};

