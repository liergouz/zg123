
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 2; }

// ��������Ʒ���
int get_fin_type() { return 1108; }

// ���������촦��
void create()
{
        set_name("���굶");
        set_picid_1(7219);
        set_picid_2(7219);

        set_level(45);
        set_value(4500);
        set_max_lasting(6099);
        set("ap", 120);
        set("dp", 0);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(BLADE);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_05; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
