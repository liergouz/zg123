
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("���պ���");
        set_picid_1(7314);
        set_picid_2(7314);

        set_level(100);
        set_value(42000);
        set_max_lasting(23599);
        set("ap", 210);
        set("dp", 26);
        set("cp", 250);
        set("sp", 22);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_12; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
