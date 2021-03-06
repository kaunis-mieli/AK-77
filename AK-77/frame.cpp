#include "frame.h"
#include "manager.h"

Frame::Frame(Manager* manager, const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size), manager(manager)
{
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(id::hello, "&Hello...\tCtrl-H",
        "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    CreateStatusBar(2);

    SetStatusText("Welcome to wxWidgets!");

    Bind(wxEVT_MENU, &Frame::OnHello, this, id::hello);
    Bind(wxEVT_MENU, &Frame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &Frame::OnExit, this, wxID_EXIT);
    this->Bind(wxEVT_CHAR, &Frame::OnKeyChar, this);
}
void Frame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
void Frame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("Made by Vytis Mikašauskas at 2022-05-16 especially for Adomas Kaveckas. Copyrights belongs to Vytis Mikašauskas and Adomas Kaveckas. For licence and reuse ask for them.",
        "About Adomas Kaveckas Grid Ruler", wxOK | wxICON_INFORMATION);
}
void Frame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}

void Frame::OnKeyChar(wxKeyEvent& e)
{
    if (this->manager->currentHandler != nullptr)
    {
        this->manager->currentHandler->OnKeyChar(e);
    }
}