
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 3; }

// ��������Ʒ���
int get_fin_type() { return 1005; }

// ���������촦��
void create()
{
        set_name("ͭì");
        set_picid_1(7409);
        set_picid_2(7409);

        set_level(20);
        set_value(2000);
        set_max_lasting(3599);
        set("ap", 76);
        set("dp", 0);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(SPEAR);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_03; }

// ��������ȡ����
string get_desc()
{
        return "��ǹ����װ��";
}
