
#include <equip.h>

inherit WEAPON;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("��ڤ��");
        set_picid_1(7322);
        set_picid_2(7322);
        set_unit("��");

        set_level(120);
        set_value(52000);
        set_max_lasting(26099);
        set("ap", 238);
        set("!%", 30);
        set("spec.hp", 200);
        set("spec.hp*", 6);
        set("spec.mp*", 6);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return 22; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
