
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("���߽�");
        set_picid_1(7320);
        set_picid_2(7320);

        set_level(30);
        set_value(7000);
        set_max_lasting(13599);
        set("ap", 72);
        set("dp", 9);
        set("cp", 70);
        set("sp", 8);

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
