
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 9; }

// ��������Ʒ���
int get_fin_type() { return 1131; }

// ���������촦��
void create()
{
        set_name("ˮ�½�");
        set_picid_1(7303);
        set_picid_2(7303);

        set_level(85);
        set_value(8500);
        set_max_lasting(13599);
        set("ap", 170);
        set("dp", 10);
        set("cp", 270);
        set("pp", 0);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_09; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
