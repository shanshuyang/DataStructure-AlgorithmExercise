#include "Bank.h"
#include <stdio.h>
#include <stdlib.h>

//事件驱动模拟的初始化
void InitSimulation(Simulation* s)
{
	int i;
	Event* firstEvent = (Event*)malloc(sizeof(Event));
	//预设10个出纳窗口
	for (i = 1; i <= 10; i++)
	{
		s->tstat[i].finishService = 0;
		s->tstat[i].totalService = 0;
		s->tstat[i].totalCustomerWait = 0;
		s->tstat[i].totalCustomerCount = 0;
	}
	s->nextCustomer = 1;

	//输入事件模拟相关数据
	printf("Enter the simulation time in minutes: ");
	scanf_s("%d", &s->simulationLength);
	printf("Enter the number of bank tellers: ");
	scanf_s("%d", &s->numTellers);
	printf("Enter the range of arrival times in minutes (separate with ,): ");
	scanf_s("%d,%d", &s->arrivalLow, &s->arrivalHigh);
	printf("Enter the range of service times in minutes (separate with ,): ");
	scanf_s("%d,%d", &s->serviceLow, &s->serviceHigh);

	//生成第一个达到事件并加入事件优先级队列
	InitEvent(firstEvent, 0, arrival, 1, 0, 0, 0);
	InitPQueue(&(s->pq));
	if (firstEvent != NULL)
	{
		PQInsert(&(s->pq), *firstEvent);
	}
	else
	{
		printf("Initialization failed");
	}
}

//计算下一客户到达的时间
int NextArrivalTime(Simulation* s)
{
	return s->arrivalLow + rand() % (s->arrivalHigh - s->arrivalLow + 1); //结果在arrivalLow到arrivalHigh之间
}

//计算客户的服务时间
int GetServiceTime(Simulation* s)
{
	return s->serviceLow + rand() % (s->serviceHigh - s->serviceLow + 1); //结果在serviceLow到serviceHigh之间
}


//计算下一个可供服务的出纳窗口号
int NextAvailableTeller(Simulation* s)
{
	int minfinish = s->tstat[1].finishService;
	int num[1000]; //记录最快可供服务的窗口号
	int minfinishindex = 1;
	int m = 1; //记录最快可供服务的窗口数
	num[0] = 1;
	for (int i = 2; i <= s->numTellers; i++)
	{
		if (s->tstat[i].finishService < minfinish)
		{
			minfinish = s->tstat[i].finishService;
			num[0] = i;
			m = 1;
		}
		else
		{
			if (s->tstat[i].finishService==minfinish)
			{
				num[m++] = i;
			}
		}
	}
	minfinishindex = num[rand() % m]; //从最快可供服务的窗口号中随机选出一个
	return minfinishindex;
}

//运行事件驱动模拟
void RunSimulation(Simulation* s)
{
	Event* e = (Event*)malloc(sizeof(Event));
	Event* newevent = (Event*)malloc(sizeof(Event));
	int nexttime, tellerID, servicetime, waittime;
	while (!PQEmpty(&(s->pq)))
	{
		*e = PQDelete(&(s->pq));
		if (e->eType == arrival) //处理到达事件
		{
			nexttime = e->time + NextArrivalTime(s);
			if (nexttime>s->simulationLength)
			{
				//如果达到事件在下班时刻之后，则不处理达到事件
				continue;
			}
			else
			{
				//生成下一客户达到事件并加入事件优先级队列
				s->nextCustomer++;
				InitEvent(newevent, nexttime, arrival, s->nextCustomer, 0, 0, 0);
				PQInsert(&(s->pq), *newevent);
			}
			printf("Time: %2d\t arrival of customer %d\n", e->time, e->customerID);
			
			//生成达到事件的离开事件
			servicetime = GetServiceTime(s);
			tellerID = NextAvailableTeller(s);
			if (s->tstat[tellerID].finishService==0)
			{
				s->tstat[tellerID].finishService = e->time;
			}
			//计算等待时间
			waittime = s->tstat[tellerID].finishService - e->time; //完成时刻减去事件达到时刻即可得到等待时间
			//修改出纳窗口的相关信息
			s->tstat[tellerID].totalCustomerWait += waittime;
			s->tstat[tellerID].totalCustomerCount++;
			s->tstat[tellerID].totalService += servicetime;
			s->tstat[tellerID].finishService += servicetime;

			//生成的离开事件加入优先级队列
			InitEvent(newevent, s->tstat[tellerID].finishService, departure, e->customerID, tellerID, waittime, servicetime);
			PQInsert(&(s->pq), *newevent);
		}
		else //处理离开事件
		{
			printf("Time: %2d\t departure of customer %d\n", e->time, e->customerID);
			printf("\t Teller %d\t Wait %d\t Service %d\n", e->tellerID, e->waitTime, e->serviceTime);
			tellerID = e->tellerID;
			//如果窗口在处理离开事件后空闲，则修改该出纳窗口的空闲时刻预告
			if (e->time == s->tstat[tellerID].finishService)
			{
				s->tstat[tellerID].finishService = 0;
			}
		}
	}
	//修改总的服务时间
	s->simulationLength = (e->time <= s->simulationLength) ? s->simulationLength : e->time;
}

//输出模拟结果
void PrintSimulationResults(Simulation* s)
{
	int cumCustomers = 0, cumWait = 0;
	int avgCustWait, tellerWorkPercent;
	float tellerWork;

	for (int i = 1; i <= s->numTellers; i++)
	{
		cumCustomers += s->tstat[i].totalCustomerCount;
		cumWait += s->tstat[i].totalCustomerWait;
	}

	printf("\n************Simulation Summary************\n");
	printf("Simulation of %d minutes\n", s->simulationLength);
	printf("\tNo. of Customers: %d\n", cumCustomers);
	printf("\tAverage Customer Wait:");
	avgCustWait = (int)((float)cumWait / cumCustomers + 0.5);
	printf("%d minutes\n", avgCustWait);
	for (int i = 1; i <= s->numTellers; i++)
	{
		printf("\tTeller #%d\tWorking", i);
		tellerWork = (float)(s->tstat[i].totalService) / s->simulationLength;
		tellerWorkPercent = (int)(tellerWork * 100.0 + 0.5);
		printf("%d\n", tellerWorkPercent);
	}
}