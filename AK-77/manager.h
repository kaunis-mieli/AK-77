#pragma once

#include <unordered_map>
#include <vector>

#include <wx/wx.h>
#include <wx/graphics.h>

#include "application.h"
#include "frame.h"
#include "canvas.h"
#include "states.h"
#include "handler.h"

struct SmartPoint
{
	double originX, originY;
	double rescaledX, rescaledY;
};

class Manager
{
public:
	Application* application = nullptr;
	Frame* frame = nullptr;
	Canvas* canvas = nullptr;
	wxBitmap bitmap;

	std::unordered_map<State, Handler*> handlers;
	Handler* currentHandler = nullptr;

	SmartPoint reference1stPoint, reference2ndPoint;



public:
	Manager(Application* application);
	void MakeTransition(const State& state);

private:
	void CreateFrame();
	void CreateCanvas();
};