#include <ansi.h>
#include <equip.h>
inherit USABLE;
inherit ITEM;

int is_box() {return 1;}

// ���������촦��
void create()
{
        set_name("��ľ����");
        set_picid_1(6702);
        set_picid_2(6702);
        set_level(1);
        set_value(50);
}

// ��������ȡ����
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc()
{
        return "����Ϊ���䱦�������ܹ��ɽ����ƶ��ɣ�\n�Ҽ�������У��䴦�ڷŴ�״̬������"HIR"��ľԿ��"NOR"��������";
}

int get_use_effect( object me ) 
{
	return "/item/01/0200"->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object item) 
{
	if (who->get_2("openbox.item")) return 0;
	if (who->get_online_rate()<100)
	{
		send_user(who, "%c%s", ';', "�ǽ���ʱ�䲻�ܴ򿪱��䣡");
		return 0;
	}	
	send_user( who, "%c%c%c%d", 0x91, 1, item->get_level(), getoid(item) );
	return 0;
}