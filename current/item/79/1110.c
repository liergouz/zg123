
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("����");
        set_picid_1(7619);
        set_picid_2(7619);

        set_level(110);
        set_value(60000);
        set_max_lasting(9599);
        set("ap", 225);
        set("dp", 0);
        set("cp", 345);
        set("sp", 0);

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
