
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(7513);
        set_picid_2(7513);

        set_level(50);
        set_value(17000);
        set_max_lasting(17099);
        set("ap", 130);
        set("dp", -22);
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
