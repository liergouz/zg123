
#include <equip.h>

inherit WEAPON;

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(7505);
        set_picid_2(7505);
        set_unit("��");

        set_level(50);
        set_value(12000);
        set_max_lasting(13599);
        set("ap", 102);

        setup();

        set_weapon_type(STICK);
}

// ��������ȡ��������
int get_weapon_level() { return 5; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
