
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 3; }

// ��������Ʒ���
int get_fin_type() { return 1057; }

// ���������촦��
void create()
{
        set_name("ڤ�⺮�");
        set_picid_1(7422);
        set_picid_2(7422);

        set_level(110);
        set_value(11000);
        set_max_lasting(16099);
        set("ap", 269);
        set("dp", 0);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(SPEAR);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_12; }

// ��������ȡ����
string get_desc()
{
        return "��ǹ����װ��";
}
