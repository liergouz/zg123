
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("�ƿ�");
        set_picid_1(7214);
        set_picid_2(7214);

        set_level(90);
        set_value(37000);
        set_max_lasting(21599);
        set("ap", 200);
        set("dp", 0);
        set("cp", 0);
        set("sp", 0);

        setup();

        set_weapon_type(BLADE);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_11; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
