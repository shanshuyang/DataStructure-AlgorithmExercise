//ģ�����л--����״̬
#pragma once
#ifndef _Bank_H
#define _Bank_H
#include "Event.h"
#include "apQueue.h"

struct tellerStatus					//���ɴ�����Ϣ 
{
	int finishService;				//����ʱ��Ԥ�棬�����ڵ�ǰ�ͻ�ʲôʱ��ɷ������
	int totalCustomerCount;			//�ó���Ա������Ŀͻ�����
	int totalCustomerWait;			//�ô��ڿͻ��ܵĵȴ�ʱ��
	int totalService;				//�ó���Ա�ܵķ���ʱ��
};
typedef struct tellerStatus TellerStatus;

struct simulation					//ģ��ṹ����
{
	int simulationLength;			//ģ��ʱ�䳤��
	int numTellers;					//���ɴ�����
	int nextCustomer;				//��һ���ͻ����
	int arrivalLow, arrivalHigh;	//��һ�ͻ������ʱ������
	int serviceLow, serviceHigh;	//�ͻ���Ҫ�����ʱ������
	TellerStatus tstat[11];			//���ɴ�����Ϣ
	PQueue pq;						//���ȼ�����
};
typedef struct simulation Simulation;

/// <summary>
/// �¼�����ģ��ĳ�ʼ��
/// </summary>
/// <param name="s">ָ��ģ���¼���ָ��</param>
void InitSimulation(Simulation* s);	
/// <summary>
/// ������һ�ͻ������ʱ��
/// </summary>
/// <param name="s">ָ��ģ���¼���ָ��</param>
/// <returns>������һ���ͻ������ʱ��</returns>
int NextArrivalTime(Simulation* s);				
/// <summary>
/// ����ͻ��ķ���ʱ��
/// </summary>
/// <param name="s">ָ��ģ���¼���ָ��</param>
/// <returns>���ؿͻ��ķ���ʱ��</returns>
int GetServiceTime(Simulation* s);				
/// <summary>
/// ������һ���ɹ�����ĳ��ɴ��ں�
/// </summary>
/// <param name="s">ָ��ģ���¼���ָ��</param>
/// <returns>������һ�����õĳ��ɴ��ں�</returns>
int NextAvailableTeller(Simulation* s);			
/// <summary>
/// �����¼�����ģ��
/// </summary>
/// <param name="s">ָ��ģ���¼���ָ��</param>
void RunSimulation(Simulation* s);				
/// <summary>
/// ���ģ����
/// </summary>
/// <param name="s">ָ��ģ���¼���ָ��</param>
void PrintSimulationResults(Simulation* s);		

#endif // !_Bank_H
