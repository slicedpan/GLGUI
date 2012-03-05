#include "GUITray.h"
#include "GUIElement.h"

GUITray::GUITray(void)
{
}

GUITray::~GUITray(void)
{
}

void GUITray::Draw()
{
	for (int i = 0; i < elements.size(); ++i)
	{
		elements[i]->Draw();
	}
}
