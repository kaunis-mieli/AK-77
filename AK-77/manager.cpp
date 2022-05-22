#include "manager.h"

Manager::Manager(Application* application)
	: application(application)
{
	this->CreateFrame();
	this->CreateCanvas();
}

void Manager::CreateFrame()
{
	this->frame = new Frame(this, "AK-77", { -1,-1 }, { 800, 600 });
	this->frame->Show(true);
}

void Manager::CreateCanvas()
{
	canvas = new Canvas(this, frame, -1, { -1, -1 }, { -1, -1 });
}

void Manager::MakeTransition(State state)
{

}