#include <item.h>
#include <ansi.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit USABLE;
inherit COMBINED;

int get_item_value() {return 750 ;}
int get_item_value_2() {return 650 ;}
int get_item_number() {return 10001014 ;}
int get_item_color() {return 1 ;}

// ���������촦��
void create()
{
        set_name( "����ϴ����" );
        set_picid_1(9174);
        set_picid_2(9174);
        set_value(50);
        set_amount(1);
        set_record(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "�ܷ�����������������������浤ҩ��";
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me); }

// ������ʹ��Ч��(���߸���)
int get_use_effect_callout( object me )
{
        int point;
	point = me->get_str_2();             
	if (point==0) 
	{
		send_user(me, "%c%s", '!', "�㲢�޷�������������У�����ʹ��ϴ���衣");
		return 0;      
	}        
	me->set_str_2(0);
	me->add_gift_point(point);
	write_user(me, ECHO "��ɹ�ϴ����%d���������", point);
	return 1;	                        
} 