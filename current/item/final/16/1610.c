#include <item.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;

// ��������������
int get_max_combined() { return 30; }

// ��������Ʒ���
int get_fin_type() { return 1610; }

// ���������촦��
void create()
{
        set_name( "��������" );
        set_picid_1(4212);
        set_picid_2(4212);
        set_value(1100);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "һЩ���صĻ�������";
}

