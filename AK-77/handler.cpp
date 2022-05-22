#include "handler.h"
#include "manager.h"

Handler::Handler(Manager* manager, const State& state)
	: manager(manager), state(state), canvas((wxWindow*)(manager->canvas)) 
{
	//wxMessageBox(std::to_string((int)&(manager->canvas)), "From Handler constructor");

}

void Handler::OnMouseMotion(wxMouseEvent& e)
{
	this->mousePosition = e.GetPosition();
	this->_OnMouseMotion(e);
}

void Handler::OnMouseLeftUp(wxMouseEvent& e)
{
	this->_OnMouseLeftUp(e);
}

void Handler::OnKeyChar(wxKeyEvent& e)
{
	this->_OnKeyChar(e);
}

void Handler::OnTransition()
{
	this->_OnTransition();
}

void Handler::DrawText(wxGraphicsContext* gc, wxDouble x, wxDouble y, const wchar_t* text)
{
	wxFont font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
	font.SetPointSize(14);
	font.MakeBold();
	gc->SetFont(font, *wxYELLOW);
	
	wxDouble width, height;
	
	gc->GetTextExtent(text, &width, &height);
	gc->SetBrush(*wxBLUE_BRUSH);
	gc->DrawRectangle(x - 5, y - 5, width + 10, height + 2);
	gc->DrawText(text, x, y - 5);
}
