
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
        set_picid_1(7418);
        set_picid_2(7418);

        set_level(80);
        set_value(32000);
        set_max_lasting(20099);
        set("ap", 187);
        set("dp", 0);
        set("cp", 0);
        set("sp", -34);

        setup();

        set_weapon_type(SPEAR);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_10; }

// ��������ȡ����
string get_desc()
{
        return "��ǹ����װ��";
}
