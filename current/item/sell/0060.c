
#include <effect.h>
#include <skill.h>
#include <ansi.h>

inherit ITEM;
inherit COMBINED;
inherit USABLE;

// ��������Ҫȷ������
int confirm_sell_item() { return 1; }

int get_item_value() {return 15 ;}
int get_item_value_2() {return 15 ;}
int get_item_number() {return 10001075 ;}
int get_item_color() {return 2 ;}

// ���������촦��
void create()
{
        set_name( "�˲���" );
        set_picid_1(9943);
        set_picid_2(9943);
        set_unit( "��" );
        set_value(800);
        set_amount(1);
        set_record(1);
        set("effect", 2000);
}

// ��������ȡ����
string get_desc() 
{ 
        return "��˵�Ǿ���ḻ���ϲ�ũ�ڳ���ɽ�ڵ����˲�֮������������׹ǵĹ�Ч��\n����1Сʱ�ڿ��������2000����Ѫ���ޡ�\n��ȴʱ��2�롣";
}

string get_short()
{
	return "����1Сʱ�ڿ��������2000����Ѫ���ޡ�";
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return "/item/sell/0006"->get_use_effect_callout(me,this_object()); }


// ������ʹ��Ч��
int confirm_use( object me ) { return "/item/sell/0006" ->confirm_use_callout( me, this_object() ); }
