
#include <equip.h>

inherit MISSILE;

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(7105);
        set_picid_2(7105);
        set_unit("��");

        set_level(50);
        set_value(12000);
        set_max_lasting(15099);
        set("ap", 57);
        set("t!%", 10);

        setup();

        set_weapon_type(THROWING);
}

// ��������ȡ��������
int get_weapon_level() { return 5; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
