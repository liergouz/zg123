
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 3; }

// ��������Ʒ���
int get_fin_type() { return 1030; }

// ���������촦��
void create()
{
        set_name("����ǹ");
        set_picid_1(7421);
        set_picid_2(7421);

        set_level(60);
        set_value(6000);
        set_max_lasting(13099);
        set("ap", 157);
        set("dp", 10);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(SPEAR);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_07; }

// ��������ȡ����
string get_desc()
{
        return "��ǹ����װ��";
}
