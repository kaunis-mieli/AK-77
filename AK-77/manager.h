#pragma once

#include <unordered_map>
#include <wx/wx.h>
#include <wx/graphics.h>

#include "application.h"
#include "frame.h"
#include "canvas.h"
#include "states.h"

class Manager
{
public:
	Application* application = nullptr;
	Frame* frame = nullptr;
	Canvas* canvas = nullptr;

public:
	Manager(Application* application);
	void MakeTransition(State state);

private:
	void CreateFrame();
	void CreateCanvas();
};