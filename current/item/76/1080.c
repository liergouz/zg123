
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("�ɽ�");
        set_picid_1(7304);
        set_picid_2(7304);

        set_level(80);
        set_value(32000);
        set_max_lasting(21599);
        set("ap", 170);
        set("dp", 20);
        set("cp", 205);
        set("sp", 18);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_10; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
