#include <item.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit USABLE;


// ��������Ʒ���
int get_fin_type() { return 1507; }

// ��������Ƕʶ��
int get_item_type() { return ITEM_TYPE_SHIKE; }

// ���������촦��
void create()
{
        set_name( "�м��﹥" );
        set_picid_1(4980);
        set_picid_2(4980);
        set_value(100);
        set("app", 20);
}

// ��������ȡ����
string get_desc() 
{ 
        return "���������ø���20�﹥������";
}

