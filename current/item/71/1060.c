
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit MISSILE;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("���");
        set_picid_1(7115);
        set_picid_2(7115);

        set_level(60);
        set_value(12000);
        set_max_lasting(22099);
        set("ap", 120);
        set("dp", -26);
        set("cp", 0);
        set("sp", 0);

        setup();

        set_weapon_type(THROWING);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_00; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
