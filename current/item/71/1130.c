
#include <equip.h>

inherit MISSILE;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("����");
        set_picid_1(7123);
        set_picid_2(7123);
        set_unit("��");

        set_level(130);
        set_value(33000);
        set_max_lasting(36099);
        set("ap", 257);
        set("t!%", 20);
        set("spec.hp", 176);
        set("spec.mp", 176);
        set("spec.mp*", 2);

        setup();

        set_weapon_type(THROWING);
}

// ��������ȡ��������
int get_weapon_level() { return 23; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
