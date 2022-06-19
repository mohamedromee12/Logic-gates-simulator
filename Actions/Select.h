#pragma once
#include "Action.h"
#include "..\Components\Component.h"
class Select : public Action
{
private:
	int x, y;
	Component* target;
public:
	Select(ApplicationManager* pApp);
	virtual void ReadActionParameters();

	//Execute action
	virtual void Execute();

	//To undo this action
	virtual void Undo();

	//To redo this action
	virtual void Redo();

	~Select();
};

