
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("���׽�");
        set_picid_1(7621);
        set_picid_2(7621);

        set_level(45);
        set_value(21000);
        set_max_lasting(6299);
        set("ap", 95);
        set("dp", 0);
        set("cp", 150);
        set("sp", 0);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_05; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
