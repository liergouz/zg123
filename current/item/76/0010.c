
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 8; }

// ���������촦��
void create()
{
        set_name("׷�罣");
        set_picid_1(7322);
        set_picid_2(7322);

        set_level(10);
        set_value(900);
        set_max_lasting(9099);
        set("ap", 32);
        set("dp", 5);
        set("cp", 0);
        set("sp", 4);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_02; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
