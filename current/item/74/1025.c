
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("�����");
        set_picid_1(7409);
        set_picid_2(7409);

        set_level(25);
        set_value(4500);
        set_max_lasting(8599);
        set("ap", 75);
        set("dp", 0);
        set("cp", 0);
        set("sp", -12);

        setup();

        set_weapon_type(SPEAR);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_03; }

// ��������ȡ����
string get_desc()
{
        return "��ǹ����װ��";
}
