#ifndef _NAND2_H
#define _NAND2_H

#include "Gate.h"


class NAND2:public Gate
{
public:
	NAND2(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	virtual void Operate();
	virtual void Draw(Output* pOut);
	virtual int GetOutPinStatus();	
	virtual int GetInputPinStatus(int n);

	virtual void setInputPinStatus(int n, STATUS s);

	virtual ActionType getactiontype();
	virtual void Save(ofstream& saveFile); //writes the component information in the save file
	virtual void Load(string lbl, int id); //Loads the component information
};
#endif
