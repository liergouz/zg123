#include <item.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;

// ��������������
int get_max_combined() { return 30; }

// ��������Ʒ���
int get_fin_type() { return 1615; }

// ��������ʹ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_KEY; }

// ���������촦��
void create()
{
        set_name( "��Կ��" );
        set_picid_1(4182);
        set_picid_2(4182);
        set_value(1600);
        set_amount(1);
        set_level(3);
}

// ��������ȡ����
string get_desc() 
{ 
        return "���Դ򿪴����Կ��";
}

