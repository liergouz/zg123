
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 2; }

// ��������Ʒ���
int get_fin_type() { return 1126; }

// ���������촦��
void create()
{
        set_name("ն����");
        set_picid_1(7220);
        set_picid_2(7220);

        set_level(75);
        set_value(7500);
        set_max_lasting(13099);
        set("ap", 180);
        set("dp", 0);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(BLADE);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_08; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
