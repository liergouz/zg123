
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 3; }

// ��������Ʒ���
int get_fin_type() { return 1052; }

// ���������촦��
void create()
{
        set_name("ڤ������");
        set_picid_1(7520);
        set_picid_2(7520);

        set_level(100);
        set_value(10000);
        set_max_lasting(15599);
        set("ap", 258);
        set("dp", 0);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(STICK);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_11; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
