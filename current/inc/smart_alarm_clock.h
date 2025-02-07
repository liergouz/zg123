#ifndef _SMART_ALARM_CLOCK_H_
#define _SMART_ALARM_CLOCK_H_

#define SAC_TIME_CACHE		1			//	ʱ�ӻ��������룩ʵ�ʻ��巶ΧӦ����������ֵ�2��
#define SAC_TAG_YEAR		"year"			//	�������־
#define SAC_TAG_MONTH		"month"			//	�����±�־
#define SAC_TAG_WEEK		"week"			//	�����ܱ�־
#define SAC_TAG_DAY		"day"			//	�������־
#define SAC_TAG_HOUR		"hour"			//	����ʱ��־
#define SAC_TAG_MINUTE		"minute"		//	����ֱ�־
#define SAC_TAG_SECOND		"second"		//	�������־

#define SAC_MAX_TIMES		5000000			//	�����Ѱ����
#define CYCLE_MINUTE		(60)			//	Ԥ����ķ�������
#define CYCLE_HOUR		(60*60)			//	Ԥ�����Сʱ����
#define CYCLE_DAY		(60*60*24)		//	Ԥ�����һ������
#define CYCLE_WEEK		(60*60*24*7)		//	Ԥ�������������
#endif

