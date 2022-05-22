#include "canvas.h"
#include "manager.h"

Canvas::Canvas(Manager* manager, wxFrame* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
	: wxWindow(parent, id, pos, size), manager(manager)
{
	this->SetCursor(wxCURSOR_CROSS);

	this->Bind(wxEVT_PAINT, &Canvas::OnPaintEvent, this);
	this->Bind(wxEVT_LEFT_UP, &Canvas::OnMouseLeftUp, this);
	this->Bind(wxEVT_MOTION, &Canvas::OnMouseMotion, this);
	this->Bind(wxEVT_CHAR, &Canvas::OnKeyChar, this);
}

void Canvas::OnPaintEvent(wxPaintEvent& e)
{
	//service->activeHandler->OnPaintEvent(e);
}

void Canvas::OnMouseMotion(wxMouseEvent& e)
{
	
}

void Canvas::OnMouseLeftUp(wxMouseEvent& e)
{
	//service->processor->OnMouseLeftUp(e);
}

void Canvas::OnKeyChar(wxKeyEvent& e)
{
	//service->processor->OnKeyChar(e);
}