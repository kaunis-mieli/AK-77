#pragma once
#include <wx/wx.h>

#include "manager.fwd.h"

/// <summary>
/// Entry class of entire application. Starts on OnInit() method.
/// </summary>
class Application : public wxApp
{
private:
    Manager* manager;

public:
    virtual bool OnInit();
};