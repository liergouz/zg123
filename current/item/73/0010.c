
#include <equip.h>

inherit WEAPON;

// ���������촦��
void create()
{
        set_name("��潣");
        set_picid_1(7301);
        set_picid_2(7301);
        set_unit("��");

        set_level(10);
        set_value(900);
        set_max_lasting(6099);
        set("ap", 22);
        set("!%", 8);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return 1; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
