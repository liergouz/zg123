
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("�����");
        set_picid_1(7313);
        set_picid_2(7313);

        set_level(60);
        set_value(22000);
        set_max_lasting(18599);
        set("ap", 131);
        set("dp", 15);
        set("cp", 160);
        set("sp", 14);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_07; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
