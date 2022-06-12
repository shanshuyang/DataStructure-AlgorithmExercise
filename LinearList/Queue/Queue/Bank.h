//模拟银行活动--银行状态
#pragma once
#ifndef _Bank_H
#define _Bank_H
#include "Event.h"
#include "apQueue.h"

struct tellerStatus					//出纳窗口信息 
{
	int finishService;				//空闲时刻预告，即窗口当前客户什么时候可服务完毕
	int totalCustomerCount;			//该出纳员服务过的客户总数
	int totalCustomerWait;			//该窗口客户总的等待时间
	int totalService;				//该出纳员总的服务时间
};
typedef struct tellerStatus TellerStatus;

struct simulation					//模拟结构数据
{
	int simulationLength;			//模拟时间长度
	int numTellers;					//出纳窗口数
	int nextCustomer;				//下一个客户编号
	int arrivalLow, arrivalHigh;	//下一客户到达的时间区间
	int serviceLow, serviceHigh;	//客户需要服务的时间区间
	TellerStatus tstat[11];			//出纳窗口信息
	PQueue pq;						//优先级队列
};
typedef struct simulation Simulation;

/// <summary>
/// 事件驱动模拟的初始化
/// </summary>
/// <param name="s">指向模拟事件的指针</param>
void InitSimulation(Simulation* s);	
/// <summary>
/// 计算下一客户到达的时间
/// </summary>
/// <param name="s">指向模拟事件的指针</param>
/// <returns>返回下一个客户到达的时间</returns>
int NextArrivalTime(Simulation* s);				
/// <summary>
/// 计算客户的服务时间
/// </summary>
/// <param name="s">指向模拟事件的指针</param>
/// <returns>返回客户的服务时间</returns>
int GetServiceTime(Simulation* s);				
/// <summary>
/// 计算下一个可供服务的出纳窗口号
/// </summary>
/// <param name="s">指向模拟事件的指针</param>
/// <returns>返回下一个可用的出纳窗口号</returns>
int NextAvailableTeller(Simulation* s);			
/// <summary>
/// 运行事件驱动模拟
/// </summary>
/// <param name="s">指向模拟事件的指针</param>
void RunSimulation(Simulation* s);				
/// <summary>
/// 输出模拟结果
/// </summary>
/// <param name="s">指向模拟事件的指针</param>
void PrintSimulationResults(Simulation* s);		

#endif // !_Bank_H
