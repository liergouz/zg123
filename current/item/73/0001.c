
#include <equip.h>

inherit WEAPON;

// ���������촦��
void create()
{
        set_name("ľ��");
        set_picid_1(7300);
        set_picid_2(7300);
        set_unit("��");

        set_level(0);
        set_value(450);
        set_max_lasting(4599);
        set("ap", 8);
        set("!%", 7);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return 0; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
