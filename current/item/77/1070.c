
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 5; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(7618);
        set_picid_2(7618);

        set_level(70);
        set_value(36000);
        set_max_lasting(7599);
        set("ap", 140);
        set("dp", 0);
        set("cp", 220);
        set("sp", 0);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_09; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
