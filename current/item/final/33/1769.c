
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

// ��������Ʒ���
int get_fin_type() { return 1769; }

// ���������촦��
void create()
{
        set_name("�����");
        set_picid_1(3288);
        set_picid_2(3288);
        set_unit("��");
        set_value(1700);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{
	string desc;
	return desc = "���ٻ���ʳ�õ�һ�ֹ��ӣ�ÿʳ��һ�Σ�������������\n��ǰ������10��������1�������ж���";
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return __FILE__->get_use_effect_call(me, this_object()); }

int get_use_effect_call(object me,object item)
{
	object owner;
	if ( !me->is_pet() )
		return 0;
	me->add_life(10);
	owner = me->get_owner();
	tell_user(owner,"���"+me->get_name()+"��������10��");
	if( !random100() )
	{
		me->add_life(-200);
		send_user(owner,"%c%s",'!',"���"+me->get_name()+"�ж��ˣ�");
	}
	return 1;	
}