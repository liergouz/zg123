
#include <equip.h>

inherit WEAPON;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("��ڤ��");
        set_picid_1(7316);
        set_picid_2(7316);
        set_unit("��");

        set_level(60);
        set_value(22000);
        set_max_lasting(17099);
        set("ap", 130);
        set("!%", 18);
        set("spec.hp", 80);
        set("spec.hp*", 2);
        set("spec.mp*", 2);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return 16; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
