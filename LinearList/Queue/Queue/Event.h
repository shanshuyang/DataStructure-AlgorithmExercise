//模拟银行活动--客户事件
#pragma once
#ifndef _Event_H
#define _Event_H

enum eventTpye
{
	arrival,
	departure
};
typedef enum eventTpye EventTpye;

struct event			//客户及事件信息
{
	int time;			//事件发生的时间（客户到达/离开的时刻）
	EventTpye eType;	//事件类型（到达/离开）
	int customerID;		//客户编号
	int tellerID;		//客户选择服务的窗口编号
	int waitTime;		//客户必须等待的时间
	int serviceTime;	//客户需要服务的时间
};
typedef struct event Event;

/// <summary>
/// 事件初始化的函数
/// </summary>
/// <param name="e">事件指针</param>
/// <param name="t">事件发生的时间</param>
/// <param name="et">事件类型</param>
/// <param name="cn">客户编号</param>
/// <param name="tn">客户选择服务的窗口编号</param>
/// <param name="wt">客户必须等待的时间</param>
/// <param name="st">客户需要服务的时间</param>
void InitEvent(Event* e, int t, EventTpye et, int cn, int tn, int wt, int st);

#endif // !_Event_H
