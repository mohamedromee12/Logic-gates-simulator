#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;

}

bool Component :: InsideMe(int x, int y)
{
	if (x >= m_GfxInfo.x1 && x <= m_GfxInfo.x2 && y >= m_GfxInfo.y1 && y <= m_GfxInfo.y2)
		return true;
	else
		return false;
}

void Component::change_status()
{

}


void Component::AddConnection(Connection* con)
{
	
}
void Component::RemoveConnection(Connection* con, Pin*, bool IsInput)
{

}
Connection** Component::GetConnections(int &N)
{
	return NULL;
}

void Component::SetIsSelected(bool q)
{
	IsSelected = q;
}
bool Component:: getisselected()
{
	return IsSelected;
}

GraphicsInfo Component::get_graphicinfo()
{
	return m_GfxInfo;
}

Component::Component()
{
	IsSelected=false;
}


string Component::getLabel(){
	return m_Label;
}

void Component::setLabel(string lbl){
	m_Label = lbl;
}

void Component :: setID(int id)
{
	ID = id;
}
int Component :: getID()
{
	return ID;
}



Component::~Component()
{}