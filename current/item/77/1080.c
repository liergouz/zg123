
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 5; }

// ���������촦��
void create()
{
        set_name("��а��");
        set_picid_1(7620);
        set_picid_2(7620);

        set_level(80);
        set_value(42000);
        set_max_lasting(8099);
        set("ap", 160);
        set("dp", 0);
        set("cp", 250);
        set("sp", 0);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_10; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
