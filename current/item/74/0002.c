
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 8; }

// ���������촦��
void create()
{
        set_name("��ì");
        set_picid_1(7400);
        set_picid_2(7400);

        set_level(0);
        set_value(450);
        set_max_lasting(4599);
        set("ap", 26);
        set("dp", 0);
        set("cp", 0);
        set("sp", -4);

        setup();

        set_weapon_type(SPEAR);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_01; }

// ��������ȡ����
string get_desc()
{
        return "��ǹ����װ��";
}
