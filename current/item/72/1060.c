
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
        set_picid_1(7216);
        set_picid_2(7216);

        set_level(60);
        set_value(22000);
        set_max_lasting(17599);
        set("ap", 140);
        set("dp", 0);
        set("cp", 0);
        set("sp", 0);

        setup();

        set_weapon_type(BLADE);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_07; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
