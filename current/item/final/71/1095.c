
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit MISSILE;

// ��������������
int get_family() { return 4; }

// ��������Ʒ���
int get_fin_type() { return 1141; }

// ���������촦��
void create()
{
        set_name("�ϻ�ɳ");
        set_picid_1(7122);
        set_picid_2(7122);

        set_level(95);
        set_value(9500);
        set_max_lasting(14099);
        set("ap", 205);
        set("dp", 20);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(THROWING);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_10; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
