
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("ӭ��ն");
        set_picid_1(7301);
        set_picid_2(7301);

        set_level(40);
        set_value(12000);
        set_max_lasting(14599);
        set("ap", 92);
        set("dp", 11);
        set("cp", 100);
        set("sp", 10);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_05; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
