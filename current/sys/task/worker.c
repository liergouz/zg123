#include <ansi.h>
#include <skill.h>
#include <task.h>
#include <effect.h>

#define TIME_INTERVAL   20
#define CASH_BONUS	200
#define EXP_BONUS	50
#define POT_BONUS	5
#define SUB_STR		20

// ���������ɶ�������
void SAVE_BINARY() { }

//��ʼ��
void begin_work(object me,int iType)
{
	int iTime;
	me->set("work_type",iType);
	iTime = me->get_strength();
	set_effect_2(me, EFFECT_USER_WORK,  iTime/SUB_STR+2, TIME_INTERVAL);	//20�����һ��
	send_user(me, "%c%c%w%s", 0x5a, 0,iTime/SUB_STR*TIME_INTERVAL, "�����Ͷ��С���");
	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 02011, 10, OVER_BODY, PF_LOOP );
}
//�жϴ�
void effect_work_break(object me)
{
	set_effect(me, EFFECT_USER_WORK, 0);
	send_user(me, "%c%c%c", 0x5a, 1, 0);
	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 02011, 0, OVER_BODY, PF_STOP );
	me->delete("work_type");
}
//�򹤱���
void work_bonus(object me)
{
	int iType, money;
	iType = me->get("work_type");
	if ( me->get_strength(me) < SUB_STR )
	{
		effect_work_break(me);
		return ;
	}
	me->add_strength(-SUB_STR);
	if ( iType == NEWBIE_WORK )	//���ִ�
	{
		me->add_exp(EXP_BONUS);
		me->add_potential(POT_BONUS);
		me->add_cash(CASH_BONUS/2);
		me->add_log("&newbiework", EXP_BONUS);
		me->add_log("*newbiework", POT_BONUS);
		me->add_log("$newbiework", CASH_BONUS/2);
		me->add_log("#newbiework", 1);	
		money = CASH_BONUS/2;
		write_user( me, ECHO "ͨ�����ڵ��Ͷ���������"+EXP_BONUS+"�㾭��ֵ��"+money+"���"+POT_BONUS+"��Ǳ�ܡ�");		
	}
	else if ( iType == ZHOU_WORK )	//�ܹ�
	{
		me->add_exp(EXP_BONUS);
		me->add_cash(CASH_BONUS);
		me->log_money("����", CASH_BONUS);                
		"/sys/sys/count"->add_income("work", CASH_BONUS);
		me->add_log("&newbiework", EXP_BONUS);
		me->add_log("$newbiework", CASH_BONUS);
		me->add_log("#newbiework", 1);			
		write_user( me, ECHO "ͨ�����ڵ��Ͷ���������"+EXP_BONUS+"�㾭��ֵ��"+CASH_BONUS+"��");		
	}			
	if ( me->get_strength(me) <= 0 )
	{
		effect_work_break(me);
		return ;
	}	
}
