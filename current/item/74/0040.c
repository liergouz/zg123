
#include <equip.h>

inherit WEAPON;

// ���������촦��
void create()
{
        set_name("����ǹ");
        set_picid_1(7404);
        set_picid_2(7404);
        set_unit("��");

        set_level(40);
        set_value(6000);
        set_max_lasting(12599);
        set("ap", 78);
        set("!%", 5);

        setup();

        set_weapon_type(SPEAR);
}

// ��������ȡ��������
int get_weapon_level() { return 4; }

// ��������ȡ����
string get_desc()
{
        return "��ǹ����װ��";
}
