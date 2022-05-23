#include "noImageHandler.h"
#include "manager.h"

NoImageHandler::NoImageHandler(Manager* manager, const State& state)
	: Handler(manager, state) {}

void NoImageHandler::_OnMouseMotion(wxMouseEvent& e)
{
	this->canvas->Refresh();
}

void NoImageHandler::_OnMouseLeftUp(wxMouseEvent& e)
{
}

void NoImageHandler::_OnKeyChar(wxKeyEvent& e)
{
	bool processed = false;
	
	if (e.GetKeyCode() == WXK_CONTROL_V)
	{
	    if (wxTheClipboard->Open())
	    {
	        if (wxTheClipboard->IsSupported(wxDF_BITMAP))
	        {
	            wxBitmapDataObject obj;
	            wxTheClipboard->GetData(obj);
	            this->manager->bitmap = obj.GetBitmap();
				this->manager->MakeTransition(State::Enter1stPoint);
	        }
	
	        wxTheClipboard->Close();
	    }
	
	    processed = true;
	}
	
	if (!processed) {
	    e.Skip();
	}
}

void NoImageHandler::_OnTransition()
{
	this->canvas->SetBackgroundColour(*wxBLACK);
	this->canvas->Refresh();
}

void NoImageHandler::Render(wxGraphicsContext* gc)
{
	this->DrawText(gc, this->mousePosition.x + 10, this->mousePosition.y + 10, wxT("PRESS CTRL + V\nTO PASTE IMAGE"));
}