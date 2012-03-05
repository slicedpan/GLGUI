#include "GUIBase.h"
#include "GUITray.h"

GUIBase::GUIBase(void)
{
}

GUIBase::~GUIBase(void)
{
}

void GUIBase::Draw()
{
	for (int i = 0; i < trays.size(); ++i)
	{
		trays[i]->Draw();
	}
}

void GUIBase::MouseClick(int x, int y, int button)
{

}

void GUIBase::MouseMove(int x, int y)
{

}

void GUIBase::Update()
{

}
