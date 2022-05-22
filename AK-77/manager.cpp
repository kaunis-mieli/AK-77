#include "manager.h"
#include "noImageHandler.h"
#include "enterPointHandler.h"
#include "freeStyleHandler.h"

Manager::Manager(Application* application)
	: application(application)
{
	this->CreateFrame();
	this->CreateCanvas();

	this->handlers.insert({ State::NoImage,			new NoImageHandler(this, State::NoImage) });
	this->handlers.insert({ State::Enter1stPoint,	new EnterPointHandler(this, State::Enter1stPoint, "1st reference point") });
	this->handlers.insert({ State::Enter2ndPoint,	new EnterPointHandler(this, State::Enter2ndPoint, "2nd reference point") });
	this->handlers.insert({ State::FreeStyle,		new FreeStyleHandler(this, State::FreeStyle)});

	this->MakeTransition(State::NoImage);
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

void Manager::MakeTransition(const State& state)
{
	currentHandler = handlers[state];
	currentHandler->OnTransition();
}