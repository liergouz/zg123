
#include <equip.h>

inherit MISSILE;

// ���������촦��
void create()
{
        set_name("�ɻ�ʯ");
        set_picid_1(7104);
        set_picid_2(7104);
        set_unit("��");

        set_level(40);
        set_value(6000);
        set_max_lasting(14599);
        set("ap", 47);
        set("t!%", 9);

        setup();

        set_weapon_type(THROWING);
}

// ��������ȡ��������
int get_weapon_level() { return 4; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
