
#include <equip.h>

inherit WEAPON;

// ���������촦��
void create()
{
        set_name("��׶ǹ");
        set_picid_1(7402);
        set_picid_2(7402);
        set_unit("��");

        set_level(20);
        set_value(1800);
        set_max_lasting(8599);
        set("ap", 44);
        set("!%", 3);

        setup();

        set_weapon_type(SPEAR);
}

// ��������ȡ��������
int get_weapon_level() { return 2; }

// ��������ȡ����
string get_desc()
{
        return "��ǹ����װ��";
}
