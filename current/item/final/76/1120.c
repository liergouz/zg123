
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 9; }

// ��������Ʒ���
int get_fin_type() { return 1155; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(7323);
        set_picid_2(7323);

        set_level(120);
        set_value(12000);
        set_max_lasting(16099);
        set("ap", 250);
        set("dp", 50);
        set("cp", 385);
        set("pp", 0);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_13; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
