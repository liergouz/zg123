
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 2; }

// ��������Ʒ���
int get_fin_type() { return 1138; }

// ���������촦��
void create()
{
        set_name("�Ʒ絶");
        set_picid_1(7205);
        set_picid_2(7205);

        set_level(95);
        set_value(9500);
        set_max_lasting(14099);
        set("ap", 220);
        set("dp", 0);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(BLADE);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_10; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
