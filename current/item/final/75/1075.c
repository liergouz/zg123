
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 3; }

// ��������Ʒ���
int get_fin_type() { return 1128; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(7522);
        set_picid_2(7522);

        set_level(75);
        set_value(7500);
        set_max_lasting(13099);
        set("ap", 191);
        set("dp", 12);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(STICK);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_08; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
