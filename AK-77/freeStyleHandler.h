#pragma once
#include "handler.h"

class FreeStyleHandler : public Handler
{
public:
	FreeStyleHandler(Manager* manager, const State& state);
	virtual void Render(wxGraphicsContext* gc);

protected:
	virtual void _OnMouseMotion(wxMouseEvent& e);
	virtual void _OnMouseLeftUp(wxMouseEvent& e);
	virtual void _OnKeyChar(wxKeyEvent& e);
	virtual void _OnTransition();
};