
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("�ٸֽ�");
        set_picid_1(7315);
        set_picid_2(7315);

        set_level(55);
        set_value(27000);
        set_max_lasting(6799);
        set("ap", 115);
        set("dp", 0);
        set("cp", 180);
        set("sp", 0);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_06; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
