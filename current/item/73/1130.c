
#include <equip.h>

inherit WEAPON;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("��ԯ��");
        set_picid_1(7323);
        set_picid_2(7323);
        set_unit("��");

        set_level(130);
        set_value(57000);
        set_max_lasting(27599);
        set("ap", 256);
        set("!%", 30);
        set("spec.hp", 220);
        set("spec.hp*", 6);
        set("spec.mp*", 6);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return 23; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
