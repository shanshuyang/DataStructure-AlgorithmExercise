#include "Bank.h"
#include <stdio.h>
#include <stdlib.h>

//�¼�����ģ��ĳ�ʼ��
void InitSimulation(Simulation* s)
{
	int i;
	Event* firstEvent = (Event*)malloc(sizeof(Event));
	//Ԥ��10�����ɴ���
	for (i = 1; i <= 10; i++)
	{
		s->tstat[i].finishService = 0;
		s->tstat[i].totalService = 0;
		s->tstat[i].totalCustomerWait = 0;
		s->tstat[i].totalCustomerCount = 0;
	}
	s->nextCustomer = 1;

	//�����¼�ģ���������
	printf("Enter the simulation time in minutes: ");
	scanf_s("%d", &s->simulationLength);
	printf("Enter the number of bank tellers: ");
	scanf_s("%d", &s->numTellers);
	printf("Enter the range of arrival times in minutes (separate with ,): ");
	scanf_s("%d,%d", &s->arrivalLow, &s->arrivalHigh);
	printf("Enter the range of service times in minutes (separate with ,): ");
	scanf_s("%d,%d", &s->serviceLow, &s->serviceHigh);

	//���ɵ�һ���ﵽ�¼��������¼����ȼ�����
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

//������һ�ͻ������ʱ��
int NextArrivalTime(Simulation* s)
{
	return s->arrivalLow + rand() % (s->arrivalHigh - s->arrivalLow + 1); //�����arrivalLow��arrivalHigh֮��
}

//����ͻ��ķ���ʱ��
int GetServiceTime(Simulation* s)
{
	return s->serviceLow + rand() % (s->serviceHigh - s->serviceLow + 1); //�����serviceLow��serviceHigh֮��
}


//������һ���ɹ�����ĳ��ɴ��ں�
int NextAvailableTeller(Simulation* s)
{
	int minfinish = s->tstat[1].finishService;
	int num[1000]; //��¼���ɹ�����Ĵ��ں�
	int minfinishindex = 1;
	int m = 1; //��¼���ɹ�����Ĵ�����
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
	minfinishindex = num[rand() % m]; //�����ɹ�����Ĵ��ں������ѡ��һ��
	return minfinishindex;
}

//�����¼�����ģ��
void RunSimulation(Simulation* s)
{
	Event* e = (Event*)malloc(sizeof(Event));
	Event* newevent = (Event*)malloc(sizeof(Event));
	int nexttime, tellerID, servicetime, waittime;
	while (!PQEmpty(&(s->pq)))
	{
		*e = PQDelete(&(s->pq));
		if (e->eType == arrival) //�������¼�
		{
			nexttime = e->time + NextArrivalTime(s);
			if (nexttime>s->simulationLength)
			{
				//����ﵽ�¼����°�ʱ��֮���򲻴���ﵽ�¼�
				continue;
			}
			else
			{
				//������һ�ͻ��ﵽ�¼��������¼����ȼ�����
				s->nextCustomer++;
				InitEvent(newevent, nexttime, arrival, s->nextCustomer, 0, 0, 0);
				PQInsert(&(s->pq), *newevent);
			}
			printf("Time: %2d\t arrival of customer %d\n", e->time, e->customerID);
			
			//���ɴﵽ�¼����뿪�¼�
			servicetime = GetServiceTime(s);
			tellerID = NextAvailableTeller(s);
			if (s->tstat[tellerID].finishService==0)
			{
				s->tstat[tellerID].finishService = e->time;
			}
			//����ȴ�ʱ��
			waittime = s->tstat[tellerID].finishService - e->time; //���ʱ�̼�ȥ�¼��ﵽʱ�̼��ɵõ��ȴ�ʱ��
			//�޸ĳ��ɴ��ڵ������Ϣ
			s->tstat[tellerID].totalCustomerWait += waittime;
			s->tstat[tellerID].totalCustomerCount++;
			s->tstat[tellerID].totalService += servicetime;
			s->tstat[tellerID].finishService += servicetime;

			//���ɵ��뿪�¼��������ȼ�����
			InitEvent(newevent, s->tstat[tellerID].finishService, departure, e->customerID, tellerID, waittime, servicetime);
			PQInsert(&(s->pq), *newevent);
		}
		else //�����뿪�¼�
		{
			printf("Time: %2d\t departure of customer %d\n", e->time, e->customerID);
			printf("\t Teller %d\t Wait %d\t Service %d\n", e->tellerID, e->waitTime, e->serviceTime);
			tellerID = e->tellerID;
			//��������ڴ����뿪�¼�����У����޸ĸó��ɴ��ڵĿ���ʱ��Ԥ��
			if (e->time == s->tstat[tellerID].finishService)
			{
				s->tstat[tellerID].finishService = 0;
			}
		}
	}
	//�޸��ܵķ���ʱ��
	s->simulationLength = (e->time <= s->simulationLength) ? s->simulationLength : e->time;
}

//���ģ����
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