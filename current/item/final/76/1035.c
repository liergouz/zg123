
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 9; }

// ��������Ʒ���
int get_fin_type() { return 1106; }

// ���������촦��
void create()
{
        set_name("���ƽ�");
        set_picid_1(7314);
        set_picid_2(7314);

        set_level(35);
        set_value(3500);
        set_max_lasting(3599);
        set("ap", 75);
        set("dp", 10);
        set("cp", 130);
        set("pp", 0);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_04; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
