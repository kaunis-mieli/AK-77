#include "freeStyleHandler.h"
#include "manager.h"

#include <format>
#include <string>

FreeStyleHandler::FreeStyleHandler(Manager* manager, const State& state)
	: Handler(manager, state)
{
}

void FreeStyleHandler::Render(wxGraphicsContext* gc)
{
	auto bitmap = this->manager->bitmap;

	if (bitmap.IsOk())
	{
		gc->DrawBitmap(bitmap, 0, 0, bitmap.GetWidth(), bitmap.GetHeight());
	}

	this->DrawText(gc, this->mousePosition.x + 10, this->mousePosition.y + 10, 
		wxString(std::format("[{},{}]", this->mousePosition.x, this->mousePosition.y)));
}

void FreeStyleHandler::_OnMouseMotion(wxMouseEvent& e)
{
	this->canvas->Refresh();
}

void FreeStyleHandler::_OnMouseLeftUp(wxMouseEvent& e)
{
}

void FreeStyleHandler::_OnKeyChar(wxKeyEvent& e)
{
}

void FreeStyleHandler::_OnTransition()
{
	this->canvas->SetBackgroundColour(*wxBLACK);
	this->canvas->Refresh();
}
