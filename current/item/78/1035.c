
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 6; }

// ���������촦��
void create()
{
        set_name("����");
        set_picid_1(7620);
        set_picid_2(7620);

        set_level(35);
        set_value(15000);
        set_max_lasting(5799);
        set("ap", 70);
        set("dp", 0);
        set("cp", 120);
        set("sp", 0);

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
