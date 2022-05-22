#pragma once
#include "handler.h"

class EnterPointHandler : public Handler
{
public:
	EnterPointHandler(Manager* manager, const State& state, const wxString& label);
	virtual void Render(wxGraphicsContext* gc);

private:
	wxString label;

protected:
	virtual void _OnMouseMotion(wxMouseEvent& e);
	virtual void _OnMouseLeftUp(wxMouseEvent& e);
	virtual void _OnKeyChar(wxKeyEvent& e);
	virtual void _OnTransition();
};