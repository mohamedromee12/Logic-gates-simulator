#include "AddXOR3.h"


#include "..\ApplicationManager.h"

AddXOR3::AddXOR3(ApplicationManager *pApp):Action(pApp)
{
}

AddXOR3::~AddXOR3(void)
{
}

void AddXOR3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("3-Input XOR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	//check if within drawing area
	while (!(Cy > UI.ToolBarHeight + UI.AND2_Width / 2 && Cy < (UI.height - UI.StatusBarHeight) - UI.AND2_Width / 2))
	{
		pOut->PrintMsg("You are not allowed to print your label outside the drawing area, choose your place again...");
		pIn->GetPointClicked(Cx, Cy);
	}
	//Clear Status Bar
	pOut->ClearStatusBar();
	
}

void AddXOR3::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	
	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	
	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate
	
	GInfo.x1 = Cx - Len/2;
	GInfo.x2 = Cx + Len/2;
	GInfo.y1 = Cy - Wdth/2;
	GInfo.y2 = Cy + Wdth/2;
	XOR3 *pA=new XOR3(GInfo, AND2_FANOUT); 
	pManager->AddComponent(pA);
}

void AddXOR3::Undo()
{}

void AddXOR3::Redo()
{}
