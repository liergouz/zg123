
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 8; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(7502);
        set_picid_2(7502);

        set_level(10);
        set_value(900);
        set_max_lasting(9099);
        set("ap", 46);
        set("dp", -6);
        set("cp", 0);
        set("sp", 0);

        setup();

        set_weapon_type(STICK);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_02; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
