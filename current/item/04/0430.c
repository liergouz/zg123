#include <ansi.h>
#include <effect.h>
#include <skill.h>

inherit ITEM;
inherit USABLE;

// ��������Ҫȷ������
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
int confirm_sell_item() { return 1; }

// ���������촦��
void create()
{
        set_name("�����ɿ���");
        set_picid_1(0057);
        set_picid_2(0057);
        set_unit("��");
        set_value(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return ("Ԣ�⣺�������\nʹ�ú�����������30%������60����\n"HIR"ʹ������Ϊ����");
}

// ������ʹ��Ч��
int get_use_effect( object me ) {return __FILE__ ->get_use_effect_callout(me,this_object());}

// ������ʹ��Ч��(���߸���)
int get_use_effect_callout( object me , object item )
{
	if(me->get_gender()!=1)
	{
		send_user(me,"%c%s",';',"�Բ���������ʹ�øõ��ߡ�");
		return 0;
	}
	write_user(me,ECHO"���õ�"+item->get_user_id()+"������ף����������������30����");
	send_user( me, "%c%w%w%c", 0x81, 0430, 3600, EFFECT_GOOD );
        set_effect(me, EFFECT_ITEM_9165, 3600);
	me->set_save( "9165#", 30 );
        USER_ENERGY_D->count_pp(me);
        return 1;
}

void effect_done(object me)
{
        send_user( me, "%c%w%w%c", 0x81, 0430, 0, EFFECT_GOOD );
}

// ��������ȡ����(����)
string get_loop_desc( object me )
{
        return "һСʱ�����ӷ���������30����\n";
}