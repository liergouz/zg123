
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
        set_picid_1(7414);
        set_picid_2(7414);

        set_level(45);
        set_value(14000);
        set_max_lasting(15599);
        set("ap", 116);
        set("dp", 0);
        set("cp", 0);
        set("sp", -20);

        setup();

        set_weapon_type(SPEAR);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_05; }

// ��������ȡ����
string get_desc()
{
        return "��ǹ����װ��";
}
