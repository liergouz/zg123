
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("����ǹ");
        set_picid_1(7410);
        set_picid_2(7410);

        set_level(70);
        set_value(27000);
        set_max_lasting(18599);
        set("ap", 167);
        set("dp", 0);
        set("cp", 0);
        set("sp", -30);

        setup();

        set_weapon_type(SPEAR);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_09; }

// ��������ȡ����
string get_desc()
{
        return "��ǹ����װ��";
}
