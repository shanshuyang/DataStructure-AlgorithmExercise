//ģ�����л--�ͻ��¼�
#pragma once
#ifndef _Event_H
#define _Event_H

enum eventTpye
{
	arrival,
	departure
};
typedef enum eventTpye EventTpye;

struct event			//�ͻ����¼���Ϣ
{
	int time;			//�¼�������ʱ�䣨�ͻ�����/�뿪��ʱ�̣�
	EventTpye eType;	//�¼����ͣ�����/�뿪��
	int customerID;		//�ͻ����
	int tellerID;		//�ͻ�ѡ�����Ĵ��ڱ��
	int waitTime;		//�ͻ�����ȴ���ʱ��
	int serviceTime;	//�ͻ���Ҫ�����ʱ��
};
typedef struct event Event;

/// <summary>
/// �¼���ʼ���ĺ���
/// </summary>
/// <param name="e">�¼�ָ��</param>
/// <param name="t">�¼�������ʱ��</param>
/// <param name="et">�¼�����</param>
/// <param name="cn">�ͻ����</param>
/// <param name="tn">�ͻ�ѡ�����Ĵ��ڱ��</param>
/// <param name="wt">�ͻ�����ȴ���ʱ��</param>
/// <param name="st">�ͻ���Ҫ�����ʱ��</param>
void InitEvent(Event* e, int t, EventTpye et, int cn, int tn, int wt, int st);

#endif // !_Event_H
