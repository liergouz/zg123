
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit MISSILE;

// ��������������
int get_family() { return 4; }

// ��������Ʒ���
int get_fin_type() { return 1012; }

// ���������촦��
void create()
{
        set_name("÷����");
        set_picid_1(7101);
        set_picid_2(7101);

        set_level(30);
        set_value(3000);
        set_max_lasting(6099);
        set("ap", 75);
        set("dp", -4);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(THROWING);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_04; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
