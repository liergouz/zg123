
#include <equip.h>
inherit USABLE;
inherit ITEM;

// ���������촦��
void create()
{
        set_name("����ʹ������ҩ");
        set_picid_1(7120);
        set_picid_2(7120);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1); 
}

// ��������ȡ����
string get_desc()
{
	string result;
	object me = this_player();
	result = "������Ʒ��һ�����˵�ҩ�ۡ�\n";
	if (me->get_save_2("orgtask2.type")==1)
		result += sprintf("���ٽ���ҩ����%s��%s�Ų\n", me->get_save_2("orgtask2.place"), me->get_org_name());
        return result;
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout( me, this_object() ); }

// ������ʹ��Ч��(���߸���)
int get_use_effect_callout( object me, object item )
{
	if ( me->get_save_2("orgtask2.type")!=1 )
		return 1;
}