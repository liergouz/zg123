
#include <equip.h>

inherit WEAPON;

// ���������촦��
void create()
{
        set_name("���");
        set_picid_1(7403);
        set_picid_2(7403);
        set_unit("��");

        set_level(30);
        set_value(3300);
        set_max_lasting(11099);
        set("ap", 61);
        set("!%", 4);

        setup();

        set_weapon_type(SPEAR);
}

// ��������ȡ��������
int get_weapon_level() { return 3; }

// ��������ȡ����
string get_desc()
{
        return "��ǹ����װ��";
}
