
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 3; }

// ��������Ʒ���
int get_fin_type() { return 1029; }

// ���������촦��
void create()
{
        set_name("��չ�");
        set_picid_1(7514);
        set_picid_2(7514);

        set_level(60);
        set_value(6000);
        set_max_lasting(13099);
        set("ap", 162);
        set("dp", -10);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(STICK);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_07; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
