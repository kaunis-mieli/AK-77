#include "enterPointHandler.h"
#include "manager.h"

EnterPointHandler::EnterPointHandler(Manager* manager, const State& state, const wxString& label)
	: Handler(manager, state), label(label)
{
}

void EnterPointHandler::Render(wxGraphicsContext* gc)
{
	auto bitmap = this->manager->bitmap;

	if (bitmap.IsOk())
	{
		gc->DrawBitmap(bitmap, 0, 0, bitmap.GetWidth(), bitmap.GetHeight());
	}

	this->DrawText(gc, this->mousePosition.x + 10, this->mousePosition.y + 10, label);
}

void EnterPointHandler::_OnMouseMotion(wxMouseEvent& e)
{
	this->canvas->Refresh();
}

void EnterPointHandler::_OnMouseLeftUp(wxMouseEvent& e)
{
	if (state == State::Enter1stPoint)
	{
		this->manager->MakeTransition(State::Enter2ndPoint);
	}
	else if (state == State::Enter2ndPoint)
	{
		this->manager->MakeTransition(State::FreeStyle);
	}
}

void EnterPointHandler::_OnKeyChar(wxKeyEvent& e)
{
}

void EnterPointHandler::_OnTransition()
{
	if (state == State::Enter1stPoint)
	{
		this->canvas->SetBackgroundColour(*wxYELLOW);
	}

	if (state == State::Enter2ndPoint)
	{
		this->canvas->SetBackgroundColour(*wxRED);
	}

	this->canvas->Refresh();
}
