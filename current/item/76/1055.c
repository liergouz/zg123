
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("��ڤ��");
        set_picid_1(7303);
        set_picid_2(7303);

        set_level(55);
        set_value(19000);
        set_max_lasting(17599);
        set("ap", 121);
        set("dp", 14);
        set("cp", 145);
        set("sp", 13);

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
