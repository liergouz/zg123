
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit MISSILE;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("�ѻ���");
        set_picid_1(7121);
        set_picid_2(7121);

        set_level(110);
        set_value(27000);
        set_max_lasting(32099);
        set("ap", 210);
        set("dp", -46);
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
