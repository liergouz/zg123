
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 9; }

// ��������Ʒ���
int get_fin_type() { return 1049; }

// ���������촦��
void create()
{
        set_name("���պ���");
        set_picid_1(7623);
        set_picid_2(7623);

        set_level(100);
        set_value(10000);
        set_max_lasting(15599);
        set("ap", 210);
        set("dp", 20);
        set("cp", 330);
        set("pp", 0);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_11; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
