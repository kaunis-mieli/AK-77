#include "enterPointHandler.h"
#include "manager.h"
#include <format>
#include <string>

#include <stdio.h>

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
	wxPoint clickedPosition = e.GetPosition();

	wxString label = std::format("{} for {};{}", this->label, std::to_string(clickedPosition.x), std::to_string(clickedPosition.y));

	wxTextEntryDialog refPoint(this->manager->frame, label, "Enter reference point", "", wxOK|wxCANCEL, {-1, -1});

	if (refPoint.ShowModal() == wxID_OK)
	{
		if (state == State::Enter1stPoint)
		{
			SmartPoint sp(0, 0, 0, 0);

			const char* value = refPoint.GetValue().c_str();

			int i = 0;

			std::sscanf(value, "%i", &i);

			wxMessageBox(std::to_string(i));

			this->manager->MakeTransition(State::Enter2ndPoint);
		}
		else if (state == State::Enter2ndPoint)
		{
			this->manager->MakeTransition(State::FreeStyle);
		}
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
