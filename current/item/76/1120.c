
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("߱��");
        set_picid_1(7319);
        set_picid_2(7319);

        set_level(120);
        set_value(52000);
        set_max_lasting(25599);
        set("ap", 250);
        set("dp", 33);
        set("cp", 310);
        set("sp", 26);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_14; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
