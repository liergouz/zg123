
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit MISSILE;

// ��������������
int get_family() { return 4; }

// ��������Ʒ���
int get_fin_type() { return 1053; }

// ���������촦��
void create()
{
        set_name("ҫ������");
        set_picid_1(7120);
        set_picid_2(7120);

        set_level(100);
        set_value(10000);
        set_max_lasting(15599);
        set("ap", 211);
        set("dp", 0);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(THROWING);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_11; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
