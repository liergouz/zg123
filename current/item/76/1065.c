
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("��罣");
        set_picid_1(7315);
        set_picid_2(7315);

        set_level(65);
        set_value(24000);
        set_max_lasting(19599);
        set("ap", 141);
        set("dp", 16);
        set("cp", 175);
        set("sp", 15);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_08; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
