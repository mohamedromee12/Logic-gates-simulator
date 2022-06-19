#include "Gate.h"

//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(int r_Inputs, int r_FanOut):m_OutputPin(r_FanOut)
{
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that gate
	IsSelected = false;
	//Associate all input pins to this gate
	for(int i=0; i<m_Inputs; i++)
		m_InputPins[i].setComponent(this);
	ConnectionsList = new Connection * [r_Inputs + r_FanOut];
	ConnectionsCount = 0;
	setID(0);
}


bool Gate::is_comp(int &x, int &y,int&n,bool b)
{
	if(InsideMe(x,y))
		{
			if(b==true)
			{
				if(m_OutputPin.can_connected())
				{
					x=m_GfxInfo.x2;
					y=m_GfxInfo.y1+25;
				}
				else
					return false;
			}
			else
			{
				x=m_GfxInfo.x1;
				if(m_Inputs==1)
				{
					if (!m_InputPins[0].get_isC()  &&   n==1)
					{
						y = m_GfxInfo.y1 + 25;
						m_InputPins[0].set_isc(true);
						n = 1;
					}
					else 
						return false;
				}

				if(m_Inputs==2)
				
				{
					if(!m_InputPins[0].get_isC() &&  n==1)
					{
						y=m_GfxInfo.y1+13;
						m_InputPins[0].set_isc(true);
						n = 1;
					}
					else if(!m_InputPins[1].get_isC() &&  n==2)
					{
						y=m_GfxInfo.y2-13;
						m_InputPins[1].set_isc(true);
						n = 2;
					}
					else 
						return false;
				}
				if(m_Inputs==3)
				{
					if(!m_InputPins[0].get_isC() &&  n==1)
					{
						y=m_GfxInfo.y1+10;
						m_InputPins[0].set_isc(true);
						n=1;
					}
					else if(!m_InputPins[1].get_isC() &&  n==2)
					{
						y=m_GfxInfo.y1+25;
						m_InputPins[1].set_isc(true);
						n=2;
					}
					else if(!m_InputPins[2].get_isC() &&  n==3)
					{
						y=m_GfxInfo.y2-10;
						m_InputPins[2].set_isc(true);
						n=3;
					}
					else 
						return false;
				}

			}

			return true;
		}
	else
		return false;
}

bool Gate::fullconnected()
{
	for(int i=0; i<m_Inputs; i++)
	{
		if(m_InputPins[i].get_isC()==false)
			return false;
	}
	if(m_OutputPin.get_isC()==false)
		return false;

	return true;
}

OutputPin* Gate::getSourcePin()
{
	return &m_OutputPin;
}
InputPin* Gate::getDestPin(int n)
{
	return &m_InputPins[n-1];
}

void Gate::AddConnection(Connection* con)
{
	ConnectionsList[ConnectionsCount++] = con;
}
void Gate :: RemoveConnection(Connection* con, Pin* pin, bool IsInput)
{
	for (int i = 0; i < ConnectionsCount; i++)
	{
		if (ConnectionsList[i] == con)
		{

			ConnectionsList[i] = ConnectionsList[ConnectionsCount-1];
			ConnectionsList[ConnectionsCount-1] = NULL;

			ConnectionsCount--;
			if (IsInput)
				for (int i = 0; i < m_Inputs; i++)
				{
					if (&m_InputPins[i] == pin)
					{
						m_InputPins[i].set_isc(false);
						m_InputPins[i].setStatus(LOW);
					}
				}
			else

				m_OutputPin.DisconnectFrom(con);

			break;
		}
	}
	

}

Connection** Gate::GetConnections(int &N)
{
	N = ConnectionsCount;
	return ConnectionsList;
}

Gate :: ~Gate()
{
	delete [] m_InputPins;
	delete[] ConnectionsList;
}