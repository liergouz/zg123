#include <equip.h>
#include <ansi.h>
inherit USABLE;
inherit ITEM;

int is_key() {return 1;}

int get_item_value() {return 26 ;}
int get_item_value_2() {return 26 ;}
int get_item_number() {return 10001067 ;}
int get_item_color() {return 2 ;}

// ���������촦��
void create()
{
        set_name("��ͭԿ��");
        set_picid_1(6703);
        set_picid_2(6703);
        set_level(2);
        set_value(50);
}

// ��������ȡ����
string get_desc()
{
        return "�����ܿ����������䱦�صı��䡣\n��Կ���Ϸ��ڷŴ�״̬�ı���֮�ϣ���ɽ�"HIR"��ͭ����"NOR"�򿪡�";
}
