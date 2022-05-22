#pragma once
#include <wx/wx.h>
#include <wx/dcbuffer.h>
#include <wx/graphics.h>
#include <wx/clipbrd.h>

#include "manager.fwd.h"
#include "states.h"

class Handler
{
public:
	Handler(Manager* manager, const State& state);
	virtual void Render(wxGraphicsContext* gc) = 0;
	void OnMouseMotion(wxMouseEvent& e);
	void OnMouseLeftUp(wxMouseEvent& e);
	void OnKeyChar(wxKeyEvent& e);
	void OnTransition();

protected:
	State state;
	Manager* manager;
	wxWindow* canvas;
	wxPoint mousePosition;

protected:
	void DrawText(wxGraphicsContext* gc, wxDouble x, wxDouble y, const wchar_t* text);
	virtual void _OnMouseMotion(wxMouseEvent& e) = 0;
	virtual void _OnMouseLeftUp(wxMouseEvent& e) = 0;
	virtual void _OnKeyChar(wxKeyEvent& e) = 0;
	virtual void _OnTransition() = 0;

};