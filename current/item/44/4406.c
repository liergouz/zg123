
// �Զ����ɣ�/make/item/make31c
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
        set_name("�߼�����ʳ��");
        set_picid_1(9974);
        set_picid_2(9974);
        set_unit("��");
        set_value(400);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{
	string desc;
	return desc = "���ӳ����ҳϵ�һ�ֿ�����ÿʳ��һ�Σ��ҳ϶�����20��";
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return __FILE__->get_use_effect_call(me, this_object()); }

int get_use_effect_call(object me,object item)
{
	object owner;
	if ( !me->is_pet() )
		return 0;
	owner = me->get_owner();
	if ( me->get_faith() >= 100 )
	{
		send_user(owner,"%c%s",'!',"��ĳ���"+me->get_name()+"���ҳ϶��Ѿ���������100");
		return 0;	
	}
	tell_user(owner,"���"+me->get_name()+"�ҳ�����20��");
	me->add_faith(20);
	return 1;	
}