
#include <equip.h>

inherit WEAPON;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("���ɽ�");
        set_picid_1(7623);
        set_picid_2(7623);
        set_unit("��");

        set_level(130);
        set_value(72000);
        set_max_lasting(10599);
        set("ap", 205);
        set("!%", 10);
        set("cp", 270);
        set("c!%", 30);
        set("spec.mp", 220);
        set("spec.hp*", 2);
        set("spec.mp*", 8);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return 34; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
