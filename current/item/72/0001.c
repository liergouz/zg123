
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 8; }

// ���������촦��
void create()
{
        set_name("��ѧ��ľ��");
        set_picid_1(7224);
        set_picid_2(7224);

        set_level(0);
        set_value(100);
        set_max_lasting(3599);
        set("ap", 8);
        set("dp", 0);
        set("cp", 0);
        set("sp", 0);

        setup();

        set_weapon_type(BLADE);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_01; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
