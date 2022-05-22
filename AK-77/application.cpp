#include "application.h"
#include "manager.h"

bool Application::OnInit()
{
	this->manager = new Manager(this);
	return true;
}