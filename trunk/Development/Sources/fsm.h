/********************************************************************
created:	2009/08/11
created:	11:8:2009   22:45
filename: 	i:\Trab\irrlicht-1.5\examples\04.Movement\fsm.h
file path:	i:\Trab\irrlicht-1.5\examples\04.Movement
file base:	fsm
file ext:	h
author:		

purpose:	
*********************************************************************/
#ifndef __FSM_H__
#define __FSM_H__

class CState
{
public:
	CState()
	{

		name="";
	}
	virtual ~CState() {}
	virtual void ExecuteBeginState() = 0;
	virtual void ExecuteState()=0;
	virtual void ExecuteEndState()=0;
	char*		name;
};

template<class T>
class CStateTemplate : public CState
{
protected:
	typedef void (T::*PFNSTATE)(void);
	T*m_pInstance;
	PFNSTATE m_pfnBeginState;
	PFNSTATE m_pfnState;
	PFNSTATE m_pfnEndState;
public:
	CStateTemplate() : m_pInstance(0),m_pfnBeginState(0),m_pfnState(0),m_pfnEndState(0){}
	void Set(T*pInstance,PFNSTATE pfnBeginState,PFNSTATE pfnState,PFNSTATE pfnEndState)
	{
		m_pInstance = pInstance;
		m_pfnBeginState=pfnBeginState;
		m_pfnState=pfnState;
		m_pfnEndState=pfnEndState;
	}

	virtual void ExecuteBeginState()
	{
		(m_pInstance->*m_pfnBeginState)();
	}
	virtual void ExecuteState()
	{
		(m_pInstance->*m_pfnState)();
	}
	virtual void ExecuteEndState()
	{
		(m_pInstance->*m_pfnEndState)();
	}
};
class CFSM
{
protected:
	CState *m_pCurrentState;
	CState *m_pNewState;
	CStateTemplate<CFSM> m_StateInitial;
public:
	CFSM();
	virtual ~CFSM(){}
	virtual void Update();
	bool IsState(CState &state);
	bool GotoState(CState &newState);
	virtual void BeginStateInitial(){}
	virtual void StateInitial(){}
	virtual void EndStateInitial(){}

};

#endif // 