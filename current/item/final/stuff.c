
// �Զ����ɣ�/make/item/make31c
#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;

// ���������촦��
void create()
{
        set_name("��Ʒ");
        set_picid_1(4905);
        set_picid_2(4905);
        set_unit("��");
        set_value(500);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{
	string desc;
	desc = "һ�����������ķ�Ʒ��";
	return desc;
}
