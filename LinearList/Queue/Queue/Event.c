#include "Event.h"

//事件初始化的函数
void InitEvent(Event* e, int t, EventTpye et, int cn, int tn, int wt, int st)
{
	e->time = t;
	e->eType = et;
	e->customerID = cn;
	e->tellerID = tn;
	e->waitTime = wt;
	e->serviceTime = st;
}