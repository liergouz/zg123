
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 8; }

// ���������촦��
void create()
{
        set_name("��ľ��");
        set_picid_1(7500);
        set_picid_2(7500);

        set_level(0);
        set_value(450);
        set_max_lasting(4599);
        set("ap", 28);
        set("dp", -4);
        set("cp", 0);
        set("sp", 0);

        setup();

        set_weapon_type(STICK);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_01; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
