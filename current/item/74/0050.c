
#include <equip.h>

inherit WEAPON;

// ���������촦��
void create()
{
        set_name("���ǹ");
        set_picid_1(7405);
        set_picid_2(7405);
        set_unit("��");

        set_level(50);
        set_value(12000);
        set_max_lasting(13599);
        set("ap", 95);
        set("!%", 6);

        setup();

        set_weapon_type(SPEAR);
}

// ��������ȡ��������
int get_weapon_level() { return 5; }

// ��������ȡ����
string get_desc()
{
        return "��ǹ����װ��";
}
