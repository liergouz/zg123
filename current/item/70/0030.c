
#include <equip.h>

inherit WEAPON;

// ���������촦��
void create()
{
        set_name("����צ��");
        set_picid_1(7003);
        set_picid_2(7003);
        set_unit("˫");

        set_level(30);
        set_value(3300);
        set_max_lasting(11099);
        set("ap", 50);
        set("!%", 13);

        setup();

        set_weapon_type(UNARMED);
}

// ��������ȡ��������
int get_weapon_level() { return 3; }

// ��������ȡ����
string get_desc()
{
        return "��ȭ����װ��";
}
