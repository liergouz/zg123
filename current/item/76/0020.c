
#include <equip.h>

inherit WEAPON;

// ���������촦��
void create()
{
        set_name("���ƽ�");
        set_picid_1(7302);
        set_picid_2(7302);
        set_unit("��");

        set_level(20);
        set_value(1800);
        set_max_lasting(4099);
        set("ap", 6);
        set("cp", 40);
        set("c!%", 7);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return 2; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
