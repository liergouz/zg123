
#include <equip.h>

inherit WEAPON;

// ��������������
int get_family() { return 4; }

// ��������Ʒ���
int get_fin_type() { return 1; }

// ���������촦��
void create()
{
        set_name("�ֹ�ͭ��");
        set_picid_1(7313);
        set_picid_2(7313);
        set_unit("��");

        set_level(30);
        set_value(7000);
        set_max_lasting(13599);
        set("ap", 76);
        set("!%", 12);
        set("spec.hp", 20);
        set("spec.hp*", 2);
        set("spec.mp*", 2);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return 13; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
