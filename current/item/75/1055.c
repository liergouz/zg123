
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("�ݹ�");
        set_picid_1(7513);
        set_picid_2(7513);

        set_level(55);
        set_value(19000);
        set_max_lasting(18099);
        set("ap", 141);
        set("dp", -24);
        set("cp", 0);
        set("sp", 0);

        setup();

        set_weapon_type(STICK);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_06; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
