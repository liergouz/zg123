#include <equip.h>
#include <ansi.h>
inherit USABLE;
inherit ITEM;

int is_key() {return 1;}

int get_item_value() {return 32 ;}
int get_item_value_2() {return 32 ;}
int get_item_number() {return 10001068 ;}
int get_item_color() {return 2 ;}

// ���������촦��
void create()
{
        set_name("�Ͻ�Կ��");
        set_picid_1(6705);
        set_picid_2(6705);
        set_level(3);
        set_value(50);
}

// ��������ȡ����
string get_desc()
{
        return "�����ܿ����������䱦�صı��䡣\n��Կ���Ϸ��ڷŴ�״̬�ı���֮�ϣ���ɽ�"HIR"�Ͻ���"NOR"�򿪡�";
}
