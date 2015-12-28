/********************************************************************
	created:	2009/08/19
	created:	19:8:2009   0:34
	filename: 	i:\Trab\ZShoot\Development\Sources\fsm.cpp
	file path:	i:\Trab\ZShoot\Development\Sources
	file base:	fsm
	file ext:	cpp
	author:		
	
	purpose:	
*********************************************************************/
#include "fsm.h"
CFSM::CFSM()
{
	m_StateInitial.Set(this,&CFSM::BeginStateInitial,&CFSM::StateInitial,&CFSM::EndStateInitial);
	m_pCurrentState=static_cast<CState*>(&m_StateInitial);
	m_pNewState = 0;

}
void CFSM::Update()
{
	if(m_pNewState)
	{
		//printf("m_pNewState");
		//printf(" %s--> %s\n",m_pCurrentState->name,m_pNewState->name);
		m_pCurrentState->ExecuteEndState();
		m_pCurrentState=m_pNewState;
		m_pNewState = 0;
		m_pCurrentState->ExecuteBeginState();
	}
	m_pCurrentState->ExecuteState();
}

bool CFSM::GotoState(CState&newState)
{	
	m_pNewState=&newState;
	return true;
}
bool CFSM::IsState(CState&state)
{
	return (m_pCurrentState==&state);
}
