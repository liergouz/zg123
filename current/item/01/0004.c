
#include <equip.h>
inherit USABLE;
inherit ITEM;

// ���������촦��
void create()
{
        set_name("��ʧ�ı���");
        set_picid_1(4116);
        set_picid_2(4116);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1); 
}

// ��������ȡ����
string get_desc()
{
        return "������Ʒ����˵����ʧ���ر������ٽ������ͻر����ɵ��ܹܴ���";
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout( me, this_object() ); }

// ������ʹ��Ч��(���߸���)
int get_use_effect_callout( object me, object item )
{
	if ( me->get_save_2("orgtask2.type")!=3 )
		return 1;
}