
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 2; }

// ��������Ʒ���
int get_fin_type() { return 1010; }

// ���������촦��
void create()
{
        set_name("�󿳵�");
        set_picid_1(7204);
        set_picid_2(7204);

        set_level(30);
        set_value(3000);
        set_max_lasting(6099);
        set("ap", 89);
        set("dp", 0);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(BLADE);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_04; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
