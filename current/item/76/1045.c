
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
        set_picid_1(7301);
        set_picid_2(7301);

        set_level(45);
        set_value(14000);
        set_max_lasting(15599);
        set("ap", 101);
        set("dp", 12);
        set("cp", 115);
        set("sp", 11);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_05; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
