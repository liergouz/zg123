
#include <equip.h>

inherit WEAPON;

// ���������촦��
void create()
{
        set_name("��ѧ��ľ��");
        set_picid_1(7200);
        set_picid_2(7200);
        set_unit("��");

        set_level(0);
        set_value(50);
        set_max_lasting(3599);
        set("ap", 8);
        set("dp", 2);

        setup();

        set_weapon_type(BLADE);
}

// ��������ȡ��������
int get_weapon_level() { return 0; }

// ��������ȡ����
string get_desc()
{
        return "һ��ľ�Ƶ����������ܰ���ʹ���߸�����������";
}
