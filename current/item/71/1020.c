
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit MISSILE;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("��Ҷ��");
        set_picid_1(7102);
        set_picid_2(7102);

        set_level(20);
        set_value(2000);
        set_max_lasting(14099);
        set("ap", 48);
        set("dp", -10);
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
