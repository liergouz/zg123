
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 9; }

// ��������Ʒ���
int get_fin_type() { return 1107; }

// ���������촦��
void create()
{
        set_name("���׽�");
        set_picid_1(7322);
        set_picid_2(7322);

        set_level(45);
        set_value(4500);
        set_max_lasting(4599);
        set("ap", 85);
        set("dp", 12);
        set("cp", 165);
        set("pp", 0);

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
