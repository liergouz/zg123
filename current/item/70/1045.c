
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("�׻�ȭ��");
        set_picid_1(7010);
        set_picid_2(7010);

        set_level(45);
        set_value(14000);
        set_max_lasting(15599);
        set("ap", 115);
        set("dp", 11);
        set("cp", 0);
        set("sp", 0);

        setup();

        set_weapon_type(UNARMED);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_00; }

// ��������ȡ����
string get_desc()
{
        return "��ȭ����װ��";
}
