
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("ڤ������");
        set_picid_1(7520);
        set_picid_2(7520);

        set_level(100);
        set_value(42000);
        set_max_lasting(24099);
        set("ap", 238);
        set("dp", -42);
        set("cp", 0);
        set("sp", 0);

        setup();

        set_weapon_type(STICK);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_12; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
