
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 9; }

// ��������Ʒ���
int get_fin_type() { return 1019; }

// ���������촦��
void create()
{
        set_name("���߽�");
        set_picid_1(7322);
        set_picid_2(7322);

        set_level(50);
        set_value(5000);
        set_max_lasting(8099);
        set("ap", 110);
        set("dp", 6);
        set("cp", 180);
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
