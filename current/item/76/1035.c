
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(7320);
        set_picid_2(7320);

        set_level(35);
        set_value(8500);
        set_max_lasting(14099);
        set("ap", 82);
        set("dp", 10);
        set("cp", 85);
        set("sp", 9);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_04; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
