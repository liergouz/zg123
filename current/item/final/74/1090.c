
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 3; }

// ��������Ʒ���
int get_fin_type() { return 1045; }

// ���������촦��
void create()
{
        set_name("����ǹ");
        set_picid_1(7417);
        set_picid_2(7417);

        set_level(90);
        set_value(9000);
        set_max_lasting(14599);
        set("ap", 228);
        set("dp", 10);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(SPEAR);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_10; }

// ��������ȡ����
string get_desc()
{
        return "��ǹ����װ��";
}
