
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("�ڽ�ǹ");
        set_picid_1(7413);
        set_picid_2(7413);

        set_level(55);
        set_value(19000);
        set_max_lasting(16599);
        set("ap", 136);
        set("dp", 0);
        set("cp", 0);
        set("sp", -24);

        setup();

        set_weapon_type(SPEAR);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_06; }

// ��������ȡ����
string get_desc()
{
        return "��ǹ����װ��";
}
