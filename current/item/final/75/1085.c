
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 3; }

// ��������Ʒ���
int get_fin_type() { return 1134; }

// ���������촦��
void create()
{
        set_name("�Ż�������");
        set_picid_1(7521);
        set_picid_2(7521);

        set_level(85);
        set_value(8500);
        set_max_lasting(13599);
        set("ap", 211);
        set("dp", 15);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(STICK);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_09; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
