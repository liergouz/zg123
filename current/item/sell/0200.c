#include <equip.h>
#include <ansi.h>
inherit USABLE;
inherit ITEM;

int is_key() {return 1;}

int get_item_value() {return 15 ;}
int get_item_value_2() {return 15 ;}
int get_item_number() {return 10001066 ;}
int get_item_color() {return 1 ;}

// ���������촦��
void create()
{
        set_name("��ľԿ��");
        set_picid_1(6701);
        set_picid_2(6701);
        set_level(1);
        set_value(50);
}

// ��������ȡ����
string get_desc()
{
        return "�����ܿ����������䱦�صı��䡣\n��Կ���Ϸ��ڷŴ�״̬�ı���֮�ϣ���ɽ�"HIR"��ľ����"NOR"�򿪡�";
}
