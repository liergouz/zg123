
#include <equip.h>

inherit WEAPON;
inherit LEGEND_ITEM;

// ���������촦��
void create()
{
        set_name("����үү��ľ��");
        set_picid_1(7300);
        set_picid_2(7300);
        set_unit("��");

        set_value(0);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1); 
        setup();

        set_weapon_type(-1);
}

// ��������ȡ��������
int get_weapon_level() { return 0; }

int get_equip_type() { return 0; }

// ��������ȡ����
string get_desc()
{
        return "������ߡ��������ϰ�Ҫ�󽻸�����үү��������Ʒ��";
}
