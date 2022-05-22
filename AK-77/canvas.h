#pragma once
#include <wx/wx.h>

#include "manager.fwd.h"

/// <summary>
/// Painting board
/// </summary>
class Canvas : wxWindow
{
public:
    Canvas(Manager* manager, wxFrame* parent, wxWindowID id, const wxPoint& pos, const wxSize& size);
private:
    void OnPaintEvent(wxPaintEvent&);
    void OnMouseMotion(wxMouseEvent&);
    void OnMouseLeftUp(wxMouseEvent&);
    void OnKeyChar(wxKeyEvent&);

private:
    Manager* manager;
};