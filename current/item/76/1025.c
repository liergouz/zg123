
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("���ལ");
        set_picid_1(7318);
        set_picid_2(7318);

        set_level(25);
        set_value(4500);
        set_max_lasting(13099);
        set("ap", 62);
        set("dp", 8);
        set("cp", 55);
        set("sp", 7);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_03; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
