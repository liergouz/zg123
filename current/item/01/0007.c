#include <ansi.h>
#include <equip.h>
inherit USABLE;
inherit ITEM;

int get_item_color() { return 2; }

// ���������촦��
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
void create()
{
        set_name("��������");
        set_picid_1(4952);
        set_picid_2(4952);
        set_value(50);
}

// ��������ȡ����
string get_desc()
{
        return "�����ϵ���Ŵ�˵�е����ޣ��̺���ʮ��ǿ���ħ����\n�ܽ�1������������������2����\n��ҵȼ�����ﵽ45��֮�����ʹ���������塣";
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout( me, this_object() ); }

// ������ʹ��Ч��(���߸���)
int get_use_effect_callout( object me, object item )
{
	object item2;
	if (me->get_level()<45)
	{
		send_user( me, "%c%s", '!', "�㵱ǰ�ĵȼ����ͣ��޷�����ʦ������ĵȼ���" );
		return 0;
	}
	item2 = me->get_equip(FAMILY_TYPE);
	if (!item2)
	{
		send_user( me, "%c%s", '!', "��û��ʦ�����" );
		return 0;
	}	
	if (item2->is_newplayer())
	{
		send_user( me, "%c%s", '!', "����������������ﲻ����ʹ��Ҫ���޷������ȼ���" );
		return 0;
	}	
	if (item2->get_item_level()!=1)
	{
		send_user( me, "%c%s", '!', "�����������������ȼ����ߣ��޷������ȼ���" );
		return 0;
	}	
	send_user(me, "%c%c%w%s", ':', 3, 0, "��������ʹ�ú����ʧ����ȷ��Ҫʹ����\n"+ESC+"ȷ��\n"+sprintf("use ! %x#\n", getoid(item))+ESC+"ȡ��\nCLOSE\n");
	return 0;
}

// ������ʹ��Ч��
int confirm_use( object me ) { return __FILE__ ->confirm_use_callout( me, this_object() ); }

// ������ʹ��Ч��(���߸���)
int confirm_use_callout( object me, object item )
{
	object item2;
	if (me->get_level()<45)
	{
		send_user( me, "%c%s", '!', "�㵱ǰ�ĵȼ����ͣ��޷�����ʦ������ĵȼ���" );
		return 0;
	}
	item2 = me->get_equip(FAMILY_TYPE);
	if (!item2)
	{
		send_user( me, "%c%s", '!', "��û��ʦ�����" );
		return 0;
	}	
	if (item2->is_newplayer())
	{
		send_user( me, "%c%s", '!', "����������������ﲻ����ʹ��Ҫ���޷������ȼ���" );
		return 0;
	}	
	if (item2->get_item_level()!=1)
	{
		send_user( me, "%c%s", '!', "�����������������ȼ����ߣ��޷������ȼ���" );
		return 0;
	}	
	item2->set_item_level(2);
	item2->init_familyobj();	
	send_user(me, "%c%d%c", 0x31, getoid(item2), 0);
	"/sys/user/energy"->count_all_prop(me);
	return 1;
}