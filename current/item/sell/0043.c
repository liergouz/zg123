#include <equip.h>
#include <ansi.h>
inherit USABLE;
inherit ITEM;

int get_item_value() {return 20 ;}
int get_item_value_2() {return 20 ;}
int get_item_number() {return 10001070 ;}
int get_item_color() {return 1 ;}

// ���������촦��
void create()
{
        set_name("����֥��");
        set_picid_1(3234);
        set_picid_2(3234);
        set_value(40);
}

// ��������ȡ����
string get_desc()
{
        return "��ͬ��Ѱ����֥�飬����ʱ�ǽڽڵͣ�\n�ɲ��ܵȼ����ƽ�����Լ��ȼ��׶ε͵ĸ���������\nÿ�ν�����Լ��ȼ��׶ε͵ĸ������Զ�����һ������֥�顣";
}
