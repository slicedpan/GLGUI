
#include <svl\SVL.h>
#include <glut.h>

void PrintText(Vec2 pos, const char* text, Vec4& colour)
{
    if(!text || !strlen(text)) return;
    glColor4f(colour[0], colour[1], colour[2], colour[3]);    
    while (*text) {
		glRasterPos2f(pos[0], pos[1] + 13);
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *text);
		pos[0] += 7;
        text++;
    }
}

void DrawTBorder(Vec2 position, int width, int height, int borderwidth, bool repeat)
{
	glVertex2f(position[0], position[1]);
	glVertex2f(position[0] + width, position[1]);
	glVertex2f(position[0] + width - borderwidth, position[1] + borderwidth);
	glVertex2f(position[0] + borderwidth, position[1] + borderwidth);
	if (repeat)
		glVertex2f(position[0], position[1]);
}

void DrawRBorder(Vec2 position, int width, int height, int borderwidth, bool repeat)
{
	glVertex2f(position[0] + width, position[1]);
	glVertex2f(position[0] + width, position[1] + height);
	glVertex2f(position[0] + width - borderwidth, position[1] + height - borderwidth);
	glVertex2f(position[0] + width - borderwidth, position[1] + borderwidth);
	if (repeat)
		glVertex2f(position[0] + width, position[1]);
}

void DrawLBorder(Vec2 position, int width, int height, int borderwidth, bool repeat)
{
	glVertex2f(position[0], position[1]);
	glVertex2f(position[0], position[1] + height);
	glVertex2f(position[0] + borderwidth, position[1] + height - borderwidth);
	glVertex2f(position[0] + borderwidth, position[1] + borderwidth);
	if (repeat)
		glVertex2f(position[0], position[1]);
}

void DrawBBorder(Vec2 position, int width, int height, int borderwidth, bool repeat)
{
	glVertex2f(position[0], position[1] + height);
	glVertex2f(position[0] + width, position[1] + height);
	glVertex2f(position[0] + width - borderwidth, position[1] + height - borderwidth);
	glVertex2f(position[0] + borderwidth, position[1] + height - borderwidth);
	if (repeat)
		glVertex2f(position[0], position[1] + height);
}

void DrawBGQuad(Vec4 colour, Vec2 position, int width, int height, int borderwidth)
{
	glBegin(GL_QUADS);
	glColor4f(colour[0], colour[1], colour[2], colour[3] / 2.0f);
	glVertex2f(position[0], position[1]);
	glVertex2f(position[0] + width,position[1]);
	glVertex2f(position[0] + width, position[1] + height);
	glVertex2f(position[0], position[1] + height);

	//borders

	glColor4f(colour[0], colour[1], colour[2], colour[3]);
	DrawTBorder(position, width, height, borderwidth, false);
	DrawLBorder(position, width, height, borderwidth, false);
	DrawRBorder(position, width, height, borderwidth, false);
	DrawBBorder(position, width, height, borderwidth, false);
	
	glEnd();

	glColor4f(colour[0] + 0.2f, colour[1] + 0.2f, colour[2] + 0.2f, 1.0f);

	glBegin(GL_LINE_STRIP);

	DrawTBorder(position, width, height, borderwidth, true);
	DrawLBorder(position, width, height, borderwidth, true);
	DrawRBorder(position, width, height, borderwidth, true);
	DrawBBorder(position, width, height, borderwidth, true);

	glEnd();
}