
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 9; }

// ��������Ʒ���
int get_fin_type() { return 1043; }

// ���������촦��
void create()
{
        set_name("���ǽ�");
        set_picid_1(7314);
        set_picid_2(7314);

        set_level(90);
        set_value(9000);
        set_max_lasting(14599);
        set("ap", 190);
        set("dp", 15);
        set("cp", 300);
        set("pp", 0);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_10; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
