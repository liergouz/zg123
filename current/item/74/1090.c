
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("��ǹ");
        set_picid_1(7417);
        set_picid_2(7417);

        set_level(90);
        set_value(37000);
        set_max_lasting(21599);
        set("ap", 207);
        set("dp", 0);
        set("cp", 0);
        set("sp", -38);

        setup();

        set_weapon_type(SPEAR);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_11; }

// ��������ȡ����
string get_desc()
{
        return "��ǹ����װ��";
}
