
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("����ì");
        set_picid_1(7409);
        set_picid_2(7409);

        set_level(20);
        set_value(3000);
        set_max_lasting(8099);
        set("ap", 64);
        set("dp", 0);
        set("cp", 0);
        set("sp", -10);

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
