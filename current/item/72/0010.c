
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 8; }

// ���������촦��
void create()
{
        set_name("����");
        set_picid_1(7201);
        set_picid_2(7201);

        set_level(10);
        set_value(900);
        set_max_lasting(6099);
        set("ap", 38);
        set("dp", 0);
        set("cp", 0);
        set("sp", 0);

        setup();

        set_weapon_type(BLADE);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_02; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
