
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 9; }

// ��������Ʒ���
int get_fin_type() { return 1113; }

// ���������촦��
void create()
{
        set_name("�㳦");
        set_picid_1(7315);
        set_picid_2(7315);

        set_level(55);
        set_value(5500);
        set_max_lasting(6599);
        set("ap", 115);
        set("dp", 15);
        set("cp", 195);
        set("pp", 0);

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
