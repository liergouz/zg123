
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit MISSILE;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("��Ǯ��");
        set_picid_1(7114);
        set_picid_2(7114);

        set_level(55);
        set_value(10500);
        set_max_lasting(21099);
        set("ap", 111);
        set("dp", -24);
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
