
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 6; }

// ���������촦��
void create()
{
        set_name("��꽣");
        set_picid_1(7315);
        set_picid_2(7315);

        set_level(50);
        set_value(24000);
        set_max_lasting(6599);
        set("ap", 100);
        set("dp", 0);
        set("cp", 165);
        set("sp", 0);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_06; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
