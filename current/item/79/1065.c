
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("���罣");
        set_picid_1(7617);
        set_picid_2(7617);

        set_level(65);
        set_value(33000);
        set_max_lasting(7299);
        set("ap", 135);
        set("dp", 0);
        set("cp", 210);
        set("sp", 0);

        setup();

        set_weapon_type(SWORD);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_08; }

// ��������ȡ����
string get_desc()
{
        return "��������װ��";
}
