
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("ī��");
        set_picid_1(7303);
        set_picid_2(7303);

        set_level(50);
        set_value(17000);
        set_max_lasting(16599);
        set("ap", 110);
        set("dp", 13);
        set("cp", 130);
        set("sp", 12);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_06; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
