
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 6; }

// ���������촦��
void create()
{
        set_name("ڤ�ƽ�");
        set_picid_1(7620);
        set_picid_2(7620);

        set_level(30);
        set_value(12000);
        set_max_lasting(5599);
        set("ap", 60);
        set("dp", 0);
        set("cp", 105);
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
