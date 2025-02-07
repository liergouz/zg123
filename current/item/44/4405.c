#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;   

// ��������������
//  int get_max_combined() { return 30; }

// ��������ʹ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_PET; }
//������Ʒ
int is_pet_item() { return 1;}
// ���������촦��
void create()
{
        set_name("����ǿ����");
        set_picid_1(0088);
        set_picid_2(0088);
        set_unit("��");
        set_value(5000);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{
	string desc;
	return desc = "�������������ٻ�ʱ�����ҩ��\n�������������ٻ�ʹ�ã�ʹ�ú����������ٴ��ٻ�ʱ���10��������Ϊ0���ӣ�";
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return __FILE__->get_use_effect_call(me, this_object()); }

int get_use_effect_call(object me,object item)
{
	int i,now;
	if ( !me->is_pet() )
		return 0;
	i = me->get_dead_time();
	now = time();
	if ( now - i > 600 )
		return 0;
	me->set_dead_time(0);
	if( me->get_owner() )
		send_user(me->get_owner(),"%c%c%d%d", 0xA1,4,getoid(me),0);
	return 1;	
}