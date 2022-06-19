#include "XNOR2.h"


#include <iostream>
using namespace std;
XNOR2::XNOR2(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void XNOR2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	if (m_InputPins[0].getStatus()==LOW && m_InputPins[1].getStatus()==LOW)
		m_OutputPin.setStatus(HIGH);
	else if (m_InputPins[0].getStatus()==LOW && m_InputPins[1].getStatus()==HIGH)
		m_OutputPin.setStatus(LOW);
	else if (m_InputPins[0].getStatus()==HIGH && m_InputPins[1].getStatus()==LOW)
		m_OutputPin.setStatus(LOW);
	else
		m_OutputPin.setStatus(HIGH);
}


// Function Draw
// Draws 2-input AND gate
void XNOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXNOR2(m_GfxInfo, IsSelected);
}

//returns status of outputpin
int XNOR2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XNOR2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XNOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}
ActionType XNOR2:: getactiontype()
{
	return ADD_XNOR_GATE_2;
}

//writes the component information in the save file
void XNOR2::Save(ofstream& saveFile)
{
	saveFile << Type_XNOR2 << "\t" << getID() << "\t" << getLabel() << "\t" << m_GfxInfo.x1 << "\t" << m_GfxInfo.y1 << endl;
}

//Loads the component information
void XNOR2::Load(string lbl, int id)
{
	setLabel(lbl);
	setID(id);
}