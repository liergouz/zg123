
#include <equip.h>

inherit WEAPON;

// ���������촦��
void create()
{
        set_name("ն��");
        set_picid_1(7204);
        set_picid_2(7204);
        set_unit("��");

        set_level(40);
        set_value(6000);
        set_max_lasting(12599);
        set("ap", 70);
        set("!%", 7);

        setup();

        set_weapon_type(BLADE);
}

// ��������ȡ��������
int get_weapon_level() { return 4; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
