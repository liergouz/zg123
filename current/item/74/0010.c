
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 8; }

// ���������촦��
void create()
{
        set_name("��ì");
        set_picid_1(7403);
        set_picid_2(7403);

        set_level(10);
        set_value(900);
        set_max_lasting(6099);
        set("ap", 44);
        set("dp", 0);
        set("cp", 0);
        set("sp", -6);

        setup();

        set_weapon_type(SPEAR);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_02; }

// ��������ȡ����
string get_desc()
{
        return "��ǹ����װ��";
}
