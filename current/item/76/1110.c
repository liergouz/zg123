
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("ڤ���Ȼ�");
        set_picid_1(7616);
        set_picid_2(7616);

        set_level(110);
        set_value(47000);
        set_max_lasting(24599);
        set("ap", 230);
        set("dp", 29);
        set("cp", 280);
        set("sp", 24);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_13; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
