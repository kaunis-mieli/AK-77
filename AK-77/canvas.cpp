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

	this->SetBackgroundStyle(wxBG_STYLE_PAINT);
}

void Canvas::OnPaintEvent(wxPaintEvent& e)
{
	wxAutoBufferedPaintDC dc(this);
	dc.Clear();

	auto gc = wxGraphicsContext::Create(dc);

	if (gc && this->manager->currentHandler != nullptr)
	{
		this->manager->currentHandler->Render(gc);
		delete gc;
	}
}

void Canvas::OnMouseMotion(wxMouseEvent& e)
{
	if (this->manager->currentHandler != nullptr)
	{
		this->manager->currentHandler->OnMouseMotion(e);
	}
}

void Canvas::OnMouseLeftUp(wxMouseEvent& e)
{
	if (this->manager->currentHandler != nullptr)
	{
		this->manager->currentHandler->OnMouseLeftUp(e);
	}
}

void Canvas::OnKeyChar(wxKeyEvent& e)
{
	if (this->manager->currentHandler != nullptr)
	{
		this->manager->currentHandler->OnKeyChar(e);
	}
}