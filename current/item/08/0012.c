#include <ansi.h>
#include <item.h>
#include <skill.h>

inherit COMBINED;
inherit ITEM;

int get_item_type() { return ITEM_TYPE_SPECIAL; }

int is_mirror() {return 1;}

// ���������촦��
void create()
{
        set_name("�ƽ������");
        set_picid_1(3564);
        set_picid_2(3564);
        set_value(5000);
        set("level2", 1000);
        set_amount(1);
}

int is_usable() {return 1;}

// ��������ȡ����
string get_desc() 
{		
	return "�з����ľ��ӣ������ӷ��õ�Ҫ������װ�������ɡ�\n���Լ�������װ����";
}
