
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("����");
        set_picid_1(7220);
        set_picid_2(7220);

        set_level(70);
        set_value(27000);
        set_max_lasting(18599);
        set("ap", 160);
        set("dp", 0);
        set("cp", 0);
        set("sp", 0);

        setup();

        set_weapon_type(BLADE);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_09; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
