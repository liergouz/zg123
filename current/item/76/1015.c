
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("���罣");
        set_picid_1(7322);
        set_picid_2(7322);

        set_level(15);
        set_value(1200);
        set_max_lasting(10099);
        set("ap", 42);
        set("dp", 6);
        set("cp", 25);
        set("sp", 5);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_02; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
