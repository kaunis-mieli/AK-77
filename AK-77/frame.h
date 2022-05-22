#pragma once
#include <wx/wx.h>

#include "manager.fwd.h"

/// <summary>
/// Main frame of program
/// </summary>
class Frame : public wxFrame
{
public:
    Frame(Manager* service, const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

private:
    //Canvas* canvas;
    Manager* manager;

    enum id {
        hello = 1
    };
};